#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i=1, empty;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File name :%s is not available\n",argv[i]);
            printf("Hence we are not adding that file into linked list\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File name :%s is not having contents in it \n",argv[i]);
            printf("Hence we are not adding that file into linked list\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfull : in inserting the file : %s into file linked list \n",argv[i]);
            }
            else if(ret_val == REPETATION)
            {
                printf("this file name %s is repeated. donot add this file to file linked list\n",argv[i]);
            }
            else
            {
                printf("Failure\n");
            }
            i++;
            continue;
        }
    }
}
// this function is used to check file availability and file contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }
    // moving file pointer to end and check with 0 so that we can know content is present in it or not 
    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name,name);
    new->link = NULL;
    // check for duplicates 
    Flist *temp = *f_head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, name) == 0) 
        {
            free(new);  // Free the new node if it's a duplicate
            printf("Duplicate file '%s' found. Not inserting.\n", name);
            return REPETATION;  // Indicate that the file was not inserted
        }
        temp = temp->link;
    }
    // check list is empty or not 
    if(*f_head == NULL)
    {
        *f_head=new;
        return SUCCESS;
    }

    //list not empty and no duplicates found .so insert the file into file linked list 
    Flist *temp1 = *f_head;
    while(temp1->link !=NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link=new;
    return SUCCESS;
}
