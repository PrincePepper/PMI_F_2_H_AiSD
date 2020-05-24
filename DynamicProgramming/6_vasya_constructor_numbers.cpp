//
// Created by semyo on 07.05.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define max_coolness 9 * 8 * (N - 1)
#define unit_number '0'
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int N = 0;
    string number_string;
    fin >> N >> number_string;
    vector<vector<int>> dp(10, vector<int>(N + 1, 0));

    for (int i = 0; i < N; i++) {
        if (number_string[i] == '*') {
            for (int j = 0; j < 10; j++) {
                for (int h = 0; h < 10; h++) {
                    if (j != h)
                        dp[h][i + 1] = max(dp[h][i + 1], dp[j][i] + j * h);
                }
            }
        } else {
            int element = number_string[i] - unit_number;
            int res;
            for (int j = 0; j < 10; j++) {
                if (j == element)
                    res = 0;
                else {
                    res = element * j;
                }
                dp[j][i + 1] = max(dp[j][i + 1], dp[element][i] + res);

            }
        }
    }
    fout << max_coolness - dp[0][N];
}