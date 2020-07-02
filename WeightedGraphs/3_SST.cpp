#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin;
ofstream fout;

typedef pair<int, int> valueAndWeight;
vector<vector<valueAndWeight>> terminal(100001);
vector<bool> visited(100001, false);

void dfs(int v) {
    visited[v] = true;
    for (auto &i : terminal[v])
        if (!visited[i.first])
            dfs(i.first);
}

void Dijkstra(int N) {
    vector<bool> visited(N, false);
    vector<int> min(N, INT_MAX);
    min[0] = 0;
    int count = 0;
    priority_queue<pair<int, int>> queue;
    queue.push(pair<int, int>(0, 0));
    while (!queue.empty()) {
        int v = queue.top().second;
        queue.pop();
        if (!visited[v]) {
            for (auto &i: terminal[v]) {
                if (i.second < min[i.first]) {
                    min[i.first] = i.second;
                    queue.push(pair<int, int>(-min[i.first], i.first));
                }
            }
            visited[v] = true;
            count += min[v];
        }
    }
    fout << count;
}

int main() {

    fin.open("input.txt");
    fout.open("output.txt");
    int M = 0, N = 0;
    fin >> N >> M;

    int tmpV1, tmpV2, weight;

    for (int i = 0; i < M; i++) {
        fin >> tmpV1 >> tmpV2 >> weight;
        terminal[tmpV1 - 1].push_back(pair<int, int>(tmpV2 - 1, weight));
        terminal[tmpV2 - 1].push_back(pair<int, int>(tmpV1 - 1, weight));
    }

    dfs(0);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            fout << -1;
            return 0;
        }
    }
    Dijkstra(N);

}