
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int element_compare(const void *p1, const void *p2);
double* random_num(int size);

int main(void)
{
    int size = 100;

    srand((unsigned int)time(NULL));

    double *test = random_num(size);

    printf("\nSorterede tal:\n");

    qsort(test, size, sizeof(double), element_compare);

    for (int i = 0; i < size; i++) {
        printf("%f\n", test[i]);
    }

    free(test);

    return 0;
}

double* random_num(int size)
{
    double *test = malloc(size * sizeof(double));

    if (test == NULL) {
        printf("System error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        test[i] = (double)rand() / RAND_MAX * 100.0;
        printf("%f\n", test[i]);
    }

    return test;
}

int element_compare(const void *p1, const void *p2)
{
    double ip1 = *(const double *)p1;
    double ip2 = *(const double *)p2;

    if (ip1 < ip2) {
        return -1;
    } else if (ip1 > ip2) {
        return 1;
    } else {
        return 0;
    }
}
