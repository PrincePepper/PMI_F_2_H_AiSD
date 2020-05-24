//
// Created by Semen on 29.04.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef pair<int, int> bigassAndcount;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    vector<bigassAndcount> a;
    int E = 0, F = 0, N = 0, C = 0, W = 0, temp = 0;
    fin >> E >> F >> N;
    vector<int> dp(F - E + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        fin >> C >> W;
        a.push_back(make_pair(C, W));
    }

    for (int i = 0; i <= F - E; i++) {
        for (int j = 0; j <= N; j++) {
            if (i - a[j].second >= 0 && dp[i - a[j].second] != INT_MAX)
                dp[i] = min(dp[i], dp[i - a[j].second] + a[j].first);
        }
    }
    if (dp[F - E] == INT_MAX)
        fout << -1;
    else fout << dp[F - E];
}
