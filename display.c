#include "inverted_search.h"

void display_database(Wlist *head[])
{
    printf(" [index]\t[word]\t\tfile_count file/s\tFile: File_name\t\tword_count\n");

    int i=0;
    for(i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}
void print_word_count(Wlist *head)
{
    // traverse
    while(head != NULL)
    {
        printf(" [%d]\t\t%s\t\t%d file/s", tolower(head->word[0]) % 97, head->word, head->file_count);

        Ltable *Thead = head->Tlink;
        while(Thead)
        {
            printf(" \t\t%s\t\t%d",Thead->file_name,Thead->word_count);
            Thead = Thead->table_link;
        }
        printf("\n");
        head = head->link;
    }
}