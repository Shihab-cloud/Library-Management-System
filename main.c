#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu_h(void);
void splash_h (void);
void login_h(void);
void addBook(void);
void booksList(void);
void del(void);
void issueBook(void);
void issueList(void);


struct books{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;

struct student{
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
}s;

FILE *fp;

int main(void){

    splash_h();

    login_h();

    meun_h();

       int ch;


    while(1){
        system("cls");
        printf("<== Library Management System ==>\n");
        printf("1.Add Book\n");
        printf("2.Books List\n");
        printf("3.Remove Book\n");
        printf("4.Issue Book\n");
        printf("5.Issued Book List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            addBook();
            break;

        case 2:
            booksList();
            break;

        case 3:
            del();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            issueList();
            break;

        default:
            printf("Invalid Choice...\n\n");

        }
        printf("Press Any Key To Continue...");
        getch();
    }


       return 0;
}

void splash_h (void){

printf(" __    _ _                      _____                                   _      _____         _             \n");
printf("|  |  |_| |_ ___ ___ ___ _ _   |     |___ ___ ___ ___ ___ _____ ___ ___| |_   |   __|_ _ ___| |_ ___ _____ \n");
printf("|  |__| | . |  _| .'|  _| | |  | | | | .'|   | .'| . | -_|     | -_|   |  _|  |__   | | |_ -|  _| -_|     |\n");
printf("|_____|_|___|_| |__,|_| |_  |  |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|    |_____|_  |___|_| |___|_|_|_|\n");
printf("                        |___|                    |___|                              |___|                  \n");



sleep(5);
system("cls");

}
