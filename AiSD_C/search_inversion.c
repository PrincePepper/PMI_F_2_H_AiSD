//
// Created by semyo on 25.03.2020.
//
#include <stdio.h>
#include <math.h>

int count = 0;

/*
int *merge_sort(int *up, int *down, int left, int right) {
    if (left == right) {
        down[left] = up[left];
        return down;
    }

    int middle = (left + right) / 2;

    // разделяй и сортируй
    int *l_buff = merge_sort(up, down, left, middle);
    int *r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    int *target = l_buff == up ? down : up;

    int l_cur = left, r_cur = middle + 1;
    for (int i = left; i <= right; i++) {
        if (l_cur <= middle && r_cur <= right) {
            if (l_buff[l_cur] < r_buff[r_cur]) {
                target[i] = l_buff[l_cur];
                count = count + 1+l_cur-r_cur;
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
    printf("%d ",count);
    return target;
}

*/

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
        while (mass[l] > mid)
            l++;
        while (mass[r] < mid)
            r--;
        if (l <= r)
            swap(&mass[l++], &mass[r--]);
    }
    if (left > r)
        qsort(mass, left, r);
    if (right < l)
        qsort(mass, l, right);
}

int inversion(int *mass, int len) {
    int result = 0;
    int time_mass[len + 1];
    qsort(mass, 0, len - 1);
    int rank[mass[0]];
    for (int i = 0; i < mass[0]; i++) {
        rank[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int x = rank[i] - 1;
        while (x >= 0) {
            result += time_mass[x];
            x -= x & -x;
        }
        x = rank[i];
        while (x <= len) {
            time_mass[x] += 1;
            x += x & -x;
        }
    }
    return result;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;
    fscanf(fin, "%d", &N);
    int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }
    inversion(mass, N);
}