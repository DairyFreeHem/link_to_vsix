

#ifndef H_LINK_DETAILS
#define H_LINK_DETAILS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "string.h"

typedef struct link_details
{
    string *link;
    string* developer;
    string* package;
    string* version;
}
link_details;


extern void delete_link(link_details *details);
extern link_details *new_link(char *link, char *package, char *developer, char *version);

#endif