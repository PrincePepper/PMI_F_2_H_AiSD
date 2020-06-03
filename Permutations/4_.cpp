//
// Created by User on 27.05.2020.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else b = b % a;
    }
    return a + b;
}

#define module 1000000007

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    int dz = abs(z1 - z2);
    long long int answer = 1;


    vector<int> mass;
    for (int i = dz + 1; i <= dz + dx + dy; i++) mass.push_back(i);

    for (int i = 2; i <= dx; i++) {
        int d = i;
        for (int & j : mass) {
            int m = gcd(d, j);
            j /= m;
            d /= m;
        }
    }

    for (int i = 2; i <= dy; i++) {
        int d = i;
        for (int & j : mass) {
            int m = gcd(d, j);
            j /= m;
            d /= m;
        }
    }
    for (int i : mass) {
        answer *= i;
        answer %= module;
    }

    cout << answer;
}

