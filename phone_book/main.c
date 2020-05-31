#include <stdio.h> 
#include "record.h"
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
//#include <windows.h>
//#include <clocale>
 
int main()
{
    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);
    char *locale = setlocale(LC_ALL, "");

    char name_book[LEN_S];
    char name[LEN_S];
    record **book;
    int open_book = 0;   // Открыта ли книга?
    int change_book = 0; // Были изменения в книге?
    
    int m1,m2,m3;

    while(m1 != 3)
    {
        do{
            if (!open_book) printf("> 1 - Доступ\n");
            if (open_book) printf("> 2 - Работа\n");
            printf("> 3 - Завершение\n> ");
            scanf("%d", &m1);
            getchar();
        }while((m1 < 1) || (m1 > 3));


        if(m1 == 1)
        {
            do{
                printf("> 1 - Создать и открыть новую книгу\n");
                printf("> 2 - Открыть\n");
                printf("> 3 - Отказаться\n> ");
                scanf("%d", &m2);
                getchar();
            }while((m2 < 1) || (m2 > 3));
            if (m2 == 1)
            {
                printf("> Введите имя файла книги: ");
                input_string(name_book,LEN_S);
                book = (record**)calloc(sizeof(record*),SIZE_BOOK);
                open_book = 1;
            }
            if (m2 == 2)
            {
                printf("> Введите имя файла книги: ");
                input_string(name_book,LEN_S);
                if (! (book = read_book(name_book,book))) printf("Ошибка чтения файла книги!\n");
                open_book = 1;
            }
        }
        if(m1 == 2)
        {
            do{
                printf("> 1 - Создать запись\n");
                printf("> 2 - Найти/обновить запись\n");
                printf("> 3 - Отказаться\n> ");
                scanf("%d", &m2);
                getchar();
            }while((m2 < 1) || (m2 > 3));
            if (m2 == 1)
            {
                add_record(book);
                change_book = 1;
            }
            if (m2 == 2)
            {
                get_name(name);
                record *rec = search_record(book, name);
                if (rec == NULL) 
                {
                    printf("Запись не найдена!\n");
                }
                else
                {
                    printf("> 1 - Найти номер\n");
                    printf("> 2 - Изменить запись\n");
                    printf("> 3 - Удилить запись\n> ");
                    scanf("%d", &m3);
                    getchar();
                    if (m3 == 1)
                    {
                        fputs(rec->number,stdout);
                        putc('\n',stdout);
                    }
                    if (m3 == 2)
                    {
                        change_book = update_record_rec(rec);
                    }
                    if (m3 == 3)
                    {
                        delete_record(book,name);
                    }
                }
                
            }
        }

        if(m1 == 3)
        {
            if (change_book) 
            {
                printf("> Сохранить ихменения?\n> 1 - YES  other - NO\n> ");
                scanf("%d", &m3);
                getchar();
                if (m3 == 1) write_book(name_book,book);
            }
            else
            {
                printf("> Изменений нет. Завершение.\n");
            }
            free_book(book);
        }   
    }



    



    return 0; 
}
