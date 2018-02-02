/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */



#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h" 
#include <string.h>

#define YYSTYPE TreeNode *

static char * savedName; /* for use in assignments */
static char * savedFunction; //For saving function name.
static char * savedScope; //for saving scope info. Uses [] so the array is allocated on the stack by GCC 
static int savedValue; //for saving array size or constant value
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */



%}
%expect 1
%start programa
%token IF ELSE INT RETURN VOID WHILE SYS_INPUT SYS_OUTPUT SYS_KILL SYS_RUN SYS_SAVE
%token ID NUM 
%token PLUS MINUS TIMES OVER LT LTE GT GTE ASSIGN EQ NEQ SEMI COMMA LPAREN RPAREN LSQR RSQR LCURLY RCURLY
%token ERROR 

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%% /* Grammar for TINY */


programa    	: decl_lista
				{ 
					if(SintaxDebug)printf("programa -> decl_lista\n");
					savedTree = $1;
				} 
			;
decl_lista  	: decl_lista decl
                {
					if(SintaxDebug)printf("decl_lista -> decl_lista decl\n");
					TreeNode * t = $1;
					if (t != NULL)
					{ 
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = $2;
						$$ = $1; 
					} else $$ = $2;
                 }
				| decl  
				{ 
					if(SintaxDebug)printf("decl_lista -> decl\n");
					$$ = $1; 
				}
			;
decl 			: var_decl
				{
					if(SintaxDebug)printf("decl -> var_decl\n");
					$$ = $1; 
				}
				| fun_decl
				{
					if(SintaxDebug)printf("decl -> var_decl\n");
					$$ = $1; 
				}
			;
				/*toda vez que le um ID precisa guardar o nome dele*/
var_decl		: tipo ID { savedName = copyString(tokenString); savedLineNo = lineno;} SEMI
				{
					
					if(SintaxDebug)printf("var_decl -> tipo ID SEMI\n");
					TreeNode * t;
					t = newDeclNode(VarK);
					t->attr.name = savedName;
					t->lineno = savedLineNo;
					t->kind.decl = VarK;

					
					t->sibling = $$->sibling;
					t->child[0] = $$->child[0];
					t->child[1] = $$->child[1];
					t->child[2] = $$->child[2];
					$$ = $1;
					$$->sibling = NULL;
					$$->child[0] = t;
					$$->child[1] = NULL;
					$$->child[2] = NULL;
				}
				| tipo ID { savedName = copyString(tokenString); savedLineNo = lineno; } LSQR NUM {savedValue = atoi(tokenString);} RSQR SEMI
				{
					if(SintaxDebug)printf("var_decl -> tipo ID LSQR NUM RSQR SEMI\n");
					// if(SintaxDebug) printf("\n*******************\nnome:%s linha:%d valor:%d\n*******************\n", savedName, savedLineNo, savedValue);
					TreeNode * t;
					TreeNode * r;
					t = newDeclNode(ArrayK);  
					t->attr.name = savedName; 
					t->lineno = savedLineNo;
					t->kind.decl = ArrayK;
					
					r = newDeclNode(SizeK);
					r->attr.val = savedValue;
					r->lineno = savedLineNo;
					r->kind.decl = SizeK;
					
					t->sibling = $$->sibling;
					t->child[0] = r;
					t->child[1] = NULL;
					t->child[2] = NULL;
					r->child[0] = $$->child[0];
					r->child[1] = $$->child[1];
					r->child[2] = $$->child[2];		
					
					$$ = $1;
					$$->sibling = NULL;
					$$->child[0] = t;
					$$->child[1] = NULL;
					$$->child[2] = NULL;
				}
			;
tipo 			:INT
				{
					if(SintaxDebug)printf("tipo -> INT\n");
					$$ = newTypeNode(Integer);
					$$->kind.type = Integer;
				}
				|	VOID
				{if(SintaxDebug)printf("tipo_especificador -> void\n");
					$$ = newTypeNode(Void);
					$$->kind.type = Void;
				}
			;
fun_decl	: tipo ID
				{ /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
					savedLineNo = lineno;
					savedFunction = savedName;
				} LPAREN params RPAREN comp_decl
				{
					if(SintaxDebug)printf("fun_decl -> tipo_especificador ID LPARE params RPARE comp_decl\n");
					TreeNode * t;
					t = newDeclNode(FunK);     
					t->attr.name = savedFunction; 
					t->lineno = savedLineNo; 
					t->kind.decl = FunK;

					t->sibling = $$->sibling;
					t->child[0] = $5;
					t->child[1] = $7;
					t->child[2] = NULL;					
					$$ = $1;
					$$->sibling = NULL;
					$$->child[0] = t;
					$$->child[1] = NULL;
					$$->child[2] = NULL;
					

					
					
				}
			;
