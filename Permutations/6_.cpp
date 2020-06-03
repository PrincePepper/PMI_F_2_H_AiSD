//
// Created by User on 28.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
ifstream fin;
ofstream fout;

vector<string> cubes;
vector<int> answer;

void aaa(string word, vector<bool> &used, int h) {
    if (word.size() == h) {
        for (int i : answer) {
            fout << i<<" ";
        }
        exit(0);
    }
    for (int i = 0; i < cubes.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            if (cubes[i].find(word[h]) != -1) {
                answer.push_back(i + 1);
                aaa(word, used, h + 1);
                answer.pop_back();
            }
            used[i] = false;
        }
    }
}

int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    int N = 0;
    string temp, word;
    fin >> N >> word;
    if (word.size() > N) {
        cout << 0;
        return 0;
    }
    vector<bool> used(N);
    for (int i = 0; i < N; i++) {
        fin >> temp;
        cubes.push_back(temp);
    }
    aaa(word, used, 0);
    cout << 0;
}