//
// Created by User on 03.05.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string Subsequence(const string &a, const string &b) {
    string res;

    vector<vector<int>> res_mass(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                res_mass[i + 1][j + 1] = 1 + res_mass[i][j];
            } else {
                res_mass[i + 1][j + 1] = max(res_mass[i + 1][j], res_mass[i][j + 1]);
            }
        }
    }
    for (int i = a.size(), j = b.size(); i > 0 && j > 0;) {
        if (a[i - 1] == b[j - 1]) {
            res.push_back(a[i - 1]);
            i--;
            j--;
        } else {
            if (res_mass[i][j] == res_mass[i - 1][j])
                i--;
            else
                j--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    string a;
    string b;
    fin >> a >> b;

    string c = Subsequence(a, b);
    fout << c;
}