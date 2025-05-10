#include "inverted_search.h"
char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
    // traverse through the file linked list 

    while(f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
    // Print success message after processing all files
    printf("Database is successfully created.\n");
}

// read content from a file 
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    // open the file in read mode 
    FILE *fptr = fopen(filename, "r");  
    fname = filename;//  it is made extern so that this file name is accessed in another .c file also (see line 2 )
    int flag = 1;
    // declare an array 
    char word[WORD_SIZE];

    while(fscanf(fptr, "%s" , word)!= EOF)
    {
        int index = tolower(word[0]) % 97;
        if(!(index >=0 && index <=25))
        {
            index = 26;
        }
        // check words are repeating or not 
        
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            // compare new word with each node word
            while(temp)
            {
                if(!strcmp(temp->word,word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if(flag == 1)
        {
            //if not repeating 
            insert_at_last(&head[index], word);
        }
    }
}

int update_word_count(Wlist **head, char *filename)
{
    // Check if head is NULL
    if (head == NULL || *head == NULL) 
    {
        return FAILURE; 
    }

    Wlist *temp = *head;

    // Traverse the Wlist nodes
    while (temp != NULL) 
    {
        // Check the linked Ltable nodes for the filename
        Ltable *ltable_temp = temp->Tlink;
        Ltable *prev_ltable = NULL;

        // Check if the Ltable node matches the filename
        while (ltable_temp != NULL)
        {
            if (strcmp(ltable_temp->file_name, filename) == 0) 
            {
                // If filenames match, increment the word count
                ltable_temp->word_count++;
                return SUCCESS; // Successfully updated
            }
            prev_ltable = ltable_temp;
            ltable_temp = ltable_temp->table_link; // Move to the next Ltable node
        }

        // If no matching filename found, create a new Ltable entry
        Ltable *new_ltable_entry = malloc(sizeof(Ltable));
        if (new_ltable_entry == NULL)
        {
            return FAILURE; // Handle memory allocation failure
        }

        // Initialize the new Ltable entry
        strcpy(new_ltable_entry->file_name, filename); // Copy the filename
        new_ltable_entry->word_count = 1; // Set initial word count
        new_ltable_entry->table_link = NULL; // No next entry yet
        
        // Link the new Ltable entry to the end of the Ltable list
        if (prev_ltable != NULL)
        {
            prev_ltable->table_link = new_ltable_entry;
        }
        else
        {
            // If this is the first Ltable node, link it directly to the Wlist node
            temp->Tlink = new_ltable_entry;
        }

        // Increment file count in the Wlist node
        temp->file_count++;
        
        return SUCCESS; // Successfully added new Ltable entry
    }

    return FAILURE; // No matching Wlist node found
}
