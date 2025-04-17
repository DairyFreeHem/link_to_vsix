#include "link_details.h"


// link_details *new_link(char* link, char* developer, char* package, char* version)
// {

// }

void delete_link(link_details *details)
{
    if ((details->link) != NULL)
    {
        free(details->link);
    }

    if ((details->developer) != NULL)
    {
        free(details->developer);
    }
    if ((details->package) != NULL)
    {
        free(details->package);
    }

    free(details);
    details = NULL;

}