//
// Created by User on 26.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;
int count = 0;
int t_count = INT_MAX;
vector<char> bbb;

void bind(vector<bool> &used_char, vector<string> &words, int h) {
    if (words.size() == h) {
        if(t_count>=count) t_count=count;
        return;
    }
    for (int i = 0; i < words[h].size(); i++) {
        int element = words[h][i];
        if (!used_char[element]) {
            used_char[element] = true;
            for (int j = 0; j < i; j++) {
                count++;
                bbb.push_back(words[h][j]);
            }
            bbb.push_back('&');
            for (int j = i; j < words[h].size(); j++) {
                bbb.push_back(words[h][j]);
            }
            bind(used_char, words, h + 1);
            used_char[element] = false;
        }
        if (i + 1 == words[h].size()) {
            for (char &j : words[h]) {
                bbb.push_back(j);
            }
            bind(used_char, words, h + 1);
        }
    }
    count=0;
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
    bind(used_char, words, 0);
    fout<<t_count;
}
