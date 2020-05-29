// H. Sergio A. Fjodorov

#include <stdio.h>
#include <string.h>

#define MAX 10
#define UCHAR unsigned char

int n;
UCHAR strings[MAX][100];
UCHAR chars[MAX][MAX + 1];
int wchars[MAX][MAX];

UCHAR res[MAX], mres[MAX];
int cntres, mcntres, wres, mwres;
int used[256];

void
find(int idx)
{
    if (cntres > mcntres || (cntres == mcntres && wres < mwres)) {
        memcpy(mres, res, sizeof(res));
        mcntres = cntres;
        mwres = wres;
    }

    if (idx == n)
        return;

    UCHAR *ch = chars[idx];
    int *w = wchars[idx];
    for (; *ch; ch++, w++) {
        if (used[*ch])
            continue;
        used[*ch] = 1;
        cntres++;
        wres += *w;
        res[idx] = *ch;

        find(idx + 1);

        res[idx] = 0;
        wres -= *w;
        cntres--;
        used[*ch] = 0;
    }

    if (mcntres < cntres + n - idx)
        find(idx + 1);
}

int
main()
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");
    int i;

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%s", strings[i]);

    for (i = 0; i < n; i++) {
        UCHAR *str = strings[i];
        UCHAR *ch = chars[i];
        int *wch = wchars[i];
        int used[256];

        memset(used, 0, sizeof(used));

        for (; *str; str++) {
            if (used[*str])
                continue;
            used[*str] = 1;
            *ch++ = *str;
            *wch++ = str - strings[i];
        }
    }

    find(0);

    for (i = 0; i < n; i++) {
        UCHAR *str = strings[i];
        for (; *str; str++) {
            if (mres[i] == *str) {
                mres[i] = 0;
                fprintf(fout, "&");
            }
            fprintf(fout, "%c", *str);
        }
        fprintf(fout, "\n");
    }
}
