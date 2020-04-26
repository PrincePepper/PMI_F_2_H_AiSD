#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int N = 0, temp = 0;
    vector<int> nails;
    vector<int> line_nails;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> temp;
        nails.push_back(temp);
    }
    sort(nails.begin(), nails.end());
    for (int i = 0; i < N; i++) {
        if (i < 3) {
            line_nails.push_back(nails[i] - nails[0]);
        } else {
            int left = line_nails[i - 1] + nails[i] - nails[i - 1];
            int right = line_nails[i - 2] + nails[i] - nails[i - 1];
            line_nails.push_back(min(left, right));
        }
    }
    fout << line_nails[line_nails.size() - 1];
}