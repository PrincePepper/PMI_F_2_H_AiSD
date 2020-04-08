#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");;
    ofstream fout("output.txt");;
    if (!fin) return 1;

    int N, M;
    vector<int> mass;

    fin >> N >> M;
    if (N < 1 || N > 100000 || M < 1 || M > 100000)
        return 2;

    int A = 0;
    for (int i = 0; i < N && fin >> A; i++) {
        if (A < 0 || A > 1000000000)
            return 3;
        mass.push_back(A);
    }

    for (int i = 0; i < M; i++) {
//        vector<int>::iterator it = max_element(mass.begin(), mass.end());
        auto it = max_element(mass.begin(), mass.end());
        *it /= 10;
    }

    fout << accumulate(mass.begin(), mass.end(), 0);
}