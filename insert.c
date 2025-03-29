#include "inverted_search.h"

//insert the at last 
void insert_LT(Link_table** head, data_t* file_count, const char* filename)
{
    //Create a new node
    Link_table* new = malloc(sizeof(Link_table));
    //Check if new node is created
    if (new == NULL)
    {
        printf("ERROR: Unable to allocate dynamic memory!\n\n");
        exit(SUCCESS);
    }
    //Check if head is NULL
    if (*head == NULL)
    {
        //Update new node data
        new -> word_count = 1;
        strcpy(new -> filename, filename);
        new -> link_table = NULL;
        *head = new;
        return;
    }

    //A temp pointer to iterate over the list. Initialize with head address
    Link_table* temp = *head;
    while (temp -> link_table)
    {
        if (temp != *head)
        {
            //Check if the word is found in the same file. If so, increment word count. Otherwise create a new node
            if (!strcmp(filename, temp -> filename))
            {
                //Increment word count and return
                ++(temp -> word_count);
                return;
            }
        }
        temp = temp -> link_table;
    }
    //Check if the last node contains the same filename. Note that it could be head node as well.	
    if (!strcmp(filename, temp -> filename))
    {
        //Increment word count and return
        ++(temp -> word_count);
        return;
    }

    ++(*file_count);
    //Create a new node and update temp node's link
    Link_table* newNode = malloc(sizeof(Link_table));
    //Check if new node is created
    if (newNode == NULL)
    {
        printf("ERROR: Unable to allocate dynamic memory!\n\n");
        exit(SUCCESS);
    }
    //Update new node data
    newNode -> word_count = 1;
    strcpy(newNode -> filename, filename);
    newNode -> link_table = NULL;
    //Establish link between temp node and new node
    temp -> link_table = newNode;
}
