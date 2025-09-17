#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int kor, eng, math;
} Student;

int main() {
    int N;
    scanf("%d", &N);
    Student students[N];

    int sumKor = 0, sumEng = 0, sumMath = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", students[i].name, 
              &students[i].kor, &students[i].eng, &students[i].math);
        sumKor += students[i].kor;
        sumEng += students[i].eng;
        sumMath += students[i].math;
    }

    double avgKor = (double)sumKor / N;
    double avgEng = (double)sumEng / N;
    double avgMath = (double)sumMath / N;

    for (int i = 0; i < N; i++) {
        if (students[i].kor >= avgKor &&
            students[i].eng >= avgEng &&
            students[i].math >= avgMath) {
            students[i].kor = 100;
            students[i].eng = 100;
            students[i].math = 100;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s %d %d %d\n", students[i].name,
               students[i].kor, students[i].eng, students[i].math);
    }

    return 0;
}
