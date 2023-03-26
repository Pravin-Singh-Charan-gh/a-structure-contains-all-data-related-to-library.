#include <stdio.h>
#include <string.h>
struct library {
    int acno;
    char title[20];
    char author[20];
    int price;
    int flag;
}; //acno=accession number
struct library book[10];
void info()
{
    int serial;
    printf("Enter the serial number of the book(1-10):");
    scanf("%d",&serial);
    printf("Enter accession number, title, name of author, price and enter 1 if the book is issued else enter 0:");
    scanf("%d%s",&book[serial-1].acno,book[serial-1].title);
    while(getchar()!='\n');
    scanf("%s%d%d",book[serial-1].author,&book[serial-1].price,&book[serial-1].flag);
}
void display()
{
    int i;
    char f;
    printf("Enter serial number of book:");
    scanf("%d",&i);
    if(book[i-1].flag==1)
        f='Y';
    else if(book[i-1].flag==0)
        f='N';
    printf("Accession number:%d\nTitle:%s\nAuthor:%s\nPrice:%d\nBook issued:%c\n",book[i-1].acno,book[i-1].title,book[i-1].author,book[i-1].price,f);
}
void list()
{
    char authr[20];
    printf("Enter name of author:");
    scanf("%s",authr);
    for(int i=0; i<10; i++)
        if(strcmp(authr,book[i].author)==0)
            printf("%s\n",book[i].title);
}
void ac_number()
{
    int ac;
    printf("Enter accession number:");
    scanf("%d",&ac);
    for(int i=0; i<10; i++)
        if(book[i].acno==ac)
            printf("%s\n",book[i].title);
}
void count()
{
    int ac,i,a=0;
    printf("Enter accession number of book:");
    scanf("%d",&ac);
    for(int i=0; i<10; i++)
        if(book[i].acno==ac)
            a++;
    printf("Accession number:\nNumber of books:%d\n",a);
}
void orderac()
{
    int a=0,b;
    for(int i=0; i<10; i++)
        if(a<book[i].acno)
            a=book[i].acno;
    for(b=0; b<=a; b++)
        for(int i=0; i<10; i++)
            if(b==book[i].acno)
                printf("%d\n",book[i].acno);
}
int main()
{
    while(1) {
        printf("1. Add book information.\n2. Display book information.\n3. List all books of given author.\n4. List the title of book specified by accession number.\n5. List the counts of books in the library.\n6. List the books in the order of accession number.\n7. Exit.\n");
        int option;
        printf("Choose option:");
        scanf("%d",&option);
        switch(option) {
        case 1:
            info();
            break;
        case 2:
            display();
            break;
        case 3:
            list();
            break;
        case 4:
            ac_number();
            break;
        case 5:
            count();
            break;
        case 6:
            orderac();
            break;
        case 7:
            printf("Thanks! have a nice day.");
            return 0;
        default:
            printf("Unexpected input.");
        }
    }
    return 0;
}
