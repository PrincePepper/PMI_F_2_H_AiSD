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

void bind(vector<bool> &used_char, vector<string> &words, int h) {
    if (words.size() == h) {
        exit(0);
    }
    for (int i = 0; i < words[h].size();i++){
        int element = words[h][i];

        if(!used_char[element]){
            used_char[element] = true;
            for(int j=0;j<i;j++){
                fout<<words[h][j];
            }
            fout<<"&";
            for(int j=i;j<words[h].size();j++){
                fout<<words[h][j];
            }
            fout<<endl;
            bind(used_char, words, h + 1);
        }
        if(i+1==words[h].size()){
            fout<<words[h]<<endl;
            bind(used_char, words, h + 1);
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
    bind(used_char, words, 0);
}