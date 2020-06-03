//
// Created by User on 26.05.2020. НЕ РЕШЕНА
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

ifstream fin;
ofstream fout;
int ccc = INT_MAX;
vector<int> ddd;

void bind(vector<bool> &used_char, vector<string> &words, int h, vector<int> &aaa) {

    if (words.size() == h) {
        if (ccc > accumulate(aaa.begin(), aaa.end(), 0)) {
            ddd = aaa;
            ccc = accumulate(aaa.begin(), aaa.end(), 0);
        }
        return;
    }
    for (int i = 0; i < words[h].size(); i++) {
        int element = words[h][i];
        if (!used_char[element]) {
            used_char[element] = true;
            aaa.push_back(i);
            bind(used_char, words, h + 1, aaa);
            aaa.pop_back();
            used_char[element] = false;

        }
        if (i + 1 == words[h].size()) {
            aaa.push_back(i);
            bind(used_char, words, h + 1, aaa);
            aaa.pop_back();
        }
    }
}

int main() {

    fin.open("input.txt");
    fout.open("output.txt");
    int n = 0;
    string temp;
    fin >> n;
    vector<string> words;
    vector<bool> used(n);
    vector<bool> used_char(256);
    for (int i = 0; i < n; i++) {
        fin >> temp;
        words.push_back(temp);
    }
    vector<int> aaa;

    bind(used_char, words, 0, aaa);

    for(int i =0;i<words.size();i++){
        int j;
        for (j = 0; j < ddd[i]; j++) {
            fout << words[i][j];
        }
        fout << "&";
        for (int h = j; h < words[i].size(); h++) {
            fout << words[i][h];
        }
        fout<<endl;
    }

    cout << ccc;
}