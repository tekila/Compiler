/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

typedef enum {LD, ST, COND_IF, COND_IF_F, LOOP_WHILE, LOOP_WHILE_F, INTCODE_ADD, INTCODE_SUB, INTCODE_MUL, INTCODE_DIV, INTCODE_LT, INTCODE_LEQ, INTCODE_GT, INTCODE_GEQ, INTCODE_EQ, INTCODE_NEQ, INTCODE_ASSIGN, INTCODE_RET} OpKind;

typedef enum {Vazio, ConstInt, String} AddrKind; //diz qual o tipo de dado que esta no no da lista. Serve para alocar a quantidade correta de bits para o dado.

typedef struct 
{
	AddrKind kind;
	union 
	{
		int val;
		char *nome;
	}contents;
}Address;


typedef struct quad_addr
{
	OpKind op;
	Address val1, val2, res;
}Quad_Cell;

typedef struct quad_addr_lista
{
	Quad_Cell quad;
	struct quad_addr_lista* next,* prev;
}Quad_List;

Quad_List * AlocaQuad(OpKind op, Address val1, Address val2, Address res)
{
	Quad_List* aux = (Quad_List*) malloc(sizeof(Quad_List));
	Quad_Cell q;
	q.op = op;
	q.val1 = val1;
	q.val2 = val2;
	q.res = res;
	aux->quad = q;
	aux->next = NULL;
	aux->prev = NULL;
	return aux;
}

Quad_List * codigo_inter;

void insereBloco(OpKind op, Address val1, Address val2, Address res)
{
	
	if(codigo_inter == NULL)
		{
			codigo_inter = AlocaQuad(op, val1, val2, res);
		}
		else{
			Quad_List* aux, *aux2;
			aux = codigo_inter;
			while(aux->next!=NULL) aux = aux->next;
			aux2 = AlocaQuad(op, val1, val2, res);
			aux->next = aux2;
		}
}


int tempVariableCounter = 0;
char str[50];
char str_array[50];

FILE *fp;

int ehFolhaInterm(TreeNode* root)
{
	int folhaFlag = 0;
	for(int i = 0; i<MAXCHILDREN;i++)
	{
		if(root->child[i]==NULL) folhaFlag = 1;
		else return 0;
		//printf("FOR: folhaFlag(filho)%d\n", folhaFlag);
	}
	return folhaFlag;
}
int paiDeFolhas(TreeNode* root) //precisa atualizar pra IF e pra While
{
	int folhaFlag = 0;
	if(root->kind.exp == OpK){
		for	(int i = 0; i<2;i++)
		{
			if(ehFolhaInterm(root->child[i])) folhaFlag = 1;
			else return 0;
			//printf("FOR: folhaFlag(pai)%d\n", folhaFlag);
		}
	}
	//printf("folhaFlag(pai)%d\n", folhaFlag);
	return folhaFlag;
}

char* returnToken(OpKind op)
{
	switch(op){
		case INTCODE_ADD: 		{return "add"		;break;}
		case INTCODE_SUB: 		{return "sub"		;break;}
		case INTCODE_MUL: 		{return "mul"		;break;}
		case INTCODE_DIV: 		{return "div"		;break;}
		case INTCODE_EQ:	 	{return "eq"		;break;}
		case INTCODE_NEQ:	 	{return "neq"	 	;break;}
		case INTCODE_GEQ:		{return "geq" 	;break;}
		case INTCODE_GT: 		{return "gt"		;break;}
		case INTCODE_LT: 		{return "lt"	 	;break;}
		case INTCODE_LEQ: 		{return "leq" 	;break;}
		case INTCODE_ASSIGN: 	{return "ld"		;break;}
	}
}


int labelCounter = 0;

int tempVarCounter = 0;

char toFile[100];

char tempVar[50];

char labels[10]; 

void CodeGen(TreeNode* root);

char jump[] = "goto";

int FUNCTION_SEARCH = 0;


Address processExp(TreeNode* root);

//Args eh um ponteiro de address que vai indicar o comeco do array de argumentos
//retorna um int indicando quantos argumentos tem
void genArguments(TreeNode* root) //funcao retorna um array de 
{
	Address arg;
	TreeNode* aux;
	aux = root;
	printf("entrou aqui. Gen Arguments\n");
	while(aux != NULL)
	{
		if(aux->codeGen!=1)
		{
			arg = processExp(aux);
			if(arg.kind == String)fprintf(fp, "(%s,%s,_,_)\n", "arg",arg.contents.nome );
			if(arg.kind == ConstInt) fprintf(fp, "(%s,%d,_,_)\n", "arg",arg.contents.val );
			aux->codeGen = 1;
		}
		aux = aux->sibling;
	}
}


