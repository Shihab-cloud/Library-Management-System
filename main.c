#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

void menu_h(void);
void splash_h (void);
void login_h(void);
void addBook(void);
void booksList(void);
void del(void);
void issueBook(void);
void issueList(void);


struct books
{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;

struct student
{
    int id;
    char sName[50];
    char sSemester[50];
    int sId;
    char bookName[50];
    char date[12];
}s;

FILE *fp;

int main(void)
{

    splash_h();

    login_h();

    meun_h();

       int ch;


    while(1)
    {
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

        switch(ch)
        {
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

void splash_h (void)
{

    printf(" __    _ _                      _____                                   _      _____         _             \n");
    printf("|  |  |_| |_ ___ ___ ___ _ _   |     |___ ___ ___ ___ ___ _____ ___ ___| |_   |   __|_ _ ___| |_ ___ _____ \n");
    printf("|  |__| | . |  _| .'|  _| | |  | | | | .'|   | .'| . | -_|     | -_|   |  _|  |__   | | |_ -|  _| -_|     |\n");
    printf("|_____|_|___|_| |__,|_| |_  |  |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|    |_____|_  |___|_| |___|_|_|_|\n");
    printf("                        |___|                    |___|                              |___|                  \n");



    sleep(5);
    system("cls");

}

void login_h(void)
{

    char username[15];
    char password[12];


    printf("Enter your username:\n");
    scanf("%s",&username);

    printf("Enter your password:\n");
    scanf("%s",&password);

    if(strcmp(username,"Shihab")==0)
    {
        if(strcmp(password,"123")==0)
        {

            printf("\nWelcome.Login Success!");


        }
        else
        {
            printf("\nwrong password");
            sleep(5000);
        }
    }
    else
    {
        printf("\nUser doesn't exist");
        sleep(5000);
    }
     sleep(3);

     system("cls");
}

void addBook(void)
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt", "ab");

    printf("Enter book id: ");
    scanf("%d", &b.id);

    printf("Enter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("Enter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("Book Added Successfully");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}


void booksList(void)
{

    system("cls");
    printf("<== Available Books ==>\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");

    fp = fopen("books.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);
    }

    fclose(fp);
}

void del(void)
{
    int id, f=0;
    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        if(id == b.id)
        {
            f=1;
        }
        else
        {
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if(f==1)
    {
        printf("\n\nDeleted Successfully.");
    }
    else
    {
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

}


void issueBook(void)
{

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int f=0;

    system("cls");
    printf("<== Issue Books ==>\n\n");

    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);


    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        if(b.id == s.id)
        {
            strcpy(s.bookName, b.bookName);
            f=1;
            break;
        }
    }

    if(f==0)
    {
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf("Enter Student Semester: ");
    fflush(stdin);
    gets(s.sSemester);

    printf("Enter Student ID: ");
    scanf("%d", &s.sID);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void issueList(void)
{
    system("cls");
    printf("<== Book Issue List ==>\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "B.id", "Name", "Semester", "ID", "Book Name", "Date");

    fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", s.id, s.sName, s.sSemester, s.sId, s.bookName, s.date);
    }

    fclose(fp);
}


