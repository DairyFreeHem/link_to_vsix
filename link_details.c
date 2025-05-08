#include "link_details.h"


// link_details *new_link(char* link, char* developer, char* package, char* version)
// {

// }

void delete_link(link_details *details)
{
    if ((details->link) != NULL)
    {
        delete_string(details->link);
    }
    if ((details->developer) != NULL)
    {
        delete_string(details->developer);
    }
    if ((details->package) != NULL)
    {
        delete_string(details->package);
    }

    FREEUP(details);
    details = NULL;
}

link_details *new_link(char *link, char *package, char *developer, char *version)
{
    link_details *obj = (link_details *)malloc(sizeof(link_details));
    if (obj == NULL)
    {
        fprintf(stderr, "New link_details object could not be instantiated.\n");
        return obj = NULL;
    }
    
    obj->link = NULL;
    obj->package = NULL;
    obj->version = NULL;

    if (link != NULL)
    {
        obj->link = new_string(link);
    }
    if (package != NULL)
    {
        obj->package = new_string(package);
    }
 
    if (developer != NULL)
    {
        obj->developer = new_string(developer);
    }
    if (version != NULL)
    {
        obj->version = new_string(version);
    }
    

    return obj;
    
}