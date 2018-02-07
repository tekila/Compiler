/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString )
{
	switch (token)
	{
		case IF:
		case ELSE:
		case INT:
		case RETURN:
		case VOID:
		case WHILE:
		case SYS_INPUT:
		case SYS_OUTPUT:
		case SYS_KILL:
		case SYS_RUN:
		case SYS_SAVE:
		fprintf(listing,
			"reserved word: %s\n",tokenString);
		break;
		case ASSIGN: fprintf(listing,"=\n"); break;
		case LTE:fprintf(listing,"<=\n"); break;
		case LT: fprintf(listing,"<\n"); break;
		case GTE:fprintf(listing,">=\n"); break;
		case GT: fprintf(listing,">\n"); break;
		case EQ: fprintf(listing,"==\n"); break;
		case NEQ:fprintf(listing,"!=\n"); break;
		case LPAREN: fprintf(listing,"(\n"); break;
		case RPAREN: fprintf(listing,")\n"); break;
		case LSQR: fprintf(listing,"[\n"); break;
		case RSQR: fprintf(listing,"]\n"); break;
		case LCURLY: fprintf(listing,"{\n"); break;
		case RCURLY: fprintf(listing,"}\n"); break;
		case SEMI: fprintf(listing,";\n"); break;
		case PLUS: fprintf(listing,"+\n"); break;
		case MINUS: fprintf(listing,"-\n"); break;
		case TIMES: fprintf(listing,"*\n"); break;
		case OVER: fprintf(listing,"/\n"); break;
		case ENDFILE: fprintf(listing,"EOF\n"); break;
		case NUM:
		fprintf(listing,
			"NUM, val= %s\n",tokenString);
		break;
		case ID:
		fprintf(listing,
			"ID, name= %s\n",tokenString);
		break;
		case ERROR:
		fprintf(listing,
			"ERROR: %s\n",tokenString);
		break;
		default: /* should never happen */
		fprintf(listing,"AquiUnknown token: %s\n",tokenString);
  }
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    //t->kind.type = Void;
  }
  return t;
}

TreeNode * newSysNode(SystemKind kind)
{ 
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t==NULL)
		fprintf(listing,"Out of memory error at line %d\n",lineno);
	else {
		for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = SysK;
		t->kind.sys = kind;
		t->lineno = lineno;
		//t->kind.type = Void;
	}
	return t;
}

TreeNode * newDeclNode(DeclKind kind)
{ 
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t==NULL)
	{
		fprintf(listing,"Out of memory error at line %d\n",lineno);
		exit(1);
	}
	// else {
		for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = DeclK;
		t->kind.decl = kind;
		t->lineno = lineno;
		//t->kind.type = Void;
	// }
	return t;
}

TreeNode * newTypeNode(TypeKind kind)
{ 
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t==NULL)
		fprintf(listing,"Out of memory error at line %d\n",lineno);
	else {
		for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = TypeK;
		t->kind.type = kind;
		t->lineno = lineno;
		//t->kind.type = Void;
	}
	return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ 
	int n;
	char * t;
	if (s==NULL) return NULL;
	n = strlen(s)+1;
	t = malloc(n);
	if (t==NULL)
		fprintf(listing,"Out of memory error at line %d\n",lineno);
	else strcpy(t,s);
	return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ 
	int i;
	INDENT;
	
	while (tree != NULL) {
		printSpaces();
		if (tree->nodekind==StmtK)
		{ 
			switch (tree->kind.stmt) {
				case IfK:
					fprintf(listing,"If:\n");
				break;
				case WhileK:
					fprintf(listing,"While:\n");
					break;
				case AssignK:
					fprintf(listing,"Assign:\n");
					break;
				case ReturnK:
					fprintf(listing,"Return:\n");
					break;
				default:
					fprintf(listing,"1Unknown ExpNode kind\n");
					break;
			}
		}
		else if (tree->nodekind==ExpK)
		{
			switch (tree->kind.exp) {
				case OpK:
					fprintf(listing,"Op: ");
					printToken(tree->attr.op,"\0");
					break;
				case ConstK:
					fprintf(listing,"Const: %d\n",tree->attr.val);
					break;
				case IdK:
					fprintf(listing,"Id: %s at Scope:: %s\n",tree->attr.name, tree->scope);
					break;
				case FunIdK:
					fprintf(listing,"FunId: %s at Scope:: %s\n",tree->attr.name, tree->scope);
					break;
			
				case IdArrayK:
					fprintf(listing,"IdArrayK: %s at Scope:: %s\n",tree->attr.name, tree->scope);
					break;
				default:
					fprintf(listing,"2Unknown ExpNode kind\n");
					break;
			}
		}
		else if(tree->nodekind == SysK)
		{ 
			switch (tree->kind.sys) {
				case InputK:
					fprintf(listing,"Syscall Input: %s - \n", tree->attr.name);
					break;
				case OutputK:
					fprintf(listing,"Syscall Output: %s - \n", tree->attr.name);
					break;
				case KillK:
					fprintf(listing,"Syscall Kil: %s - \n", tree->attr.name);
					break;;
				case RunK:
					fprintf(listing,"Syscall Run : %s - \n", tree->attr.name);
					break;
				case SaveK:
					fprintf(listing,"Syscall Save: %s - \n", tree->attr.name);
					break;
				default:
					fprintf(listing,"3Unknown ExpNode kind\n");
					break;
			}
		
		}
		else if(tree->nodekind == DeclK)
		{ 
			switch (tree->kind.decl) {
				case VarK:
					fprintf(listing,"VarK: %s at Scope:: %s :: Data type: %s\n", tree->attr.name, tree->scope, (tree->Type == Integer)? "Integer":"Not Integer");
					break;
				case ArrayK:
					fprintf(listing,"ArrayK: %s at Scope:: %s \n", tree->attr.name, tree->scope );
					break;
				case FunK:
					fprintf(listing,"FunK: %s at Scope:: %s :: Return Type: %s\n", tree->attr.name, tree->scope, (tree->Type == Integer)? "Integer":"Not Integer");
					break;;
				case VarParK:
					fprintf(listing,"VarParK: %s at Scope:: %s\n", tree->attr.name, tree->scope);
					break;
				case ArrayParK:
					fprintf(listing,"ArrayParK: %s at Scope:: %s\n", tree->attr.name, tree->scope);
					break;
				case SizeK:
					fprintf(listing,"SizeK: %d at Scope:: %s\n", tree->attr.val, tree->scope);
					break;
				default:
					fprintf(listing,"4Unknown ExpNode kind\n");
					break;
			}
		
		}
		else if(tree->nodekind == TypeK)
		{ 
			switch (tree->kind.sys) {
				case Void:
					fprintf(listing,"Void Type\n");
					break;
				case Integer:
					fprintf(listing,"Integer Type\n");
					break;
				default:
					fprintf(listing,"5Unknown ExpNode kind\n");
					break;
			}
		
		}
		else fprintf(listing,"Unknown node kind\n");
		for (i=0;i<MAXCHILDREN;i++)
			printTree(tree->child[i]);
		tree = tree->sibling;
	}
	UNINDENT;
}
