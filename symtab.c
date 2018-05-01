/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int __hash(char * key)
{
    int temp = 0;
    int i = 0;
    while (key[i] != '\0') 
	{
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

static int hash(char * name, char* scope)
{
	char* key = malloc(strlen(name)+strlen(scope)+1);
	strcpy(key, name);
	strcat(key, scope);
    
    return __hash(key);
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec 
{
    int lineno;
    struct LineListRec * next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec 
{
    char * name;
	char * scope;
    LineList lines;
    int memloc; /* memory location for variable */
	TypeKind type;
	DeclKind kind;
    struct BucketListRec * next;
} * BucketList;




/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert(char * name, char* scope,  int lineno, int loc, TypeKind type, DeclKind kind)
{
    int h = hash(name, scope);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0)) l = l->next;
    if (l == NULL) /* variable not yet in table */ {
        l = (BucketList) malloc(sizeof(struct BucketListRec));
        l->name = name;
        l->lines = (LineList) malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->memloc = loc;
		l->scope = scope;
		l->type = type;
		l->kind = kind;
        l->lines->next = NULL;
        l->next = hashTable[h];
        hashTable[h] = l;
    } else /* found in table, so just add line number */ {
        LineList t = l->lines;
        while (t-> next != NULL) t = t-> next;
        t-> next = (LineList) malloc(sizeof(struct LineListRec));
        t-> next-> lineno = lineno;
        t-> next-> next = NULL;
    }
	
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 * or -2 if theres another variable in the 
 * same scope with the same name.
 */
int st_lookup(char * name, char * scope, DeclKind kind) 
{
	if(GeneralDebug) printf("New call of st_lookup::::\n");
    int h = hash(name, scope);
	if(kind == FunIdK) h = hash(name, scope);
	//if(kind == FunK) return st_verify_var_fun_same_name(name, kind);
	//all things with the same name and scope are in the same list.
    BucketList l = hashTable[h];
    while ((l != NULL) && strcmp(l->name, name) != 0 )
        l = l-> next;
    if (l == NULL) return -1; //something called `name` with scope `scope` is not in table
	else /*same name and scope in the table*/if(kind!= VarParK && kind != ArrayParK) return -2;
	else return l->memloc;
	
}

int st_lookup_var_fun_same_name(char* name, DeclKind kind)
{
	int i = 0;
	for(i; i<SIZE; i++)
	{
		BucketList l = hashTable[i];
		while(l!=NULL)
		{
			if(strcmp(name, l->name) == 0 && kind != l->kind && l->kind!=VarParK && l->kind!=ArrayParK) return -2;
			else l = l->next;
		}
	}
	return -1;
}


/*

    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l-> name) != 0))
        l = l-> next;
    if (l == NULL) return -1; //not in table
    else if(strcmp(l->scope, scope) == 0 || strcmp (l->scope, "global") == 0) return -2;
	else return l-> memloc;*/

/*
 * st_lookup_main() looks for a declaration of
 * main function in the symbolTable. 
 * return -2 if theres no mention of main
 * in a global scope
 * returns -1 if theres no mention of main at all.
 */

int st_lookup_main() 
{
	
	int i = 0;
	for(i; i<SIZE; i++)
	{
		BucketList l = hashTable[i];
		while(l!=NULL)
		{
			if(strcmp("main", l->name) == 0) return -2;
			else l = l->next;
		}
	}
	return -1;
    // int h = hash("main", "global\0");
    // BucketList l = hashTable[h];
    // while ((l != NULL) && (strcmp("main", l-> name) != 0))
        // l = l-> next;
    // if (l == NULL) return -1;
    // else if(strcmp (l->scope, "global") == 0) return -2;
	// else return l-> memloc;
}


/* Function st_lookup_type returns the type 
 * of return value of a function.
 */
TypeKind st_lookup_type(char * name, char * scope, DeclKind kind) 
{
	
    int h = hash(name, scope);
	//if(kind == FunIdK) h = hash(name, scope);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l-> name) != 0)){
		if(GeneralDebug)printf("st_lookup_type::: \n\tlooking at %s.\n\tlooking for %s\n", l->name, name);
        l = l-> next;
	}
    if (l == NULL) {
		return NotAType; 
	}
	else return l->type;
}





/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing) 
{
    int i;
    fprintf(listing, "Variable Name | Location |  Scope   |  Line Numbers   \n");
    fprintf(listing, "------------- | -------- | -------- |  ------------\n");
    for (i = 0; i < SIZE; ++i) {
        if (hashTable[i] != NULL) {
            BucketList l = hashTable[i];
            while (l != NULL) {
                LineList t = l->lines;
                fprintf(listing, "%-14s |", l->name);
                fprintf(listing, "%-8d |", l->memloc);
				fprintf(listing, "%-9s |", l->scope);
				fprintf(listing, "%d", t->lineno);
				t = t->next;
                while (t != NULL) {
                    fprintf(listing, ",%d", t->lineno);
                    t = t->next;
                }
				fprintf(listing, "\n");
                l = l->next;
            }
        }
    }
} /* printSymTab */