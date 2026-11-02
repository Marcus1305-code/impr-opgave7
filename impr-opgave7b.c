#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* roll_multiple_dies(int n);
void input(int* size);

int main() {
    srand(time(NULL));
    int size;
    int count = 1;
    input(&size);

    //lav en funktion på bag grund af size en størrelse af et array med random værdier
    printf("kast: %d\n", count);
    int *num_of_throws = roll_multiple_dies(size);    
    
    for (int i = 0; i < 9; i++) {
        count++;
        printf("kast: %d\n", count);
        roll_multiple_dies(size);
    }
    free(num_of_throws);
    return 0;
}
// n antal terning kast
int* roll_multiple_dies(int n) {
    int *num_of_throws = malloc(sizeof(int) * n);
    
    if (num_of_throws == NULL) {
        printf("System error\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        num_of_throws[i] = (rand() % 6)+1;
        printf("%d\n", num_of_throws[i]);
    }
    return num_of_throws;

}
void input(int* size) {
    printf("valg antal kast\n");
    scanf("%d", size);
}