/****************************************************/
/* File: tiny.l                                     */
/* Lex specification for TINY                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "tiny.tab.h"

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
//extern int yylex(void);

%}

digito       	[0-9]
numero      	{digito}+
letra	      	[a-zA-Z]
identificador  	{letra}+({letra}|{digito})*
newline 		\n
carriage 		\r
whitespace 		[ \t]+


%%
"if"            	{return IF;}
"else"          	{return ELSE;}
"int "          	{return INT;}
"return"       		{return RETURN;}
"void"        		{return VOID;}
"while"         	{return WHILE;}
"__sys_input()"  	{return SYS_INPUT;}
"__sys_output()"  	{return SYS_OUTPUT;}
"__sys_kill()"		{return SYS_KILL;}
"__sys_run()"		{return SYS_RUN;}
"__sys_save()"		{return SYS_SAVE;}
"+"             	{return PLUS;}
"-"             	{return MINUS;}
"*"             	{return TIMES;}
"/"             	{return OVER;}
"<"             	{return LT;}
"<="				{return LTE;}
">"					{return GT;}	
">="				{return GTE;}
"="					{return ASSIGN;}
"=="				{return EQ;}
"!="				{return NEQ;}
";"             	{return SEMI;}
","					{return COMMA;}
"("             	{return LPAREN;}
")"             	{return RPAREN;}
"["					{return LSQR;}
"]"					{return RSQR;}
"{"					{return LCURLY;}
"}"					{return RCURLY;}
{numero}        	{strcpy(tokenString, yytext);return NUM;}
{identificador} 	{strcpy(tokenString, yytext);return ID;}
{newline}       	{if(lineno == 0)lineno = 2;else lineno++;}
{whitespace}    	{/* skip whitespace */}
"/*"            	{ 
						char c1, c2; //Inicio Comentario
						do
						{ 
							c1 = input();
							if (c1 == EOF) break;
							if (c1 == '\n') lineno++;
							if (c1 == '*')
							{
								c2=input();
								if(c2 == '/') break;
								if(c2 == EOF) break;
							}
						} while (1);
						
					}

.         			{printf("\n********************\nToken nao reconhecido: %d:%s\n", lineno, tokenString); return ERROR;}
%%





