/*------------------------------------------------------
Name            :Akanksha Walke
Date            :22/10/2021
Description     :Inverted search project
Input           :./inverted_search.h file1.txt
Output          :Select the option
                 1.Create Database
                 2.Display database
                 3.Search word
                 4.Update database
                 5.Save database
                 6.Exit
                 1
                 Successfully created the database!
------------------------------------------------------*/

#include "inverted_search.h"

int main(int argc, char* argv[])
{
 
    //Check if filenames are provided or not
    if (argc == 1)
    {
        printf("ERROR: No filename provided from command line. Please pass filename/s to perform inverted search operations.\n\n");
        exit(SUCCESS);
    }
    
    //Trace the no. of input files provided from command line
    data_t no_of_input_files = argc - 1;
    
    //Creating an array of file pointers
    FILE* file_pointer[no_of_input_files];
    
    //Validate filenames
    if (!verify_and_open_input_files(file_pointer, argv, no_of_input_files))
    {
        printf("\nPlease try again...\n\n");
        exit(SUCCESS);
    }
    
    //Create database of existing filenames
    Existing_Files_t* head = NULL;
    for (data_t i = 1; i < argc; i++)
    {
        insert_into(&head, argv[i]);
    }
    
    //Create a Hash table which maintains alphabetical order
    Hash_albha_t head_index[NO_OF_ALPHABETS];
    
    //Initializing Hash table with indices 0 to 25
    for (data_t i = 0; i < NO_OF_ALPHABETS; i++)
    {
        head_index[i].key = i;//Index
        head_index[i].value = '#';//Initialize all values to '#'
        head_index[i].head = NULL;//Initialize each node's link to NULL
    }
    
    //User would select an option from given menu & a flag to check if Database is already created
    data_t opt, db_created = 0;
    
    //To store word to be searched
    char word[MAX_WORD_SIZE];
    
    while(1)
    {
        printf("Select the option\n1.Create Database\n2.Display database\n3.Search word\n4.Update database\n5.Save database\n6.Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1: //Create database
                    if (db_created)
                        printf("\nDatabase has been already created!!\n\n");
                    else
                    {
                        //Calling the function to create database
                        create_database(file_pointer, head_index, argv, no_of_input_files);
                        printf("\nSuccessfully created the database!\n\n");
                        db_created = 1;
                    }
                    break;
            case 2: //Display the database
                    if (db_created)
                        display_database(head_index);
                    else
                        printf("\nDatabase has not been created yet! first create a database\n\n");
                    break;
            case 3: //Search a word
                    if (db_created)
                    {
                        printf("\nEnter the word you want to search: ");
                        scanf("%s", word);
                        search_word(head_index, word);
                    }
                    else
                        printf("\nDatabase has not been created yet! first create a database!\n\n");
                    break;
            case 4: //Update database
                    if (db_created)
                        update_database(head_index, argc, argv, &head);
                    else
                        printf("\nDatabase has not been created yet! first create a database\n\n");
                    break;
            case 5: //Save database
                    if (db_created)
                        save_database(head_index, head);
                    else
                        printf("\nDatabase has not been created yet! first create a database !\n\n");
                    break;
            case 6: //Exiting from while loop
                    return 0;
            default: //Invalid option
                    printf("ERROR: Invalid option selected!\n\n");
        }
    }

    //Close all the files and exit from the program
    for (data_t i = 0; i < no_of_input_files; i++)
    {
        fclose(file_pointer[i]);
    }
        
    return 0;
}
