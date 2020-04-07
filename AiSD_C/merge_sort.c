//
// Created by semyo on 16.03.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int *merge_sort(int *up, int *down, unsigned int left, unsigned int right) {
    if (left == right) {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right) / 2;

    // разделяй и сортируй
    int *l_buff = merge_sort(up, down, left, middle);
    int *r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    int *target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++) {
        if (l_cur <= middle && r_cur <= right) {
            if (l_buff[l_cur] < r_buff[r_cur]) {
                target[i] = l_buff[l_cur];
                l_cur++;
            } else {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        } else if (l_cur <= middle) {
            target[i] = l_buff[l_cur];
            l_cur++;
        } else {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0, K = 0;
    fscanf(fin, "%d%d", &N, &K);
    int mass[N], mass2[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d", *merge_sort(mass, mass2, 0, N));
    }
}