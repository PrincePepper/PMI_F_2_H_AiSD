//
// Created by User on 22.06.2020.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;
vector<vector<int>> terminal(100001);
bool visited_v[100001];

void dfs(long long int t) {
    visited_v[t] = true;
    for (int i: terminal[t]) {
        if (!visited_v[i])
            dfs(i);
    }
}

int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    long long int N = 0, M = 0;
    fin >> N >> M;
    long long int first, second;
    for (long long int i = 0; i < M; i++) {
        fin >> first >> second;
        terminal[first].push_back(second);
        terminal[second].push_back(first);
    }

    long long int count = 0;
    for (long long int i = 1; i <= N; i++) {
        if (!visited_v[i]) {
            count++;
            dfs(i);
        }
    }
    fout << count;
}
