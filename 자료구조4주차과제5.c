#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int score;
} Student;

int main() {
    int N;
    scanf("%d", &N);

    Student *students = (Student *)malloc(N * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int sum;
    sum=0;
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
        sum=sum;
        sum += students[i].score;
    }

    double avg = (double)sum / N;
    printf("%.2f\n", avg);

    free(students);
    return 0;
}
