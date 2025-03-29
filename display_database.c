#include "inverted_search.h"

//function to display the database
void display_database(Hash_albha_t head_index[])
{
    //A flag to check if database is empty
    data_t db_empty = 1;
    for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if (head_index[i].value != '#')
        {
            db_empty = 0;
            printf("\n----------------------------------------\n");
            
            //Print the index at which word is stored
            printf("#[%d]: ", tolower(head_index[i].value) % 97);
            Database_t* head = head_index[i].head;
            while (head)
            {
                if (head != head_index[i].head)
                    printf("   : ");
                printf("%s : Appeared in %d file(s)", head -> word, head -> file_count);
                Link_table* hd = head -> link_table;
                while (hd)
                {
                    printf(" : %s : %d time(s) #\n", hd -> filename, hd -> word_count);
                    hd = hd -> link_table;
                }
                head = head -> link;
            }
        }
    }
    if (db_empty)
        printf("\nDatabase is empty\n\n");
    else
        printf("----------------------------------------\n\n");
}
