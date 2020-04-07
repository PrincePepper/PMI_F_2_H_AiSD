#include <stdio.h>

void swap(long int *a, long int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int k_statistik(long int *mass, long int right, long int k) {
    right--;
    long int left = 0;
    while (1) {

        if (right <= left + 1) {    //если в массиве всего 1 или 2 элемента то или меняем или сразу выводим его
            if (right == left + 1 && mass[right] < mass[left])
                swap(&mass[left], &mass[right]);
            return mass[k - 1];
        }

        // упорядочиваем mass[left], mass[left+1], mass[right]
        long int mid = (left + right) / 2;
        swap(&mass[mid], &mass[left + 1]);
        if (mass[left] > mass[right])
            swap(&mass[left], &mass[right]);
        if (mass[left + 1] > mass[right])
            swap(&mass[left + 1], &mass[right]);
        if (mass[left] > mass[left + 1])
            swap(&mass[left], &mass[left + 1]);

        // медианой является mass[left+1], среди mass[left], mass[left+1], mass[right]
        long int i = left + 1, j = right;
        long int cur = mass[left + 1];
        while (1) {
            while (mass[++i] < cur);
            while (mass[--j] > cur);
            if (i > j)
                break;
            swap(&mass[i], &mass[j]);
        }

        // передвигаем медиану в сторону где находится наш k элемент
        mass[left + 1] = mass[j];
        mass[j] = cur;

        // продолжаем работать в той части, которая должна содержать искомый элемент
        if (j >= k)
            right = j - 1;
        if (j <= k)
            left = i;

    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0, K = 0;
    fscanf(fin, "%d%d", &N, &K);
    long int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%ld", &mass[i]);
    }
    fprintf(fout, "%d", k_statistik(mass, N, K));

}