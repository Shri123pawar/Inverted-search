#include "inverted_search.h"
/*
Name : Shridhar pawar
project : Inverted search
*/
int main(int argc, char *argv[])
{
    system("clear");
    // validate CLA
    if(argc <=1)
    {
        printf("enter valid no of arguments\n");
        printf("./slist.exe file1.txt file2.txt......");
        return 0;
    }

    // create file linked link 
    // first declare head pointer 

    Flist *f_head = NULL;

    // validate the files

    file_validation_n_file_list(&f_head, argv);
    if(f_head == NULL)
    {
        printf("no files are added to file linked list\n");
        printf("Hence the process gets terminated \n");
        return 1;
    }

    // Initialize the Wlist pointer array
    Wlist *head[26] = {NULL};  // Initializes the array
    
    // prompt the user for choice 
    
    int choice;
    char cont; // Variable to store user choice for continuation

    do
    {
        printf("\n");
        printf(" Select your choice among following options\n");
        printf("1. Create DATABASE\n");
        printf("2. Display DATABASE\n");
        printf("3. Update DATABASE\n");
        printf("4. search\n");
        printf("5. Save DATABASE\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            create_database(f_head, head);
            break;
        case 2:
            display_database(head);
            break;
        case 3:
            update_database(head, &f_head);
            break;
        case 4:
            char word[WORD_SIZE];
            printf("Enter the word to search \n");
            scanf("%s",word);
            int index = tolower(word[0]) % 97;
            // now call search function  
            search(head[index], word);
            break;
        case 5:
            save_database(head);
            break;
        default:
            printf("Invalid input\n");
        }
        // Ask the user if they want to continue
            printf("Do you want to continue? (Y/N): ");
            scanf(" %c", &cont);
            getchar();
    } while(cont == 'Y' || cont == 'y');
    return 0;
}