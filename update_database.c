#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    printf("Enter the filename\n");
    scanf("%s", file_name);

    // validation 
    int empty = isFileEmpty(file_name);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File name :%s is not available\n",file_name);
            printf("Hence we are not adding that file into linked list\n");
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File name :%s is not having contents in it \n",file_name);
            printf("Hence we are not adding that file into linked list\n");
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, file_name);
            if(ret_val == SUCCESS)
            {
                printf("Successfull : in inserting the file : %s into file linked list \n",file_name);
            }
            else if(ret_val == REPETATION)
            {
                printf("this file name %s is repeated. donot add this file to file linked list\n",file_name);
            }
            else
            {
                printf("Failure\n");
            }
        }
    // create data base

    while(*f_head)
    {
        if(!strcmp((*f_head)->file_name,file_name))
        {
            create_database(*f_head, head);
        }
        *f_head = (*f_head)->link;
    }
} 

