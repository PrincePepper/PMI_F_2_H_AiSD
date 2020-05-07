//
// Created by User on 04.05.2020.
//
#include <iostream>
#include <vector>
#include <fstream>

#define module 1000000007

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int N, K, temp = 0;
    fin >> N >> K;
    vector<int> mass_Ai(N + 1, 0);
    vector<vector<int>> dp(3, vector<int>(N + 1, 0));
    dp[1][0] = 1;
    for (int i = 0; i < K; i++) {
        fin >> temp;
        mass_Ai[temp] = 1;
    }
    for (int i = 1; i < N + 1; i++) {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % module;
        if (mass_Ai[i] == 0) {
            dp[1][i] = dp[0][i - 1] % module;
            dp[2][i] = dp[1][i - 1] % module;
        }
    }
    fout << ((dp[0][N] + dp[1][N]) % module);
}
