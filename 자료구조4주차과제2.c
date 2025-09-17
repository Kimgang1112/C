#include <stdio.h>
#include <string.h>


typedef struct {
    char name[20];
    int birthYear;
} Author;


typedef struct {
    char title[30];
    int price;
    Author author;
} Book;

int main() {
    Book b1, b2;

    
    scanf("%s %d %s %d", b1.title, &b1.price, b1.author.name, &b1.author.birthYear);
    
    scanf("%s %d %s %d", b2.title, &b2.price, b2.author.name, &b2.author.birthYear);

   
    Book cheaper = (b1.price < b2.price) ? b1 : b2;

    printf("%s %d %s %d\n", 
           cheaper.title, 
           cheaper.price, 
           cheaper.author.name, 
           cheaper.author.birthYear);

    return 0;
}
