#include "inverted_search.h"

/*Functions used to update the database in sorted manner*/

//function to insert after 
void insert_after(Database_t** head, const char* word, const char* new_word, const char* filename)
{
    Database_t* current = *head;
    while (current)
    {
        if(!strcasecmp(current -> word, word))
        {
            //Create a new node
            Database_t* new = malloc(sizeof(Database_t));
            //Check whether memory is allocated
            if (new == NULL)
            {
                printf("Error: Unable to allocate dynamic memory!\n\n");
                exit(SUCCESS);
            }
            //Update new node data
            new -> file_count = 1;
            strcpy(new -> word, new_word);
            insert_LT(&(new -> link_table), &(new -> file_count), filename);
            //Establish link between new node and next node
            new -> link = current -> link;
            //Update current node's link
            current -> link = new;
            return;
        }
        current = current -> link;
    }
    printf("Data not found in the list!\n");
    return;
}

//Function to insert at first
void insert_at_first(Database_t** head, const char* word, const char* filename)
{
    //Create a new node
    Database_t* new = malloc(sizeof(Database_t));
    //Check if node is created or not
    if (new == NULL)
    {
        printf("Error: Unable to allocate dynamic memory!\n\n");
        return;
    }
    //Update the data
    new -> file_count = 1;
    strcpy(new -> word, word);
    insert_LT(&(new -> link_table), &(new -> file_count), filename);
    //Establish a link between first and next node + update head pointer
    new -> link = *head;
    *head = new;
    return;
}
 
void insert_into(Existing_Files_t** head, const char* filename)
{
    //Create a new node
    Existing_Files_t* new = malloc(sizeof(Existing_Files_t));
    //Check if node is created or not
    if (new == NULL)
    {
        printf("Error: Unable to allocate dynamic memory!\n\n");
        return;
    }
    //Update the data
    strcpy(new -> filename, filename);
    //Establish a link between first and next node + update head pointer
    new -> link = *head;
    *head = new;
    return;
}

