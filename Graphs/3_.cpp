//
// Created by User on 25.06.2020.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;
vector<vector<int>> terminal(100001);
bool visited_v[100001];
vector<int> answer;

void dfs(long long int t,int N) {

    for (long long int i = 1; i <= N; i++) {
        dfs(i);
    }
    if (!visited_v[t]) {
        visited_v[t] = true;
        for (int i: terminal[t]) {
            if (!visited_v[i]){
                answer.push_back(i + 1);
                dfs(i);
                answer.pop_back();
            }

        }
        visited_v[t] = true;
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
    }



}