params 		: params_lista
				{
					if(SintaxDebug) printf("params -> params_lista\n");
					$$ = $1;
				}
			| VOID
				{
					if(SintaxDebug)printf("params -> VOID\n");
					$$ = NULL;
					
				}
			;
params_lista: params_lista COMMA param
				{	
					if(SintaxDebug)printf("params_lista -> params_lista COMMA param\n");
					TreeNode * t = $1;
					if (t!=NULL)
					{
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = $3;
						$$ = $1;
					}else
					{
						$$ = $3;
					}
					
				}
			| param
				{if(SintaxDebug)printf("params_lista -> param\n");
					$$ = $1;
					
				}
			;
param 		: tipo id 
				{ /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					if(SintaxDebug) printf("param -> tipo_especificador ID\n");
					$$ = $1;
					$$->child[0] = newDeclNode(VarParK);
					$$->child[0]->kind.decl = VarParK;
					$$->child[0]->attr.name = $2->attr.name;
					$$->child[0]->lineno = $2->lineno;
					//$$->child[0]->kind.type = $$->kind.type;
					
					
				}
			| tipo id 
				{ /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
				}
				LSQR RSQR
				{
					if(SintaxDebug)printf("param -> tipo_especificador ID LSQRBRA RSQRBRA\n");
					TreeNode * t = newDeclNode(ArrayParK);
					t->attr.name = savedName;
					t->lineno = savedLineNo;
					$$=$1;
					$$->child[0] = $2;
					$$->child[0]->kind.type = $$->kind.type;
				}
			;
comp_decl	: LCURLY decl_local stmt_lista RCURLY
				{
					if(SintaxDebug)printf("comp_decl -> LCURBRA decl_local stmt_lista RCURBRA\n");
					TreeNode * t = $2;
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = $3;
						$$ = $2;
					}else{
						$$ = $3;
					}	
				}
			;
decl_local	: decl_local var_decl
				{
					if(SintaxDebug)printf("decl_local -> decl_local var_decl\n");
					TreeNode * t = $1;
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = $2;
						$$ = $1;
					}else{
						$$ = $2;
					}				
					
				}
			| 	{	
					if(SintaxDebug) printf("decl_local-> vazio .\n");
					$$ = NULL;
				}
			;
stmt_lista	: stmt_lista stmt
				{
					if(SintaxDebug)printf("stmt_lista -> stmt_lista stmt\n");
					TreeNode * t = $1;
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = $2;
						$$ = $1;
					}else{
						$$ = $2;
					}	
				}
			|	{	
					if(SintaxDebug) printf("local_declaracoes-> vazio .\n");
					$$ = NULL;
				}
			;
stmt		: exp_decl
				{
					if(SintaxDebug)printf("stmt -> exp_decl\n");
					$$ = $1;
				}
			| comp_decl
				{
					if(SintaxDebug)printf("stmt -> comp_decl\n");
					$$ = $1;
				}
			| selecao_decl
				{
					$$ = $1;
					if(SintaxDebug)printf("stmt -> selecao_decl\n");
				}
			| iteracao_decl
				{
					if(SintaxDebug)printf("stmt -> iteracao_decl\n");
					$$ = $1;
				}
			| retorno_decl
				{
					if(SintaxDebug)printf("stmt -> retorno_decl\n");
					$$ = $1;
				}
			;
exp_decl	: exp SEMI
				{
					if(SintaxDebug)printf("exp_decl -> exp SEMICOLON\n");
					$$ = $1;
				}
			| SEMI
				{
					if(SintaxDebug)printf("exp_decl -> SEMICOLON\n");
					$$ = $1;
				}
			;
selecao_decl: IF LPAREN exp RPAREN stmt
				{	
					if(SintaxDebug)printf("selecao_decl -> IF LPARE exp RPARE stmt\n");
					$$ = newStmtNode(IfK);
					$$->child[0] = $3;
					$$->child[1] = $5;
					
				}
			| IF LPAREN exp RPAREN stmt ELSE stmt
				{
					$$ = newStmtNode(IfK);
					$$->child[0] = $3;
					$$->child[1] = $5;
					$$->child[2] = $7;
					if(SintaxDebug) printf("selecao_decl -> IF LPARE exp RPARE stmt ELSE stmt\n");
				}
			;
