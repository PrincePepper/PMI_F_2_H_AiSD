#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void heapUp(int pos, int *mass) {
    while (pos > 0 && mass[(pos - 1) / 2] < mass[pos]) {
        swap(mass[(pos - 1) / 2], mass[pos]);
        pos = (pos - 1) / 2;
    }
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("heapsort.in");
    fout.open("heapsort.out");
    long long int N;
    fin >> N;
    int mass[N];
    int size = 0;
    for (int i = 2; i <= N; i++) {
        mass[size] = i;
        heapUp(size++, mass);
    }
    mass[size] = 1;
    for (int i = 0; i < N; i++) {
        fout << mass[i] << " ";
    }
}