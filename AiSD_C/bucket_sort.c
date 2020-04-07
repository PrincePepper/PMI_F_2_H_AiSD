//
// Created by semyo on 12.03.2020.
//

#include <stdio.h>
#include <math.h>

int char2digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        return -1;
}

char digit2char(int d) {
    if (d >= 0 && d <= 9)
        return (char) ('0' + d);
    else if (d >= 10 && d <= 35)
        return (char) ('A' + d - 10);
}

char *b_sort(char *mass_words[]) {

    for (int i = 2; i > -1; i--) {
        vector <vector<string>> support_mass;
        support_mass.resize(123);

        for (int j = 0; j < mass_words.size(); j++) {
            string letter = mass_words[j];
            support_mass[(int) letter[i]].push_back(letter);
        }

        mass_words.clear();

        for (int j = 0; j < support_mass.size(); j++) {
            if (support_mass[j].size() > 0) {
                for (int l = 0; l < support_mass[j].size(); l++) {
                    mass_words.push_back(support_mass[j][l]);
                }
            }
        }
    }
    return mass_words;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;
    fscanf(fin, "%d", &N);
    char mass[N][3];
    char *temp;
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%s", &mass[i]);
    }


}
