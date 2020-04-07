//
// Created by semyo on 05.03.2020.
//
#include <stdio.h>


int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0, temporary = 0;
    int mass[3000] = {0};
    fscanf(fin, "%d", &N);
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (mass[j] < mass[i]) {
                temporary = mass[i];
                mass[i] = mass[j];
                mass[j] = temporary;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", mass[i]);
    }
}
