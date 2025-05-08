

#ifndef H_STRING
#define H_STRING

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"mem.h"


typedef struct string
{
    int size;
    char* str;

} string;


extern string *new_string(char *text);
extern void delete_string(string *str);
extern string *replace_string(string *str, char* src, char *dst);
extern void replace_new_string(string **str, char *src, char *dst );


#endif