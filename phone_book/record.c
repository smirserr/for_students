#include "record.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>




record ** read_book(char *fname, record **book)
{
    FILE *f;
    book = (record**)calloc(sizeof(record*),SIZE_BOOK);
    
    f = fopen(fname,"r");
    if (f == NULL) return NULL;
    char name[LEN_S];
    char phone[LEN_S];
    while(fgets(name,LEN_S,f) && fgets(phone,LEN_S,f))
    {
        if (name[strlen(name)-1] == '\n') name[strlen(name)-1] = '\0';
        if (phone[strlen(phone)-1] == '\n') phone[strlen(phone)-1] = '\0';
        record * new_rec = (record*)calloc(sizeof(record),1);
        strcpy(new_rec->name,name);
        strcpy(new_rec->number,phone);

        insert_rec(book,new_rec);
    }
    fclose(f);
    printf("Книга успешно прочитана!\n");
    return book;
}

int write_book(char *fname, record ** book)
{
    if (book == NULL) return 0;
    FILE *f;
    f = fopen(fname,"w");
    if (f == NULL) return 0;
    for(int i = 0; i < SIZE_BOOK; i++)
    {
        record *head = book[i];
        while (head != NULL)
        {
            //fputs(head->name,stdout);
            //fputs(head->number,stdout);
            fputs(head->name,f);
            fputc('\n',f);
            fputs(head->number,f);
            fputc('\n',f);
            head = head->next;
        }
    }
    fclose(f);
    return 1;
}

int free_book(record **book)
{
    if (book == NULL) return 0;
    for(int i = 0; i < SIZE_BOOK; i++)
    {
        record *head = book[i];
        while (head != NULL)
        {
            record * t = head;
            head = head->next;
            free(t);
        }
    }
    return 1;
}


char* input_string(char* s, int size)
{
    fgets(s, size, stdin);
    if (s[strlen(s)-1] == '\n') s[strlen(s)-1] = '\0';
    return s;
}


int find(char *s, char c)
{
    for(int i = 0; s[i] != '\0'; i++)
        if (s[i] == c) return i;
    return -1;
}


char *get_name(char *name)
{   
    printf("Введите фамилию: ");
    int chek; 
    do
    {
        chek = 1;
        name = input_string(name,LEN_P); 
        if (strlen(name) == 0) chek = 0;
        for(int i = 0; (name[i] != '\0') && chek; i++)
        {
            int t = find(small_letters, name[i]);
            if (t != -1) name[i] = big_letters[t];
            t = find(big_letters, name[i]);
            if (t == -1) chek = 0;;
        }
        if (!chek) printf("Недопустимые символы, повторите ввод: ");
    }while(!chek);

    return name;
}

char *get_phone(char *phone)
{   
    printf("Введите телефон: ");
    int chek = 1;
    do
    {
        chek = 1;
        phone = input_string(phone,LEN_P);
        if (strlen(phone) == 0) chek = 0;
        for(int i = 0; (phone[i] != '\0') && chek; i++)
            if ((phone[i] < '0') || (phone[i] > '9')) chek = 0;
        if (!chek) printf("Недопустимые символы, повторите ввод: ");
    }while(!chek);
    
    return phone;
}

int add_record(record **book)
{
    record *new_rec = (record*)calloc(sizeof(record),1);
    if (! get_name(new_rec->name)) return 0;
    if (! get_phone(new_rec->number)) return 0; 
    insert_rec(book,new_rec);
    return 1;
}

void insert_rec(record **book, record *new_rec)
{
    
    int n = find(lit, new_rec->name[0]);
    //printf("!!!! %d\n", n);
    record *head = book[n];
    if (head == NULL) 
    {
        book[n] = new_rec;
        return; 
    }
    while (head->next != NULL) head = head->next;
    head -> next = new_rec; 
    
}

record *search_record(record **book, char *name)
{
    int n = find(lit,name[0]);
    record *head = book[n];
    if (head == NULL) return NULL; 
    while ((head != NULL) && strcmp(head->name,name)) head = head->next;
    return head; 
}

int delete_record(record **book, char *name)
{
    int n = find(lit,name[0]);
    record *head = book[n];
    if (head == NULL) return 0;
    if(head->next == NULL) 
    {
        if (! strcmp(head->name,name)) 
        {
            free(head);
            book[n] = 0;
            return 1;
        }
    }
    while((head->next != NULL) && strcmp(head->next->name,name)) head = head->next;
    if (head->next == NULL) return 0;
    record * t = head->next->next;
    free(head->next);
    head->next = t;
    return 1;
}

int update_record(record **book)
{
    char *name;
    char *number;
    if (! get_name(name)) 
    {
        printf("Запись не найдена, прерывание.\n");
        return 0;
    }
    record * rec = search_record(book,name);
    if (rec == NULL) return 0;
    while (! get_phone(number))
    {
        printf("Некорректный номер! Повторите ввод:\n");
    } 
    strcpy(rec->number,number);
    return 1;
}
