//
// Created by User on 01.07.2020.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

vector<vector<int>> terminal(101, vector<int>(101, INT_MAX));

void Floyd(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (terminal[j][i] < INT_MAX && terminal[i][k] < INT_MAX)
                    terminal[j][k] = min(terminal[j][k], terminal[j][i] + terminal[i][k]);
            }
        }
    }
}

int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    int M, N;
    fin >> N >> M;

    for (int i = 0; i < N; i++)
        terminal[i][i] = 0;

    int first, second, weight;
    for (int i = 0; i < M; i++) {
        fin >> first >> second >> weight;
        terminal[first - 1][second - 1] = weight;
    }

    Floyd(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (terminal[i][j] != INT_MAX)
                fout << terminal[i][j] << " ";
        }
        fout << endl;
    }
}