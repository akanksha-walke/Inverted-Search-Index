#include "inverted_search.h"

//function to create database
void create_database(FILE* fptr[], Hash_albha_t head_index[], char* argv[], data_t no_of_files)
{

    //A string to store every word from the files
    char getword[MAX_WORD_SIZE];
    //traverse
    for (data_t i = 0; i < no_of_files; i++)
    {
        //Fetch every character from the file
        char ch;
        //key to get the alphabetical index of the word
        data_t alphabet_found = FAILURE, j = 0, key;
        
        //Iterate from the file till EOF
        while ((ch = fgetc(fptr[i])) != EOF)
        {
            //If an alphabet is found
            if (isalpha(ch))
            {
                //Put the character in the getword string and increment its index
                getword[j++] = ch;
                //If the alphabet is found the 1st time or if it is found after a non-alphabet character, assign SUCCESS value to flag
                if (!alphabet_found)
                    alphabet_found = SUCCESS;
            }
            //Check if non-alphabet character 
            else if (!isalpha(ch) && alphabet_found)
            {
             
                getword[j] = '\0';
                //Update Hash index based on 1st character in the word
                key = HASH_FUNCTION(tolower(getword[0]), 'a');
                head_index[key].key = key;
                //Update letter in the hash table
                head_index[key].value = tolower(getword[0]);
                
                //Update Database Linked list
                insert_sorted_DB(getword, &(head_index[key].head), *(argv + i + 1));
                alphabet_found = FAILURE;

                j = 0;
            }
        }
    }
}

//Function to print the list and create database
void print_list(Database_t* head)
{
		//Check if head is empty
		if (head == NULL)
		{
				printf("\nList is empty\n\n");
				return;
		}
		printf("\n---------Printing Database---------\n");
		//Iterate through the linked list
		while (head)
		{
				//Print filecount and the stored word
				printf("file_count = %d : word = %s\n", head -> file_count, head -> word);
				//Print Link Table
				Link_table* hd = head -> link_table;
				//Check if link_table is empty
				if (hd == NULL)
				{
						printf("\nList is empty\n\n");
						return;
				}
				while (hd)
				{
						//Print word count and the stored filename
						printf("word_count = %d : filename = %s\n", hd -> word_count, hd -> filename);
						hd = hd -> link_table;
				}
				printf("\n");
				head = head -> link;
		}
		printf("\n");
}

