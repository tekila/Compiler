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
				fprintf(listing,"ERROR: Operation with void. Line %d:\n", t->lineno);
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
					//If its an operation, acquire the return value from root->Type
					//Must also verify if lefthand side is a variable and if its declared.
					if(t->child[0]->kind.exp == IdK || t->child[0]->kind.exp == IdArrayK) //lefthand side is a variable.
					{
						//we now know that the lefthand side is valid
						if(t->child[1]->Type == Void && t->child[1]->kind.exp!=OpK)
						{
							//Invalid assignment, show error
							printf("%d -------------------\n", t->child[1]->attr.val);
							fprintf(listing,"ERROR 1: Integer receiving void return. Line %d:\n", t->lineno);
							Error = TRUE;
						}
						
					}
					else
					{
						//lefthand side not a variable. Show error.
						fprintf(listing,"ERROR 2: Lefthand side of ASSIGN is not a variable. Line %d:\n",t->lineno);
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
					if(st_lookup(t->attr.name, t->scope) == -1)
					{
						//Not in the table. Activation without declaration.
						fprintf(listing,"ERROR: Variable %s used without declaration. Line %d:\n",t->attr.name, t->lineno);
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
					int st_lookup_return = st_lookup(t->attr.name, t->scope);
					if( st_lookup_return == -1)
					{
						//Not in the table. Activation without declaration.
						printf("st_lookup_return");
						fprintf(listing,"ERROR 3: Function %s in %s Scope used without declaration. \nLine: %d\n",t->attr.name, t->scope,  t->lineno);
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
						int st_lookup_return = st_lookup(t->attr.name, t->scope);
						//found a var declaration. must know if its already in the table.
						if(st_lookup_return == -2) //theres another variable here with the same scope
						{
							fprintf(listing,"ERROR 4: Variable %s uses same name, in the same scope, as another identifier. Line %d:\n",t->attr.name, t->lineno);
							Error = TRUE;						
						}
						if(st_lookup_return == -1) //theres not another variable. must insert
						{
							st_insert(t->attr.name, t->scope, t->lineno, location++);
						}
						break;
					}
					case FunK:
					{
						int st_lookup_return = st_lookup(t->attr.name, t->scope);
						//found a var declaration. must know if its already in the table.
						if(st_lookup_return == -2) //theres another variable here with the same scope
						{
							fprintf(listing,"ERROR 5: Function %s uses same name, in the same scope, as another idenfier. Line %d:\n",t->attr.name, t->lineno);
							Error = TRUE;						
						}
						if(st_lookup_return == -1) //theres not another variable. must insert
						{
							st_insert(t->attr.name, t->scope, t->lineno, location++);
							if(SemanticDebug) printf("Function inserted: %s\n", t->attr.name);
						}
					}
				}
			}
			break;
		case TypeK:
			printf("TODO: Inserting TypeK\n"); break;
		
		default:
		break;
	}
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
	traverse(syntaxTree);
	if (TraceAnalyze)
	{ 
		fprintf(listing,"\nSymbol table:\n\n");
		printSymTab(listing);
	}
}

static void typeError(TreeNode * t, char * message)
{ 
	fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
	Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ 
	// switch (t->nodekind)
  // { case ExpK:
      // switch (t->kind.exp)
      // { case OpK:
          // if ((t->child[0]->type != Integer) ||
              // (t->child[1]->type != Integer))
            // typeError(t,"Op applied to non-integer");
          // if ((t->attr.op == EQ) || (t->attr.op == LT))
            // t->type = Boolean;
          // else
            // t->type = Integer;
          // break;
        // case ConstK:
        // case IdK:
          // t->type = Integer;
          // break;
        // default:
          // break;
      // }
      // break;
    // case StmtK:
      // switch (t->kind.stmt)
      // { case IfK:
          // if (t->child[0]->type == Integer)
            // typeError(t->child[0],"if test is not Boolean");
          // break;
        // case AssignK:
          // if (t->child[0]->type != Integer)
            // typeError(t->child[0],"assignment of non-integer value");
          // break;
        // case WriteK:
          // if (t->child[0]->type != Integer)
            // typeError(t->child[0],"write of non-integer value");
          // break;
        // case RepeatK:
          // if (t->child[1]->type == Integer)
            // typeError(t->child[1],"repeat test is not Boolean");
          // break;
        // default:
          // break;
      // }
      // break;
    // default:
      // break;

  // }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ 
	traverse(syntaxTree);
}