char* FUNCTION_RETURN;

int findFuncRetVal(char* nome)
{
	char stream[50], *ret;
	fseek(fp, 0, SEEK_SET);
	while(feof(fp) == 0)
	{
		
		ret = fgets(stream, 50, fp);
		printf("procurando funcao %s. Analizando: %s \n", nome, ret);
		ret = strstr(stream, nome);
		if(ret != NULL )
		{
			printf("achou funcao %s no arquivo\n", ret);
			while(1)
			{
				//printf("%s esta dentro do while\n", ret);
				ret = fgets(stream, 50, fp);
				printf("Esta dentro do while: %s", ret);
				if(ret == NULL)
				{
					printf("NULL\n");
					//fseek(fp, 0, SEEK_END);
					break;
				}
				else
				{
					ret = strstr(stream, "ret");
					if(ret!=NULL)
					{
						//achou o argumento de retorno da funcao Nome
						FUNCTION_RETURN = strtok(stream, "(ret,");
						if(FUNCTION_RETURN!=NULL) 
						{
							FUNCTION_SEARCH = 1;
							printf("Temp de retorno : %s\n", FUNCTION_RETURN);
							fseek(fp, 0, SEEK_END);
							//fflush(fp);
							return 1;
						}
					}
				}
			}
		}
	}
	FUNCTION_SEARCH = 0;
	fseek(fp, 0, SEEK_END);
	return 0;
}

