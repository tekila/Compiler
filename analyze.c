/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

/* counter for variable memory locations */
static int location = 0;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
// static void traverse( TreeNode * t,
               // void (* preProc) (TreeNode *),
               // void (* postProc) (TreeNode *) )
// { 
	// if (t != NULL)
	// { 
		// preProc(t);
		// { 
			// int i;
			// for (i=0; i < MAXCHILDREN; i++)
				// traverse(t->child[i],preProc,postProc);
		// }
		// postProc(t);
		// traverse(t->sibling,preProc,postProc);
	// }
// }

/*
 * visits all children, then root node, then its siblings
 */
static void traverse( TreeNode * root)
{
	if(root!=NULL){
		insertNode(root); 
		traverse(root->child[0]);
		traverse(root->child[1]);	
		traverse(root->child[2]);
		traverse(root->sibling);
	}
	
}

int notNull(TreeNode * t)
{
	if(t == NULL) return 0;
	return 1;
}

/*
 * treatChainedOps treats tree nodes composed by multiple expressions
 * such as var1 = 5+var2*9/var3;
 */

static int treatChainedOps(TreeNode * t)
{
	//child 0 - left tree
	//child 1 - right tree
	int r, l;
	if(notNull(t))
	{
		if(notNull(t->child[0]) && notNull (t->child[1]))
		{
			//if both left and right subtree have integers, then return 1 to caller;
			if(t->child[0]->kind.exp == OpK)
			{
				l = treatChainedOps(t->child[0]);
			}
			else if(t->child[0]->Type == Integer)
			{
				return 1;
			}
			else if(t->child[1]->kind.exp == OpK)
			{
				r = treatChainedOps(t->child[1]);
			}
			else if(t->child[1]->Type == Integer)
			{
				return 1;
			}
			else
			{
				//ERROR: typecheck detected something other than Int.
				fprintf(listing,"::::ERROR 1:::: Operation with void. Line %d:\n", t->lineno);
				Error = TRUE;
				return 0;
			}
		}
		if(l == 1 && r == 1) {t->Type == Integer; return 1;}
		else return 0;
	}
	
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{ 
	
	switch (t->nodekind)
	{ 
		case StmtK:
			switch (t->kind.stmt)
			{ 
				case AssignK:
				{	
					//On assign, must verify if we are not assigning a void value to an Int;
					//Child[0] holds left side of assign;
					//child[1] holds value to be assigned.
					//If its an operation,ignode because its treated somewhere else
					//Must also verify if lefthand side is a variable and if its declared.
					if(t->child[0]->kind.exp == IdK || t->child[0]->kind.exp == IdArrayK) //lefthand side is a variable.
					{
						//we now know that the lefthand side is valid
						if(t->child[1]->kind.exp == FunIdK)
						{
							//if the righthand side has a function, then search for the return value in the symbol table
							TypeKind returnType = st_lookup_type(t->child[1]->attr.name,"global", t->child[1]->kind.decl);
							if(returnType == Void){
								fprintf(listing,"::::ERROR 2-a:::: Integer `%s` receiving function `%s` which returns void. Line %d:\n", t->child[0]->attr.name, t->child[1]->attr.name, t->lineno);
								Error = TRUE;
							}
						}
						else if(t->child[1]->Type == Void && t->child[1]->kind.exp != OpK)
						{
							//Invalid assignment, show error
							fprintf(listing,"::::ERROR 2-b:::: Integer receiving void return. Line %d:\n", t->lineno);
							Error = TRUE;
						}
						
					}
					else
					{
						//lefthand side not a variable. Show error.
						fprintf(listing,"::::ERROR 3:::: Lefthand side of ASSIGN is not a variable. Line %d:\n",t->lineno);
						Error = TRUE;
					}
					break;
				}
				case IfK:
				{
					
				}
				case WhileK:
				case ReturnK:
				default:
				break;
			}
			break;
		case ExpK:
			switch (t->kind.exp)
			{ 
				case IdArrayK: //same as IdK
				case IdK:
				{
					//finding an IdK means we found a variable that should`ve been declared
					//earlier in the code. This means we have to check if it has been declared
					//indeed. Show error if it hasn`t been.
					if(st_lookup(t->attr.name, t->scope, t->kind.exp) == -1)
					{
						//Not in the table. Activation without declaration.
						fprintf(listing,"::::ERROR 4:::: Variable `%s` in `%s` scope used without declaration. Line %d:\n",t->attr.name, t->scope,  t->lineno);
						Error = TRUE;
					}
					break;
				}
				case OpK:
				{
					//same drill as the assignent. Must check with both kids are integers.
					if(!(t->child[0]->Type == Integer && t->child[1]->Type == Integer))
					{
						//if(not(bothIntegers))
						if(t->child[0]->kind.exp == OpK)
						{
							//operations chained togheter, typechecks in a independent function.
							treatChainedOps(t);
						}
					}
					
					
					break;
				}
				case FunIdK:
				{
					int st_lookup_return = st_lookup(t->attr.name, "global", t->kind.decl);
					if( st_lookup_return == -1)
					{
						//Not in the table. Activation without declaration.
						fprintf(listing,"::::ERROR 5:::: Function `%s` in %s Scope used without declaration. Line: %d\n",t->attr.name, t->scope,  t->lineno);
						Error = TRUE;
					}
					break;
				}
								
				default:
				break;
			}
			break;
		case SysK:
			printf("TODO: Inserting SysK\n"); break;
		case DeclK:
			{
				switch (t->kind.decl)
				{
					case ArrayK:
					case VarParK:
					case ArrayParK:
					case VarK:
					{
						
						
						//found a var declaration. must know if its already in the table.
						int st_lookup_return = st_lookup(t->attr.name, t->scope, t->kind.decl);
						int st_lookup_global = st_lookup_var_fun_same_name(t->attr.name, t->kind.decl);
						if(st_lookup_return == -2) //theres another variable here with the same scope
						{
							fprintf(listing,"::::ERROR 6:::: Variable `%s` uses same name as another identifier. Line %d:\n",t->attr.name, t->lineno);
							Error = TRUE;						
						}
						if(st_lookup_return == -1) //theres not another variable. must insert
						{
							if(t->Type == Void)
							{
								fprintf(listing,"::::ERROR 9:::: Variable `%s` declared as void. Line %d:\n",t->attr.name, t->lineno);
								Error  = TRUE;
							}else 
							{
								if(st_lookup_global == -2)
								{
									fprintf(listing,"::::ERROR 6:::: Variable `%s` uses same name as another identifier. Line %d:\n",t->attr.name, t->lineno);
							Error = TRUE;
								}
								st_insert(t->attr.name, t->scope, t->lineno, location++, t->Type, t->kind.decl);
								// if(SemanticDebug) printf("IdK inserted: %s\n", t->attr.name);
							}
						}
						break;
					}
					case FunK:
					{
						//found a function declaration. must know if its already in the table.
						int st_lookup_return = st_lookup(t->attr.name, "global", t->kind.decl);
						int st_lookup_global = st_lookup_var_fun_same_name(t->attr.name, t->kind.decl);
						if(st_lookup_return == -2) //theres another variable here with the same scope
						{
							fprintf(listing,"::::ERROR 7:::: Function %s uses same name as another identifier. Line %d:\n",t->attr.name, t->lineno);
							Error = TRUE;						
						}
						if(st_lookup_return == -1) //theres not another variable. must insert
						{
							if(st_lookup_global == -2)
							{
								fprintf(listing,"::::ERROR 7:::: Function %s uses same name as another identifier. Line %d:\n",t->attr.name, t->lineno);
								Error = TRUE;	
							}else st_insert(t->attr.name, "global", t->lineno, location++,  t->Type, t->kind.decl);
							// if(SemanticDebug) printf("Function inserted: %s as %s\n", t->attr.name, returnType(t->Type));
						}
					}
				}
			}
			break;
		case TypeK: //should something even be done here??
			//printf("TODO: Inserting TypeK\n"); break;
		
		default:
		break;
	}
}

void verifyMain()
{
	int main = st_lookup_main();
	if(main == -1)
	{
		fprintf(listing,"::::ERROR 8-a:::: Function 'main' not found.\n");
		Error = 1;
	}
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
	traverse(syntaxTree);
	verifyMain();
	if (TraceAnalyze)
	{ 
		
		if(!Error){
			fprintf(listing,"\nSymbol table:\n\n");
			printSymTab(listing);
		}
		else 
		{
			printf("Compilation Error: check log\n");
			exit(1);
		}
	}
}

static void typeError(TreeNode * t, char * message)
{ 
	fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
	Error = TRUE;
}


/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ 
	traverse(syntaxTree);
}
