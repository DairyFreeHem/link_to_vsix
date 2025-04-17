#include "string.h"

string *new_string(char* text)
{
    int text_size = strlen(text);
    char* str = (char *)malloc(text_size+1);
    strncpy(str,text,(text_size));
    str[(text_size)] = '\0';
    string *nustring =  (string *)malloc(sizeof(string));
    nustring->size = text_size;
    nustring->str = str;

    return nustring;
}

void delete_string(string *str)
{
    if (str->str != NULL)
    {
        free(str->str);
    }
    
}


string *replace_string(string *str, char *src, char *dst)
{
    string *ret_val;
    int src_len = strlen(src);
    int dst_len = strlen(dst);
    char *str_since_src = strstr(str->str, src);

    if (str_since_src != NULL)
    {
        ret_val = (string *)malloc(sizeof(string));
        int str_since_src_len = strlen(str_since_src);
        int str_len_short = str->size - (str_since_src_len);
        
        ret_val->size = ((str->size - src_len) + dst_len);
        if (ret_val != NULL)
        {   
            char *new_str = (char *)malloc(ret_val->size + 1);
            if (new_str != NULL)
            {
                strncpy(new_str,str->str, str_len_short); // First part of string
                strncpy(&(new_str[(str_len_short)]),dst,dst_len); // Replace string

                int rest_of_str_len = strlen(&(str_since_src[src_len]));
                strncpy(&(new_str[(str_len_short+dst_len)]),&(str_since_src[src_len]),rest_of_str_len);
                new_str[(ret_val->size)] = '\0';
                ret_val->str = new_str;

                return ret_val;
            }
        }
        

    }
    
    return NULL;
    
}