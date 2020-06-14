//
// Created by Semen on 12.06.2020.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream fin;
ofstream fout;

class Hash {
private:
    long long int key;
    long long int value;
    Hash *next;
public:
    explicit Hash(long long int key, long long int value);

    static long long int hashFunction(long long int n);

    Hash *insertH(Hash **hashTable, long long int n);

    void deleteH(Hash **hashTable, long long int n);

    Hash *findH(Hash **hashTable, long long int n);

    void printH(Hash **hashTable);
};

Hash::Hash(long long int key, long long int value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

long long int Hash::hashFunction(long long int value) {
    return value% 10000;
}

Hash *Hash::insertH(Hash **hashTable, long long int n) {
    long long int bucket = hashFunction(n);
    Hash *p0 = hashTable[bucket];
    while (p0 && p0->value != n){
        p0 = p0->next;
    }
    if (p0 && n == p0->value) {
        return *hashTable;
    }
    p0 = hashTable[bucket];
    Hash *p = new Hash(bucket, n);
    hashTable[bucket] = p;
    p->next = p0;
    return p;
}

//Hash *Hash::findH(Hash **hashTable, long long int n) {
//    Hash *p;
//    p = hashTable[hashFunction(n)];
//    while (p && p->value != n)
//        p = p->next;
//    return p;
//}

void Hash::deleteH(Hash **hashTable, long long int n) {
    Hash *p0 = nullptr, *p;
    long long int bucket = hashFunction(n);
    p = hashTable[bucket];
    while (p && p->value != n) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[hashFunction(n)] = p->next;
}

void Hash::printH(Hash **hashTable) {
    vector<long long int> mass;
    for (long long int i = 0; i < 10000; i++) {
        Hash *p = hashTable[i];
        if (p != nullptr) {
            while (p) {
                mass.push_back(p->value);
                p = p->next;
            }
        }
    }
    sort(mass.begin(), mass.end());
    for (long long mas : mass)
        fout << mas << " ";
}


int main() {
    fin.open("input.txt");
    fout.open("output.txt");
    long long int k = 1;
    vector<long long int> mass;
    for (long long int i = 0; k != 0; i++) {
        fin >> k;
        mass.push_back(k);
    }
    Hash *root[10000] = {nullptr};
    Hash hash(1, 1);
    for (long long int mas : mass) {
        if (mas > 0)
            hash.insertH(root, mas);
        else if (mas < 0)
            hash.deleteH(root, abs(mas));
        else if (mas == 0) break;
    }
    hash.printH(root);
    fout.close();
}
