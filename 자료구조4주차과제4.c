#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int main() {
    Point p1, p2;
    Point *a = &p1, *b = &p2;

    scanf("%d %d", &a->x, &a->y);
    scanf("%d %d", &b->x, &b->y);

    double distance = sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));

    printf("%.2f\n", distance);

    return 0;
}