iteracao_decl: WHILE LPAREN exp RPAREN stmt
				{if(SintaxDebug)printf("iteracao_decl -> WHILE LPARE exp RPARE stmt\n");
					$$ = newStmtNode(WhileK);
					$$->child[0] = $3;
					$$->child[1] = $5;
					
				}
			;
retorno_decl: RETURN SEMI
				{if(SintaxDebug)printf("retorno_decl -> RETURN SEMICOLON\n");
					$$ = newStmtNode(ReturnK);
					$$->child[0] = NULL;
				}
			| RETURN exp SEMI
				{if(SintaxDebug)printf("retorno_decl -> RETURN exp SEMICOLON\n");
					$$ = newStmtNode(ReturnK);
					$$->child[0] = $2;
				}
			;
exp			: var ASSIGN exp
				{if(SintaxDebug)printf("exp -> var ASSIGN exp\n");
					$$ = newStmtNode(AssignK);
					$$->child[0] = $1;
					$$->child[1] = $3;
					$$->kind.type = $1->kind.type;
				}
			| exp_simp
				{
					if(SintaxDebug)printf("exp -> exp_simp\n");	
					$$ = $1;
				}
			;
var			: ID 
				{ /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					if(SintaxDebug) printf("var -> ID\n");
					$$ = newExpNode(IdK);
					$$->kind.exp = IdK;
					$$->attr.name = copyString(tokenString);	
					
				}
			| ID 
				{ /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
					savedLineNo = lineno;
				} LSQR exp RSQR
				{
					if(SintaxDebug)printf("var -> ID LSQRBRA exp RSQRBRA\n");
					$$ = newExpNode(IdArrayK);
					$$->kind.exp = IdArrayK;
					$$->attr.name = savedName;
					$$->lineno = savedLineNo;
					$$->child[0] = $4;
				}
			;
exp_simp	: exp_soma relacional exp_soma
				{
					if(SintaxDebug)printf("exp_simp -> exp_soma relacional exp_soma\n");
					$$ = newExpNode(OpK);
					$$->attr.op = $2->attr.op;	
					$$->child[0] = $1;
					$$->child[1] = $3;
					
				}
			| exp_soma
				{
					if(SintaxDebug)printf("exp_simp -> exp_soma\n");
					$$ = $1;
					
				}
			;
relacional 	: LTE
				{
					if(SintaxDebug)printf("relacional -> LESSEQ\n");
					$$ = newExpNode(OpK);
					$$->attr.op = LTE;
				}
			| LT
				{
					if(SintaxDebug)printf("relacional -> LESS\n");
					$$ = newExpNode(OpK);
					$$->attr.op = LT;
				}
			| GT
				{
					if(SintaxDebug)printf("relacional -> GREAT\n");
					$$ = newExpNode(OpK);
					$$->attr.op = GT;
				}
			| GTE
				{
					if(SintaxDebug)printf("relacional -> GREATEQ\n");
					$$ = newExpNode(OpK);
					$$->attr.op = GTE;
				}
			| EQ
				{
					if(SintaxDebug)printf("relacional -> EQ\n");
					$$ = newExpNode(OpK);
					$$->attr.op = EQ;
				}
			| NEQ
				{
					if(SintaxDebug)printf("relacional -> NEQ\n");
					$$ = newExpNode(OpK);
					$$->attr.op = NEQ;
				}
			;
