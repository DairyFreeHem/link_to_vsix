#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link_details.h"
#include "string.h"

string *download_template;



int convert_link(string *link)
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
        return -1;
    }

    string *download_link = replace_string(download_template,"<developer>",developer);
    string *download_link_2 = replace_string(download_link, "<package>",package_name);

    delete_string(download_link);
    delete_string(download_link_2);
    
    
    return 0;
}


int main(int argc, char* argv[])
{
    int return_code = 0;
    if (argc > 1)
    {
        download_template = new_string("https://marketplace.visualstudio.com/_apis/public/gallery/publishers/<developer>/vsextensions/<package>/<version>/vspackage");
        string *market_link = new_string(argv[1]);
        return_code = convert_link(market_link);

        delete_string(market_link);
        return return_code;
    }
    else
    {
        printf("No package imputted, please input link as app parameter\n");
    }


    printf("No file inputted, exiting...\n");
    return return_code;
}








