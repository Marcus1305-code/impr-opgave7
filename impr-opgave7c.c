#include <stdio.h>
#include <stdlib.h>

void input(int barcode[]);
//int* createArray();
int check(int sum);
int calcalute_odd(int barcode[]);
int calcalute_even(int odd_sum, int barcode[]);
int control_of_last_digigt(int barcode[], int check_digit);

int main() {   

    int* barcode = malloc(sizeof(int) * 12);
    if (barcode == NULL) {
        return 1;
    }
    input(barcode);

    int odd_sum, check_digigt, sum, control_digit;

    odd_sum = calcalute_odd(barcode);
    sum = calcalute_even(odd_sum, barcode);
    check_digigt = check(sum);
    control_digit = control_of_last_digigt(barcode, check_digigt);
    printf("odd sum: %d\n", odd_sum);
    printf("sum: %d\n", sum);
    printf("check digit: %d\n", check_digigt);
    printf("control af last digit: %d\n 1 betyder sand og 0 falsk", control_digit);
    free(barcode);
    return 0;
}
void input(int barcode[]) {
    printf("indtast barcode på en længde af 12\n");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &barcode[i]);
    }
}
/*
int* createArray() {
   /* int* array = malloc(sizeof(int) * 12);
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < 12måske skal det faktisk kun være en gang; i++) {
        array[i] = input();
        printf("barcode: %d", array[i]);
    }
    return array;
}
*/
int calcalute_odd(int barcode[]) {
    int odd_sum = 0;
    for (int i = 0; i < 11; i += 2) {
        odd_sum += barcode[i];
    }
    return odd_sum * 3;
}
int calcalute_even(int odd_sum, int barcode[]) {
    int sum = 0;
    for (int i = 1; i < 11; i += 2) {
        sum += barcode[i];
    }
    return sum += odd_sum;;
}
int check(int sum) {
    int check_digit = 0;
    int digigt = sum % 10;
    if (digigt == 0) {
        check_digit = 0;
    } else {
        check_digit = 10 - digigt;
    }
    return check_digit;
}
int control_of_last_digigt(int barcode[], int check_digit) {
    int last_digigt = barcode[11];

    if (last_digigt == check_digit) {
        printf("the UPC proces is right");
        return 1;
    } else {
        printf("the value of the last digit is not the same as the check value");
        return 0;
    }
}