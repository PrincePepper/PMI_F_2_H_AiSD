//
// Created by semyo on 05.03.2020.
//

#include <stdio.h>


void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void qsort(int *mass, int left, int right) {
    int l = left, r = right;
    int mid = mass[(((l + r) / 2) + l + r) / 3];
    while (l <= r) {
        while (mass[l] < mid)
            l++;
        while (mass[r] > mid)
            r--;
        if (l <= r)
            swap(&mass[l++], &mass[r--]);
    }
    if (left < r)
        qsort(mass, left, r);
    if (right > l)
        qsort(mass, l, right);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0, K = 0;
    fscanf(fin, "%d", &N);
    int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    qsort(mass, 0, N - 1);


    fprintf(fout, "%d ", mass[0]);

}
