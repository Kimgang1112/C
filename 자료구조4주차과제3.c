#include <stdio.h>
#include <string.h>

typedef struct {
    int year, month, day;
} Date;

typedef struct {
    char name[30];
    int id;
    Date hire;
} Employee;


int isEarlier(Date a, Date b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main() {
    Employee emp[3];
    for (int i = 0; i < 3; i++) {
        scanf("%s %d %d %d %d", emp[i].name, &emp[i].id, 
              &emp[i].hire.year, &emp[i].hire.month, &emp[i].hire.day);
    }

   
    int idx = 0;
    for (int i = 1; i < 3; i++) {
        if (isEarlier(emp[i].hire, emp[idx].hire)) {
            idx = i;
        }
    }

    printf("%s %d %04d-%02d-%02d\n", emp[idx].name, emp[idx].id,
           emp[idx].hire.year, emp[idx].hire.month, emp[idx].hire.day);

    return 0;
}
