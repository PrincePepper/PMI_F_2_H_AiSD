//
// Created by User on 27.06.2020.
//
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

vector<int> terminal[100001];

void cycle(long long int v) {
    while (!terminal[v].empty()) {
        long long int _temp = terminal[v].back();
        terminal[v].pop_back();
        long long int value = 0;
        while (value <= terminal[_temp].size() && terminal[_temp][value] != v) {
            value++;
        }
        terminal[_temp].erase(terminal[_temp].begin() + value);
        cycle(_temp);
    }
    fout << v << " ";
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
    for (long long int i = 1; i <= N; ++i) {
        if (terminal[i].size() % 2 != 0) {
            fout << -1;
            return 0;
        }
    }
    cycle(1);
}