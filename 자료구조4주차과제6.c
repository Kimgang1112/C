#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int kor, eng, math;
} Student;


void bubble_sort(Student *a, int *b,int n){
    for (int j=0; j<n-1; j++){
        for (int i=0; i<n-j-1; i++){
            if (b[i]<b[i+1]){
                int temp=b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
                Student student=a[i];
                a[i]=a[i+1];
                a[i+1]=student;
            } else if(b[i]==b[i+1]){
                if (strcmp(a[i].name,a[i+1].name)>0){
                    Student student=a[i];
                    a[i]=a[i+1];
                    a[i+1]=student;
                }
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Student students[N];
    int arr[N];
    

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", students[i].name, 
              &students[i].kor, &students[i].eng, &students[i].math);
        arr[i]=students[i].kor+students[i].eng+students[i].math;
        
    }

    

    for (int i = 0; i < N; i++) {
        bubble_sort(students,arr,N);
    }

    for (int i = 0; i < N; i++) {
        printf("%s %d %d %d\n", students[i].name,
               students[i].kor, students[i].eng, students[i].math);
    }

    return 0;
}