exp_soma	: exp_soma soma termo
				{
					if(SintaxDebug)printf("exp_soma -> exp_soma soma termo\n");
					$$ = $2;
					if($1->kind.type == Integer && $3->kind.type == Integer)
					{
						$2->kind.type = Integer;
					}
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
			| termo
				{
					if(SintaxDebug) printf("exp_soma -> termo\n");
					$$ = $1;
				}
			;
soma		: PLUS
				{
					if(SintaxDebug) printf("soma -> PLUS\n");
					$$ = newExpNode(OpK);
					$$->attr.op = PLUS;	
					
				}
			| MINUS
				{
					$$ = newExpNode(OpK);
					if(SintaxDebug)printf("soma -> PLUS\n");
					$$->attr.op = MINUS;
				}
			;
termo		: termo mult fator
				{
					if(SintaxDebug)printf("termo -> termo mult fator\n");
					$$ = $2;
					if($1->kind.type == Integer && $3->kind.type == Integer)
					{
						$2->kind.type = Integer;
					}
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
			| fator
				{
					if(SintaxDebug) printf("termo -> fator\n");
					$$ = $1;
					
				}
			;
mult		: TIMES
				{
					$$ = newExpNode(OpK);
					if(SintaxDebug)printf("mult -> MULT\n");
					$$->attr.op = TIMES;
					
				}
			| OVER
				{
					$$ = newExpNode(OpK);
					if(SintaxDebug)printf("mult -> DIV\n");
					$$->attr.op = OVER;
					
				}
			;
fator		: LPAREN exp RPAREN
				{
					if(SintaxDebug)printf("fator -> LPARE exp RPARE\n");
					$$ = $2;
				}
			| var
				{
					if(SintaxDebug)printf("fator -> var\n");
					$$ = $1;
				}
			| ativacao
				{
					if(SintaxDebug)printf("fator -> ativacao\n");
					$$ = $1;
				}
			| NUM
				{
					if(SintaxDebug)printf("fator -> NUM\n");
					$$ = newExpNode(ConstK);
					$$->kind.exp = ConstK;
					$$->attr.val = atoi(tokenString);
				}
			;
ativacao	: id LPAREN args RPAREN
				{	
					if(SintaxDebug) printf("ativacao -> ID LPARE args RPARE\n");
					$$ = newExpNode(IdK);
					$$->kind.exp = IdK;
					$$->attr.name = $1->attr.name;
					$$->lineno = $1->lineno;
					$$->child[0] = $3;

				}
			| chamada_sistema 
				{
					if(SintaxDebug) printf("ativacao -> chamada_sistema\n");
					$$ = $1;
				}
			;
chamada_sistema: 
			SYS_INPUT
				{
					if(SintaxDebug) printf("chamada_sistema -> SYS_INPUT\n");
					$$ = newSysNode(InputK);
					$$->attr.name = "input";
					$$->lineno = lineno;
				}
			|SYS_OUTPUT
				{
					if(SintaxDebug) printf("chamada_sistema -> SYS_OUTPUT\n");
					$$ = newSysNode(OutputK);
					$$->attr.name = "output";
					$$->lineno = lineno;
				}
			|SYS_KILL
				{
					if(SintaxDebug) printf("chamada_sistema -> SYS_KILL\n");
					$$ = newSysNode(KillK);
					$$->attr.name = "kill";
					$$->lineno = lineno;
				}
			|SYS_RUN
				{
					if(SintaxDebug) printf("chamada_sistema -> SYS_RUN\n");
					$$ = newSysNode(RunK);
					$$->attr.name = "run";
					$$->lineno = lineno;
				}
			|SYS_SAVE
				{
					if(SintaxDebug) printf("chamada_sistema -> SYS_SAVE\n");
					$$ = newSysNode(SaveK);
					$$->attr.name = "save";
					$$->lineno = lineno;
				}
			;
id			: ID
			{
				$$ = newExpNode(IdK);
				$$->attr.name = copyString(tokenString);
				savedName = copyString(tokenString);
				$$->lineno = lineno;
			}
			;
args		: list_args
				{
					if(SintaxDebug)printf("args -> list_args\n");
					$$ = $1;
				}
			| 	{
					if(SintaxDebug) printf("args -> vazio");
					$$ = NULL;
				}
			
			;
			
list_args	: list_args COMMA exp
				{
					if(SintaxDebug)printf("list_args -> list_args COMMA exp\n");
					TreeNode * t = $3;
					t->sibling = $$->sibling;
					$$ = $1;
					$$->sibling = t;
					
				}
			| exp
				{
					if(SintaxDebug)printf("list_args -> exp\n");
					$$ = $1;
				}
			;
	
%%

int yyerror(char * message)
{ 
	fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	Error = TRUE;
	return 0;
}


 
TreeNode * parse(void)
{ 
	yyparse();
	return savedTree;
}


/* Scope changes are function bound only. 
 * We`re not dealing here with scope changes on control/loop statements.
 */
void scoper(TreeNode* root)
{ 
	char globalScope[] = "global";
	savedScope = globalScope;
	if(SintaxDebug) printf("inside scoper\n");
	while(root!=NULL) //condition for not bugging.
	{	
		if(root->nodekind == DeclK) //root is a declaration
		{
			if(root->kind.decl == FunK) //root is a declaration of a function, savedScope must change.
			{
				printf("root->attr.name: %s\n", root->attr.name);
				
				char dot[100] = "."; //must be array of char because char* creates a read-only, which is not useful
				char* aux;
				aux = strcat(dot, root->attr.name);
				savedScope = strcat(savedScope, aux);
				printf("savedScope: %s\n", savedScope);
				if(SintaxDebug) printf("Scope updated\n");
			}
		}
		for(int i = 0; i<MAXCHILDREN; i++)
			scoper(root->child[i]);
		root = root->sibling;
	}
}

