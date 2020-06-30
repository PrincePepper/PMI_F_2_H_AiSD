//
// Created by User on 25.06.2020.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin;
ofstream fout;

vector<int> terminal[1000000];
int visited_v[1000000];
vector<int> answer;
int cycle = 0;

void dfs(long long int v) {
    visited_v[v] = 1;
    for (int i : terminal[v])
    {
        if(visited_v[i] == 0){
            dfs(i);
        } else if (visited_v[i] == 1){
            cycle = 1;
            return;
        }
    }
    visited_v[v] = 2;
    answer.push_back(v);
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
    for (long long int i = 1; i <= N; ++i)
        if (!visited_v[i])
            dfs(i);
    reverse(answer.begin(), answer.end());
    if (cycle) {
        fout << -1;
        return 0;
    }
    for (long long int i: answer)
        if(i >= 0)fout << i << " ";

}

