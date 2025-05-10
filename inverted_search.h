#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>

// define MACROS 

#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPETATION -4

extern char *fname;

// Structure for file list 
typedef char data_t;
typedef struct file_node
{
    data_t file_name[FNAME_SIZE];
    struct file_node *link;
}Flist;

// structure for word list 

typedef struct word_node
{
    int file_count;
    char word[WORD_SIZE];
    struct link_table_node *Tlink; // we can use Ltable *Tlink also
    struct word_node *link;
}Wlist;

// structure for link table
typedef struct link_table_node
{
    int word_count;
    char file_name[FNAME_SIZE];
    struct link_table_node *table_link;
}Ltable;

// function declarations
void file_validation_n_file_list(Flist **f_head, char *argv[]);

void create_database(Flist *f_head, Wlist *head[]);
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename);
// creating word list 
int insert_at_last(Wlist **head, data_t *data);
// update link table 
int update_link_table(Wlist **head);
// update word count 
int update_word_count(Wlist **head, char *file_name);
// display 
void display_database(Wlist *head[]);
// print word count 
void print_word_count(Wlist *head);
// search 
void search(Wlist *head, char *word);
// update 
void update_database(Wlist *head[], Flist **f_head);
// save database
void save_database(Wlist *head[]);
// write data base 
void write_databasefile(Wlist *head, FILE *databasefile);

extern int isFileEmpty(char *filename);
// create list of files
extern int to_create_list_of_files(Flist **f_head, char *filename);




#endif

