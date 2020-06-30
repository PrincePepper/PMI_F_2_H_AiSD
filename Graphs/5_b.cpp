#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

vector<int> terminal[100001];
bool visited[100001];
int time[100001];
bool answer[100001];

int count = 0;
int timer = 0;

int dfs(int v, int p = 0) {
    visited[v] = true;
    time[v] = timer;
    int depth = timer++;
    int children = 0;
    for (int i = 0; i < terminal[v].size(); i++) {
        if (terminal[v][i] != p) {
            if (visited[terminal[v][i]])
                depth = min(depth, time[terminal[v][i]]);
            else {
                int fnext = dfs(terminal[v][i], v);
                depth = min(depth, fnext);
                if (fnext >= time[v] && !answer[v] && p != 0) {
                    answer[v] = true;
                    count++;
                }
                children++;
            }
        }
    }
    if (p == 0 && !answer[v] && children > 1) {
        answer[v] = true;
        count++;
    }
    return depth;
}

int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    int N, M;
    fin >> N >> M;
    long long int first, second;
    for (int i = 0; i < M; i++) {
        fin >> first >> second;
        terminal[first].push_back(second);
        terminal[second].push_back(first);
    }
    dfs(1);
    fout << count << " ";
    for (int i = 1; i <= N; i++)
        if (answer[i])
            fout << i << " ";
}