//
// Created by User on 10.05.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


long long k_statistik(vector<long long int> &mass, long long int left, long long int right, long long int k) {
    long long int x = mass[(left + right) / 2];
    long long int i = left, j = right;
    while (i <= j) {
        while (mass[i] < x) i++;
        while (mass[j] > x) j--;

        if (i <= j) {
            swap(mass[i], mass[j]);
            i++;
            j--;
        }
    }
    if (left <= k && k <= j) return k_statistik(mass, left, j, k);
    if (i <= k && k <= right) return k_statistik(mass, i, right, k);
    return mass[k];
}

//int k_statistik(vector<long long int> &mass, long long int n, long long int k) {
//    long long int l = 0, r = n-1;
//    while (true) {
//        if (r <= l + 1) {
//            // текущая часть состоит из 1 или 2 элементов -
//            //	 легко можем найти ответ
//            if (r == l + 1 && mass[r] < mass[l])
//                swap(mass[l], mass[r]);
//            return mass[k];
//        }
//
//        // упорядочиваем mass[l], mass[l+1], mass[r]
//        long long int mid = (l + r) >> 1;
//        swap(mass[mid], mass[l + 1]);
//        if (mass[l] > mass[r])
//            swap(mass[l], mass[r]);
//        if (mass[l + 1] > mass[r])
//            swap(mass[l + 1], mass[r]);
//        if (mass[l] > mass[l + 1])
//            swap(mass[l], mass[l + 1]);
//
//        // выполняем разделение
//        // медианой является mass[l+1], т.е. медиана среди mass[l], mass[l+1], mass[r]
//        long long int y = l + 1, x = r;
//        long long int cur = mass[l + 1];
//
//        while (true) {
//            while (mass[++y] < cur);
//            while (mass[--x] > cur);
//            if (y > x)
//                break;
//            swap(mass[y], mass[x]);
//        }
//
//        // вставляем медиану
//        mass[l + 1] = mass[x];
//        mass[x] = cur;
//
//        // продолжаем работать в той части, которая должна содержать искомый элемент
//        if (x >= k)
//            r = x - 1;
//        if (x <= k)
//            l = y;
//
//    }
//}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    long long int N, K, temp = 0;
    fin >> N >> K;
    vector<long long int> mass(N);
    for (long long int i = 0; i < N; i++) {
        fin >> temp;
        mass[i] = temp;
    }
    fout << k_statistik(mass, 0, N, K - 1);
//    fout << k_statistik(mass, N, K-1);
}