Address processExp(TreeNode* root)
{
	if(root!=NULL)
	{
		switch(root->nodekind)
		{
			
			case ExpK:
			{
				///operacoes matematicas e logicas em pos-ordem
				///primeiro trata os dois filhos, depois trata a raiz
				
				switch(root->kind.exp)
				{
					case OpK:
					{
						Address *temp;
						Address op1, op2;
						char charOp1[50], charOp2[50];
						//if abaixo trata arrays. Nao muda se nao buga.
						if(root->child[0]->kind.exp == IdArrayK && root->child[1]->kind.exp == IdArrayK) 
						{
							//temos 2 arrays sendo operados por OPk
							op1 = processExp(root->child[0]);
							if(op1.kind == String)sprintf(charOp1, "%s", op1.contents.nome);
							if(op1.kind == ConstInt)sprintf(charOp1, "%d", op1.contents.val);
							//if(op1.kind!=Vazio)printf("nome: %s\n", charOp1);
							op1.contents.nome = charOp1;
							//if(op1.kind == Vazio) printf("NADA\n");
							op2 = processExp(root->child[1]);
							if(op2.kind == String)sprintf(charOp2, "%s", op2.contents.nome);
							if(op2.kind == ConstInt)sprintf(charOp2, "%d", op2.contents.val);
							//if(op2.kind!=Vazio)printf("nome: %s\n", charOp2);
							op2.contents.nome = charOp2;
							//if(op2.kind == Vazio) printf("NADA\n");
							
						}
						else 
						{
							op1 = processExp(root->child[0]);///filho esquerdo tratado
							switch(op1.kind)
							{
								case ConstInt:
								{
									//printf("OP1 EH INT\n");
									break;
								}
								case String:
								{
									//printf("OP1 EH STRING\n");
									if(op1.contents.nome == NULL)
									{
										///indica que os filho da direita eh um operador.
										///como resgatar o temporario antigo.
										op1.contents.nome = temp->contents.nome;
									}
									break;
								}
								case Vazio:
								{
									//printf("OP1 EH VAZIO\n");
								}
							}
							op2 = processExp(root->child[1]);///filho direito tratado
							//if(root->child[1]->id_type ==  ArrayPosK) printf("RETORNO DO processExp(): %s\n", op2.contents.nome);
							switch(op2.kind)
							{
								case ConstInt:
								{
									//printf("OP2 EH INT\n");
									break;
								}
								case String:
								{
									//printf("OP2 EH STRING\n");
									if(op2.contents.nome == NULL)
									{
										///indica que os filho da direita eh um operador.
										///como resgatar o temporario antigo.
										op2.contents.nome = temp->contents.nome;
									}
									break;
								}
								case Vazio:
								{
									//printf("OP2 EH VAZIO\n");
									break;
								}
							}
						}
						if(root->child[0]->kind.exp == IdArrayK && root->child[1]->kind.exp == IdArrayK) 
						{
							if(op1.kind!=Vazio && op2.kind!=Vazio)
							{
								//printf("nome: %s\n", op1.contents.nome);
								//printf("nome: %s\n", op2.contents.nome);
							}
						}
						//if(op2.kind == ConstInt)printf("num: %d\n", op2.contents.val);
						if(op1.kind == Vazio) break;
						if(op2.kind == Vazio) break;
						OpKind op;///tratamento de raiz
						switch (root->attr.op) ///descobre o operando
						{
							case PLUS: 		{op = INTCODE_ADD;		break;}
							case MINUS: 	{op = INTCODE_SUB;		break;}
							case TIMES:		{op = INTCODE_MUL;		break;}
							case OVER: 		{op = INTCODE_DIV;		break;}
							case EQ:	 	{op = INTCODE_EQ;		break;}
							case NEQ:	 	{op = INTCODE_NEQ;		break;}
							case GTE:		{op = INTCODE_GEQ;		break;}
							case GT: 		{op = INTCODE_GT;		break;}
							case LT: 		{op = INTCODE_LT;		break;}
							case LTE: 		{op = INTCODE_LEQ;		break;}
							default:
							{
								printf("Operando nao reconhecido \n");
								exit(1);
							}
						}
						///gera um temporario pra armazenar o resultado;
						sprintf(tempVar, "_TEMP%d_", tempVarCounter);
						tempVarCounter++;
						char *local_tempVar = (char*)malloc(sizeof(char)*50);
						for(int i = 0; i<50; i++)
						{
							local_tempVar[i] = tempVar[i];
						}
						
						//printf("local_tempVar: %s\n", local_tempVar);
						if(op1.kind == String && op2.kind == String)sprintf(toFile, "(%s,%s,%s,%s)\n", returnToken(op), op1.contents.nome, op2.contents.nome, tempVar);
						if(op1.kind == ConstInt && op2.kind == String)sprintf(toFile, "(%s,%d,%s,%s)\n", returnToken(op), op1.contents.val, op2.contents.nome, tempVar);
						if(op1.kind == String && op2.kind == ConstInt)sprintf(toFile, "(%s,%s,%d,%s)\n", returnToken(op), op1.contents.nome, op2.contents.val, tempVar);
						if(op1.kind == ConstInt && op2.kind == ConstInt)sprintf(toFile, "(%s,%d,%d,%s)\n", returnToken(op), op1.contents.val, op2.contents.val, tempVar);
						fprintf(fp, "%s", toFile);
						Address retVal;
						retVal.contents.nome = local_tempVar;
						retVal.kind = String;
						root->codeGen = 1;
						return retVal;
						break;
					}
					case ConstK:
					{
						Address returnVal;
						if(root->codeGen != 1){
							//printf("NumK (processExp)\n");
							Address returnVal;
							returnVal.contents.val = root->attr.val;
							returnVal.kind = ConstInt;
							root->codeGen = 1;
							return returnVal;
						}
						returnVal.kind = Vazio;
						return returnVal;
						break;
					}
					case IdK:
					{
						if(root->kind.decl == FunK)
						{
							if(root->codeGen != 1)
							{
								char * entrada = "fundef";
								fprintf(fp, "(%s,%s,_,_)\n", entrada, root->attr.name);
								if(root->child[1]!=NULL)CodeGen(root->child[1]); //primeiro filho da funcao tem parametros, segundo tem codigo
								else fprintf(fp, "(nop,_,_,_)\n");
								//root->codeGen = 1;
							}
						}
						else if(root->kind.exp == FunIdK)
						{
							Address returnVal;
							if(root->codeGen != 1)
							{
								//printf("root == CallK\n");
								TreeNode* aux;
								char * entrada = "funcal";
								if(root->child[0]!=NULL)fprintf(fp, "(begin_args,_,_,_)\n");//funcao sem argumentos
								if(root->child[0]!=NULL && root->child[0]->nodekind == ExpK)
								{///indica que o argumento da funcao eh outra funcao.
								 ///precisa armazenar o temporario que vai servir de retorno para a avaliacao da funcaoArgumento
									sprintf(tempVar, "_TEMP%d_", tempVarCounter);
									tempVarCounter++;
								}
								printf("chegou aqui\n");
								genArguments(root->child[0]); //primeiro filho da funcao tem parametros, segundo tem codigo
								///pra gerar o codigo de return, eu preciso descobrir o que a funcao retorna. Como?
								///da pra percorrer a arvores e achar o no de retorno da funcao.
								fprintf(fp, "(%s,%s,_,_)\n", entrada, root->attr.name);
								//printf("procurando funcao:%s\n", root->attr.name);
								int t = findFuncRetVal(root->attr.name);
								printf("retorno FindFuncRetVal: %d\n", t);
								if(t)
								{
									//printf("Entrou aqui. If(t)\n");
									returnVal.kind = String;
									returnVal.contents.nome = FUNCTION_RETURN;
									//FUNCTION_RETURN = NULL;
								}
								root->codeGen = 1;
								return returnVal;
							}
							returnVal.kind = Vazio;
							return returnVal;
						}
						else if(root->kind.exp == IdArrayK)
						{
							Address returnVal;
							if(root->codeGen != 1)
							{
								
								returnVal = processExp(root->child[0]);
								if(returnVal.kind == ConstInt){
									sprintf(str_array,"%s[%d]", root->attr.name,returnVal.contents.val);
									returnVal.contents.nome = str_array;
									returnVal.kind = String;
									//printf("VALOR DO ARRAY: %s\n", str_array);
								}
								else
								{
									sprintf(str_array,"%s[%s]", root->attr.name,returnVal.contents.nome);
									returnVal.contents.nome = str_array;
								}
								//printf("retval: %s\n", returnVal.contents.nome);
								root->codeGen = 1;
								return returnVal;
							}
							returnVal.kind = Vazio;
							return returnVal;
						}else
						{
							Address returnVal;
							if(root->codeGen != 1)
							{
								//printf("IdK (processExp): ");
								Address returnVal;
								returnVal.contents.nome = root->attr.name;
								returnVal.kind = String;
								//printf("%s\n", root->attr.name);
								root->codeGen = 1;
								return returnVal;
							}
							returnVal.kind = Vazio;
							return returnVal;
						}
						break;
					}
					// case DeclTypeK:
					// {
						// break;
					// }
					// case MemVarK:
					// {
						// break;
					// }
					default:
					{
						// printf("Erro nao conhecido\n");
						// exit(1);
					}
				}
				break;
			}
			default: 
			{
				printf("Erro nao conhecido.\n");
				exit(1);
			}
		}
	}
}

