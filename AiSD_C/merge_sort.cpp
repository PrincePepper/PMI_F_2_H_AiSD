//
// Created by User on 10.05.2020.
//
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
    int N;
    fin >> N;
    vector<string> words;
    for (int i = 0; i < N; i++) {
        string temp_words;
        fin >> temp_words;
        words.push_back(temp_words);
    }

    int temp=0;
    for (int i = 3; i >= 0; i--) {
        vector<vector<string>> mass(91);
        for (auto stroke : words) {
            mass[stroke[i]].push_back(stroke);
        }

        for (auto & mas : mass) {
            if (!mas.empty()) {
                    for (auto & ma : mas) {
                        words[temp] = ma;
                        temp++;
                    }
            }
        }
        mass.clear();
        temp=0;
    }

    for (int i = 0; i < N; i++) {
        fout << words[i] << endl;
    }
}
