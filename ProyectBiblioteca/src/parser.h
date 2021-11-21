/*
 * parser.h
 *
 *  Created on: 20 Nov 2021
 *      Author: Lauta
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_OneBookFromText(FILE* pFile);
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook);

int parser_OneEditorialFromText(FILE* pFile);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
#endif /* PARSER_H_ */
