#include "inverted_search.h"

void save_database(Wlist *head[])
{
    // Static variable to store the filename across multiple calls
    static char file_name[FNAME_SIZE] = "";

    // Ask for the filename only if it's not already set
    if (file_name[0] == '\0') 
    {
        printf("Enter the file name to save the database:\n");
        scanf("%s", file_name);
    }

    // Open the file with the saved filename for writing
    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL) 
    {
        printf("Error: Unable to open file %s for writing\n", file_name);
        return;
    }

    // Iterate through the head array
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }

    fclose(fptr);  // Close the file
    printf("Database saved successfully to %s\n", file_name);
}

void write_databasefile(Wlist *head, FILE *databasefile)
{
    Wlist *current = head;

    // Iterate over each word node in the Wlist linked list
    while (current != NULL)
    {
        // Write the word and the file count
        fprintf(databasefile, " #[%d] word is [%s]: file count is %d:files/s:",tolower(head->word[0]) % 97, current->word, current->file_count);

        // Iterate through each file entry in the Tlink list
        Ltable *file_entry = current->Tlink;
        while (file_entry != NULL)
        {
            fprintf(databasefile, "file is %s: word count is %d ", file_entry->file_name, file_entry->word_count);
            file_entry = file_entry->table_link;
        }

        fprintf(databasefile, "\n"); // Newline for the next word
        current = current->link;
    }
}
