#include "inverted_search.h"

//Function to update database
void update_database(Hash_albha_t head_index[], data_t argc, char* argv[], Existing_Files_t** head)
{
    //take a file pointer
    FILE* fptr_new[1] = {NULL};
    //Store new_filename as 1st argument
    printf("\nEnter the filename: ");
    scanf("%s", argv[1]);
    
    //Verify and open this file
    if (verify_and_open_input_files(fptr_new, argv, 1))
    {
        //This is new file. Insert its name into existing database
        insert_into(head, argv[1]);

        //Call create database function so that database gets updated.
        create_database(fptr_new, head_index, argv, 1);
        printf("Successfully verified the file and updated the database!\n\n");
    }
    else
        fprintf(stderr, "ERROR: Please use valid filename \n\n");
    //Close the file if opened
    if (fptr_new[0])
        fclose(fptr_new[0]);
}

