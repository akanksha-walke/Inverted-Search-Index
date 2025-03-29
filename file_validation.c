#include "inverted_search.h"

//check if file exists
Status is_existing_file(Existing_Files_t* head, const char* filename)
{
    while(head)
    {
        if (!strcmp(head -> filename, filename))
            return SUCCESS;
        head = head -> link;
    }
    return FAILURE;
}

//Verify the file and open the file for operations to be performed
Status verify_and_open_input_files(FILE* fptr[], char* argv[], data_t no_of_files)
{
    //An error flag to know if there is any error
    data_t error_flag = 0;
    char filename[MAX_FILENAME_SIZE];
    for (data_t i = 0; i < no_of_files; i++)
    {
        //Extract only filename from given path if any
        strcpy(*(argv + i + 1), basename(*(argv + i + 1)));
        if ((fptr[i] = fopen((const char*)*(argv + i + 1), "r")) == NULL)
        {
            perror("fopen");
            fprintf(stderr, "ERROR: Unable to open file: %s. This file may not be present in the current working directory.\n", *(argv + i + 1));
            error_flag = 1;
        }
    }
    return (error_flag) ? FAILURE: SUCCESS;
}
