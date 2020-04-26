//
// Created by Semen Sereda on 26.04.2020.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    long long int N = 0, value = 0, max_element = 0;
    fin >> N;
    vector<long long int> stairs;
    vector<long long int> stairs_count;
    stairs.push_back(0);
    stairs_count.push_back(0);
    for (int i = 0; i < N; i++) {
        fin >> value;
        stairs.push_back(value);
    }
    for (int i = 1; i <= N; i++) {
        long long int last = INT_MIN, last_two = INT_MIN;
        if (i != 1)last_two = stairs_count[i - 2];
        last = stairs_count[i - 1];
        stairs_count.push_back((max(last, last_two) + stairs[i]));
    }
    fout << stairs_count[stairs_count.size() - 1];
}
