//
// Created by User on 25.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> setlist_A;

ifstream fin;
ofstream fout;

vector<int> digits(int a) {
    int u = a;
    int n = 0;
    while (u > 0) {
        u = u / 10;
        n++;
    }
    vector<int> result(n);
    n = 0;
    while (a > 0) {
        result[n++] = a % 10;
        a = a / 10;
    }
    return result;
}

void combi_A(vector<int> &digital_a, vector<int> &p, vector<bool> &mark, int u) {
    if (u == p.size()) {
        int cur = 0;
        if (digital_a[p[0]] == 0) {
            return;
        }
        for (int i = 0; i < p.size(); i++) {
            cur = 10 * cur + digital_a[p[i]];
        }
        setlist_A.insert(cur);
        return;
    }
    for (int i = 0; i < p.size(); i++) {
        if (!mark[i]) {
            mark[i] = true;
            p[u] = i;
            combi_A(digital_a, p, mark, u + 1);
            mark[i] = false;
        }
    }
}

void combi_B(vector<int> &digital_b, vector<int> &p, vector<bool> &mark, int c, int u) {
    if (u == p.size()) {
        int cur = 0;
        if (digital_b[p[0]] == 0) {
            return;
        }
        for (int i = 0; i < p.size(); i++) {
            cur = 10 * cur + digital_b[p[i]];
        }
//        for (auto i : setlist_A) //вывод всех перестановок А в консоль(надо закоментить перед тестом)
//            cout << i << endl;
        if (setlist_A.find(c - cur) != setlist_A.end()) {
            fout << "YES" << endl;
            fout << c - cur << " " << cur << endl;
//            cout << "YES" << endl;
//            cout << c - cur << " " << cur << endl;
            exit(0);
        }
        return;
    }
    for (int i = 0; i < p.size(); i++) {
        if (!mark[i]) {
            mark[i] = true;
            p[u] = i;
            combi_B(digital_b, p, mark, c, u + 1);
            mark[i] = false;
        }
    }
}


int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    int A = 0, B = 0, C = 0;
    fin >> A >> B >> C;
    vector<int> digital_a;
    digital_a = digits(A);

    vector<int> digital_b;
    digital_b = digits(B);

    vector<int> ppp(digital_a.size());
    vector<bool> mark(digital_a.size());

    combi_A(digital_a, ppp, mark, 0);

    vector<int> ppp2(digital_b.size());
    vector<bool> mark2(digital_b.size());

    combi_B(digital_b, ppp2, mark2, C, 0);
        fout << "NO";
        //cout << "NO";
}