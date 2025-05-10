#include "inverted_search.h"

int insert_at_last(Wlist *head[], data_t *data)
{
    // create a node for word
    Wlist *new = malloc(sizeof(Wlist));
    // error check 
    if(new == NULL)
    {
        return FAILURE;
    }
    // update the nodes
    new->file_count = 1;
    strcpy(new->word , data);
    new->Tlink = NULL;
    new->link = NULL;

    //update Ltable node 

    update_link_table(&new);
    // LIST IS EMPTY OR NOT 

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    // TRAVERSE UNTILL LAST 

    Wlist *temp = *head;
    while(temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

// Use extern to access fname defined in another file
extern char *fname;

// update Ltable 
int update_link_table(Wlist **head)
{
    // create a node
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
        return FAILURE;
    }
    // UPDATE FEILDS 
    new->word_count = 1;
    strcpy(new->file_name , fname); // here reference from line 40
    new->table_link = NULL;

    (*head)->Tlink = new; // so table is linked to word list
    return SUCCESS;
}