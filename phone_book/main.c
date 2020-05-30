#include <stdio.h> 
#include "record.h"
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

//  #include <clocale>
 
int main()
{
    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);
    char *locale = setlocale(LC_ALL, "");

    char name_book[LEN_S];
    record **book;

    
    int m1,m2;

    while(m1 != 3)
    {
        do{
            printf("1 - Доступ\n");
            printf("2 - Работа\n");
            printf("3 - Завершение\n");
            scanf("%d", &m1);
            getchar();
        }while((m1 < 1) || (m1 > 3));


        if(m1 == 1)
        {
            do{
                printf("1 - Создать и открыть новую книгу\n");
                printf("2 - Открыть\n");
                printf("3 - Отказаться\n");
                scanf("%d", &m2);
                getchar();
            }while((m2 < 1) || (m2 > 3));
            if (m2 == 1)
            {
                printf("Введите имя файла книги: ");
                input_string(name_book,LEN_S);
                book = (record**)calloc(sizeof(record*),SIZE_BOOK);

            }
            if (m2 == 2)
            {
                printf("Введите имя файла книги: ");
                input_string(name_book,LEN_S);
                if (! (book = read_book(name_book,book))) printf("Ошибка чтения файла книги!\n");
            }
        }
        if(m1 == 2)
        {
            do{
                printf("1 - Создать запись\n");
                printf("2 - Найти/обновить запись\n");
                printf("3 - Отказаться\n");
                scanf("%d", &m2);
                getchar();
            }while((m2 < 1) || (m2 > 3));
            if (m2 == 1)
            {
                add_record(book);
            }
            if (m2 == 2)
            {

            }
        }
        if(m1 == 3)
        {
            if (book != NULL) write_book(name_book,book);
        }
    }



    


   /*

    add_record(book);
    add_record(book);
    add_record(book);

    for(int i = 0; i < SIZE_BOOK; i++)
    {
        printf("%c\n", lit[i]);
        if(book[i] == NULL) printf("...\n\n");
        else
        {
            record * head = book[i];
            while(head != NULL)
            {
                
                puts(head->name);
                puts(head->nubber);
                head = head->next;
            }
        } 
        printf("----------------------\n");
    }
    */

    return 0; 
}
