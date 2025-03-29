#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <libgen.h>

typedef int data_t;

/* Macros */
#define NO_OF_ALPHABETS                  26
#define HASH_FUNCTION(DATA, LETTER)      (DATA % LETTER)
#define MAX_WORD_SIZE                    30
#define MAX_FILENAME_SIZE                80
#define DEBUG_ON                         0

/* Structure declarations */
//A structure to maintain link table
typedef struct LT_t
{
		data_t word_count;
		char filename[MAX_FILENAME_SIZE];
		struct LT_t* link_table;
}Link_table;

//A structure to maintain the database
typedef struct DB_t
{
		data_t file_count;
		char word[MAX_WORD_SIZE];
		Link_table* link_table;
		struct DB_t* link;
}Database_t;

//A structure to maintain a Hash table of Alphabets
typedef struct node
{
		data_t key;
		char value;
		Database_t* head;
}Hash_albha_t;

//A link list to keep track of existing files in the database
typedef struct ExF
{
		char filename[MAX_FILENAME_SIZE];
		struct ExF* link;
}Existing_Files_t;

/* Enum declaration for getting Status from functions */
typedef enum
{
		FAILURE,
		SUCCESS
}Status;

/* Function prototypes */

void create_database(FILE* fptr[], Hash_albha_t head_index[], char* argv[], data_t no_of_files);
void insert_into(Existing_Files_t** head, const char* filename);
Status is_existing_file(Existing_Files_t* head, const char* filename);
void insert_sorted_DB(const char* word, Database_t** head, const char* filename);
void insert_LT(Link_table** head, data_t* file_count, const char* filename);
void search_word(Hash_albha_t head_index[], const char* word);
Status verify_and_open_input_files(FILE* fptr[], char* argv[], data_t no_of_files);
void print_list(Database_t* head);
void display_database(Hash_albha_t head_index[]);
void update_database(Hash_albha_t head_index[], data_t argc, char* argv[], Existing_Files_t** head);
void insert_at_first(Database_t** head, const char* word, const char* filename);
void insert_after(Database_t** head, const char* word, const char* new_word, const char* filename);
void save_database(Hash_albha_t head_index[], Existing_Files_t* head);

