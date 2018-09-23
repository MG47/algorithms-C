/*
* Custom implmentation of ctype.h
* TODO
*/

#ifndef CTYPE_CUSTOM_H
#define CTYPE_CUSTOM_H

#define ISSPACE(c) (c == ' ' || c == '\n' || c == 'r' || c == '\t')

#define ISDIGIT(c) ((c >= '0') && (c <= '9'))

#define ISALPHA(c) (((c >= 'A') && (c <= 'Z')) || ((c >= 'a')  && (c <= 'z')))

#define ISUPPER(c) ((c >= 'A') && (c <= 'Z')))

#define ISLOWER(c) ((c >= 'a') && (c <= 'z')))

#define ISALNUM(c) (((c >= '0') && (c <= '9')) \
	|| ((c >= 'A') && (c <= 'a')) \
	|| ((c >= 'a') && (c <= 'z')))

#define ISASCII(c) (c < 128)

#define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? c + 32 : c)

#define TOUPPER(c) ((c >= 'a' && c <= 'z') ? c - 32 : c)

/* TODO */
/*
int   isblank(int);
int   iscntrl(int);
int   isgraph(int);
int   isprint(int);
int   ispunct(int);
int   isxdigit(int);

int   toascii(int);

*/

#endif /*CTYPE_CUSTOM_H*/


