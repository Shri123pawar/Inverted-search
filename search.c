#include "inverted_search.h"

void search(Wlist *head, char *word)
{
    if(head == NULL)
    {
        printf("List is empty , where search is not possible \n");
        return ;
    }
    // now traverse 
    while(head)
    {
        // compare each node word with the search word 
        if(!strcmp(head->word,word))
        {
            printf("word %s is present in %d files ",word,head->file_count);
            Ltable *Thead = head->Tlink;
            while(Thead)
            {
                printf("in file : %s is present for %d times \n",Thead->file_name,Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            return ;
        }
        head = head->link;
    }
    printf("Search word is not found \n");
}
