/****************************************************/
/* File: parse.h                                    */
/* The parser interface for the TINY compiler       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#ifndef _PARSE_H_
#define _PARSE_H_

/* Function parse returns the newly 
 * constructed syntax tree
 */
TreeNode * parse(void);

/* Function scoper operates on the SavedTree from tiny.y 
 * to retrieve scope info for each and every case necessary.
 */
void scoper(TreeNode* root); 

#endif