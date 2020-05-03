//
// Created by User on 03.05.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string Subsequence(const string &a, const string &b) {
    vector<vector<int>> res_mass;
    string res;
    int h, w;
    if (a < b) {
        res_mass.resize(b.size() + 1, vector<int>(a.size() + 1, 0));
        h = b.size();
        w = a.size();
    } else {
        res_mass.resize(a.size() + 1, vector<int>(b.size() + 1, 0));
        h = a.size();
        w = b.size();
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i] == b[j]) {
                res_mass[i + 1][j + 1] = 1 + res_mass[i][j];
            } else {
                res_mass[i + 1][j + 1] = max(res_mass[i + 1][j], res_mass[i][j + 1]);
            }
        }
    }
    int i = h, j = w;
    while (i > 0 && j > 0) {
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