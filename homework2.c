// Copyright 2023 Gasan Emirgamzaev emirgamzaevsan@gmail.com


#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aads.h"


// Дан массив 𝑎 размера 𝑛 , состоящий из натуральных чисел, и число 𝑚 ≤ 𝑛 . Для
//каждого участка из 𝑚 стоящих рядом членов (а таких участков 𝑛 − 𝑚 + 1 ) вычислить его
//сумму.

int sum = 0;
void neighbourSum(int *array, int n, int m) {
    for (size_t x = 0; x < n - m; ++x) {
        for (size_t j = x; j == x*m; ++j) {
            sum += array[j];
        }
        array[x] = sum;
        sum = 0;
    }
}


int main() {


    int array[] = {1,2,3,4};
    int n = 4;
    int m = 2;
    for (size_t x =0; x < n; ++x) {
        printf("%d",array[x]);
    }
}