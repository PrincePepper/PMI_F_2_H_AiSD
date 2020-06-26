//
// Created by User on 25.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fin;
ofstream fout;

int mark[1001];
string test_string[1001];
string answer;

void answerthetest(int p, int q, int k) {
    if (k == q) {
        bool done = true;
        for (int i = 0; i < p; i++) {
            int summa_sovpadeni = 0;
            for (int j = 0; j < q; j++) {
//                cout<<answer<<endl;
//                cout<<answer[x]<<" "<<test_string[y][x]<<endl;
                if (answer[j] == test_string[i][j])
                    summa_sovpadeni++;
            }
            if (summa_sovpadeni != mark[i]) {
                done = false;
                break;
            }
        }
        if (done) {
            for (int i = 0; i < q; i++) {
                fout << answer[i];
                cout << answer[i];
            }
            exit(0);
        } else
            return;
    }
    answer[k] = '-';
    answerthetest(p, q, k + 1);

    answer[k] = '+';
    answerthetest(p, q, k + 1);
}

int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    int P = 0, Q = 0, temp_int = 0;
    string temp;
    fin >> P >> Q;

    for (int i = 0; i < P; i++) {
        fin >> temp;
        test_string[i] = temp;
        fin >> temp_int;
        mark[i] = temp_int;
    }
    answerthetest(P, Q, 0);
}