Address processStmt(TreeNode* root)
{
	switch(root->kind.stmt)
	{
		case AssignK:
		{
			if(root->codeGen!=1){
				Address tempEsq, tempDir;
				char charOp1[50], charOp2[50];
				///lado esquerdo so pode ser variavel ou veotr. Trivial.
				///lado direito pode ser expressao, variavel ou inteiro.
				///se chamar processExp deve funcionar de prima.
				///precisa armazenar o temporario que vai salvar a expressao do lado direito.
				if(root->child[0]->kind.exp == IdArrayK && root->child[1]->kind.exp == IdArrayK) 
				{
					printf("array\n");
					tempEsq = processExp(root->child[0]);
					if(tempEsq.kind == String)sprintf(charOp1, "%s", tempEsq.contents.nome);
					if(tempEsq.kind == ConstInt)sprintf(charOp1, "%d", tempEsq.contents.val);
					//if(tempEsq.kind != Vazio)printf("nome: %s\n", charOp1);
					tempEsq.contents.nome = charOp1;
					tempDir = processExp(root->child[1]);
					if(tempDir.kind == String)sprintf(charOp2, "%s", tempDir.contents.nome);
					if(tempDir.kind == ConstInt)sprintf(charOp2, "%d", tempDir.contents.val);
					//if(tempDir.kind != Vazio)printf("nome: %s\n", charOp2);
					tempDir.contents.nome = charOp2;
					
				}
				else
				{
					tempEsq = processExp(root->child[0]);
					tempDir = processExp(root->child[1]);
				}
				if(FUNCTION_SEARCH)
				{
					//printf("retval: %s\n", FUNCTION_RETURN);
					sprintf(charOp1, "%s", FUNCTION_RETURN);
					tempDir.contents.nome = charOp1;
					tempDir.kind = String;
					printf("retval : %s\n", tempDir.contents.nome);
					FUNCTION_SEARCH = 0;
				}
				if(tempEsq.kind == String && tempDir.kind == String)sprintf(toFile, "(%s,%s,%s,_)\n", "ld", tempEsq.contents.nome, tempDir.contents.nome);
				if(tempEsq.kind == ConstInt && tempDir.kind == String)sprintf(toFile, "(%s,%d,%s,_)\n", "ld", tempEsq.contents.val, tempDir.contents.nome);
				if(tempEsq.kind == String && tempDir.kind == ConstInt)sprintf(toFile, "(%s,%s,%d,_)\n", "ld", tempEsq.contents.nome, tempDir.contents.val);
				if(tempEsq.kind == ConstInt && tempDir.kind == ConstInt)sprintf(toFile, "(%s,%d,%d,_)\n", "ld", tempEsq.contents.val, tempDir.contents.val);
				fprintf(fp, "%s", toFile);
				
				root->codeGen = 1;
				
			}
			break;
		}
		case IfK:
		{
			if(root->codeGen!=1){
				Address ifCond;
				char labelTrue[10];
				char labelFalse[10];
				
				sprintf(labelFalse,"L%d", labelCounter);
				labelCounter++;
				sprintf(labelTrue,"L%d", labelCounter);
				labelCounter++;
				
				//Avalia Condicao
				ifCond = processExp(root->child[0]); ///pela definicao da gramatica so pode ter expressao na condicao do if.
				//if_false t1 goto l0
				fprintf(fp,"(if_false,%s,%s,_) -->jump condicional\n", ifCond.contents.nome, labelFalse); //
				CodeGen(root->child[1]);//codigo para TRUE
				
				if(root->child[2]!=NULL)
				{
					fprintf(fp,"(%s,%s,_, _) -->jump para o fim\n", jump, labelTrue);//goto l1
					fprintf(fp,"(label,%s,_,_) -->label false\n", labelFalse);//label
					CodeGen(root->child[2]);
					fprintf(fp,"(label,%s,_,_) -->label do fim\n", labelTrue);
				}else
				{
					fprintf(fp,"(label,%s,_,_) -->label do fim\n", labelFalse);
				}
				root->codeGen= 1;
			}
			
			break;
		}
		case WhileK:
		{
			if(root->codeGen!=1){
				Address whileCond;
				char labelContinue[10];
				char labelBreak[10];
				sprintf(labelContinue,"L%d", labelCounter);
				labelCounter++;
				sprintf(labelBreak,"L%d", labelCounter);
				labelCounter++;
				fprintf(fp,"(label,%s,_,_)\n", labelContinue);
				whileCond = processExp(root->child[0]);
				fprintf(fp,"(if_false,%s,%s,_)\n", whileCond.contents.nome, labelBreak);
				CodeGen(root->child[1]);
				fprintf(fp,"(%s,%s,_,_)\n", jump, labelContinue);
				fprintf(fp,"(label,%s,_,_)\n", labelBreak);
				root->codeGen= 1;
			}
			break;
		}
		case ReturnK:
		{
			if(root->codeGen!=1){
				if(root->child[0]!=NULL){
					Address retVal;
					if(root->child[0]->kind.exp == IdK || root->child[0]->kind.exp == IdK)
					{//indica que no return tem uma variavel ou um vetor. Precisa armazenar num temp
						sprintf(tempVar, "_TEMP%d_", tempVarCounter);
						tempVarCounter++;
						retVal.contents.nome = tempVar;
						retVal.kind = String;
						fprintf(fp,"(ld,%s,%s,_)\n", retVal.contents.nome, root->child[0]->attr.name);
					}	
					else
					{
						retVal = processExp(root->child[0]);
					}
					if(retVal.contents.nome == NULL)
						fprintf(fp,"(ret,_,_,_)\n");
					else 
					{
						if(retVal.kind == String)fprintf(fp,"(ret,%s,_,_)\n", retVal.contents.nome);
						if(retVal.kind == ConstInt)fprintf(fp,"(ret,%d,_,_)\n", retVal.contents.val);
					}
					root->codeGen= 1;
				} else 
				{
					fprintf(fp,"(ret,_,_,_)\n");
					root->codeGen= 1;
				}
				break;
			}
		}
	}
}

void CodeGen(TreeNode* root)
{
	//processa
	if(root != NULL)
	{
		switch(root->nodekind)
		{
			
			case StmtK:
			{
				processStmt(root);
				break;
			}
			case ExpK:
			{
				///operacoes matematicas e logias em pos-ordem. Talvez usar notacao polonesa?
				///primeiro trata os dois filhos, depois trata a raiz
				///ExpK tambem pode ser declaracao de funcao. Se for IdK e id_type for FuncDeclK eh declaracao de funcao. Tratado dentro do processExp();
				processExp(root);
				break;
			}
			default: 
			{
				printf("Erro nao conhecido.\n");
				exit(1);
			}
			
		}
		
		//caminha
		if(root->child[0] != NULL )CodeGen(root->child[0]);
		if(root->child[1] != NULL )CodeGen(root->child[1]);
		if(root->child[2] != NULL )CodeGen(root->child[2]);
		CodeGen(root->sibling);
	}
}


void generateIntermCode(TreeNode* savedTree)
{
	fp = fopen("IntermediateCode.txt", "w+");
	printf("\nentrou\n");
	CodeGen(savedTree);
	fprintf(fp,"(halt,_,_,_)\n");
	printf("gerou\n");
}
