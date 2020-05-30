#ifndef RECORD_H
#define RECORD_H

#define LEN_S 100
#define LEN_P 13
#define SIZE_BOOK 26 //30

static char lit[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЭЮЯ"; 
static char small_letters[] = "abcdefghijklmnopqrstuvwxyz"; //"абвгдеёжзийклмнопрстуфхцчщщъыьэя";
static char big_letters[]   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";



typedef struct record
{
    char name[LEN_S];
    char number[LEN_P];
    struct record * next;

} record;


record** read_book(char *fname, record **book);
int write_book(char *fname, record ** book);
int free_book(record **book);


char* input_string(char* s, int size);
char *get_name(char *name);
char *get_phone(char *phone);
int add_record(record **book);
void insert_rec(record **book, record *new_rec);
record *search_record(record **book, char *name);
int delete_record(record **book, char *name);
int update_record(record **book);

#endif