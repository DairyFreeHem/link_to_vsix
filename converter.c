#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link_details.h"
#include "string.h"

string *download_template;
string *version = NULL;


int convert_link(string *link, link_details **output)
{
    char *developer, *package_name;
    char *link_package = strstr(link->str,"itemName=");
    // Length of the string "itemName="
    int prefix_length = 9;
    const char delim[2] = ".";
    char* package_info = strtok(&(link_package[prefix_length]), delim);

    developer = package_info;
    package_name = strtok(NULL, delim);

    if (package_name == NULL)
    {
        printf("Error, Package name missing, please make sure your URL is correct\n");
        FREEUP(output);
        return -1;
    }

    string *download_link = replace_string(download_template,"<developer>",developer);
    replace_new_string(&download_link, "<package>",package_name);
    if (version != NULL)
    {
        replace_new_string(&download_link,"<version>",version->str);
    }
    
     *output = new_link(download_link->str,package_name,developer,version->str);


    delete_string(download_link);
    download_link = NULL;
    
    return 0;
}


int main(int argc, char* argv[])
{
    int return_code = 0;
    if (argc > 1)
    {
        if (argc > 2)
        {
            version = new_string(argv[2]);
        }
        
        download_template = new_string("https://marketplace.visualstudio.com/_apis/public/gallery/publishers/<developer>/vsextensions/<package>/<version>/vspackage");
        string *market_link = new_string(argv[1]);
        link_details *det = NULL;
        return_code = convert_link(market_link,&det);

        printf("%s \n",det->link->str );

        delete_link(det);
        det = NULL;
        delete_string(market_link);
        market_link = NULL;
        return return_code;
    }
    else
    {
        printf("No package imputted, please input link as app parameter\n");
    }


    printf("No file inputted, exiting...\n");
    return return_code;
}








