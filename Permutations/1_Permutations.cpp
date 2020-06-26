//
// Created by User on 25.05.2020.
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<bool> visited_v(100);
vector<int> set(100);

void combi_repeat(int n, int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << set[i]<<" ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited_v[i]) {
            visited_v[i] = true;
            set[k] = i;
            combi_repeat(n, k + 1);
            visited_v[i] = false;
        }

    }

}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int N = 0;
    fin >> N;
    combi_repeat(N, 0);
}
