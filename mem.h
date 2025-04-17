/*Macro to free up dynamically allocated data*/
#define FREEUP(ptr) {\
                            if (ptr != NULL)\
                            {\
                                free(ptr);\
                                (ptr) = (NULL);\
                            }\
                          }

