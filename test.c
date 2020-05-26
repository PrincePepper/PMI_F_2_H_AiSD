//
// Created by User on 25.05.2020.
//
#include <stdio.h>
#include <stdint.h>

#define STOPPER 0                                      /* Smaller than any datum */
#define    MEDIAN_FILTER_SIZE    (5)

int median_filter(int datum) {
    struct pair {
        struct pair *point;                              /* Pointers forming list linked in sorted order */
        int value;                                   /* Values to sort */
    };
    static struct pair buffer[MEDIAN_FILTER_SIZE] = {0}; /* Buffer of nwidth pairs */
    static struct pair *datpoint = buffer;               /* Pointer into circular buffer of data */
    static struct pair small = {NULL, STOPPER};          /* Chain stopper */
    static struct pair big = {&small, 0};                /* Pointer to head (largest) of linked list.*/

    struct pair *successor;                              /* Pointer to successor of replaced data item */
    struct pair *scan;                                   /* Pointer used to scan down the sorted list */
    struct pair *scanold;                                /* Previous value of scan */
    struct pair *median;                                 /* Pointer to median */
    int i;

    if (datum == STOPPER) {
        datum = STOPPER + 1;                             /* No stoppers allowed. */
    }
    printf("\n%d\n", datpoint->value);
    if ((++datpoint - buffer) >= MEDIAN_FILTER_SIZE) {
        datpoint = buffer;                               /* Increment and wrap data in pointer.*/
    }
    printf("\n%d\n", datpoint->value);
    datpoint->value = datum;                           /* Copy in new datum */
    successor = datpoint->point;                       /* Save pointer to old value's successor */
    median = &big;                                     /* Median initially to setlist_A in chain */
    scanold = NULL;                                    /* Scanold initially null. */
    scan = &big;                                       /* Points to pointer to setlist_A (largest) datum in chain */

    /* Handle chain-out of setlist_A item in chain as special case */
    if (scan->point == datpoint) {
        scan->point = successor;
    }
    scanold = scan;                                     /* Save this pointer and   */
    scan = scan->point;                                /* step down chain */

    /* Loop through the chain, normal loop exit via break. */
    for (i = 0; i < MEDIAN_FILTER_SIZE; ++i) {
        /* Handle odd-numbered item in chain  */
        if (scan->point == datpoint) {
            scan->point = successor;                      /* Chain out the old datum.*/
        }

        if (scan->value < datum)                        /* If datum is larger than scanned value,*/
        {
            datpoint->point = scanold->point;             /* Chain it in here.  */
            scanold->point = datpoint;                    /* Mark it chained in. */
            datum = STOPPER;
        };

        /* Step median pointer down chain after doing odd-numbered element */
        median = median->point;                       /* Step median pointer.  */
        if (scan == &small) {
            break;                                      /* Break at end of chain  */
        }
        scanold = scan;                               /* Save this pointer and   */
        scan = scan->point;                           /* step down chain */

        /* Handle even-numbered item in chain.  */
        if (scan->point == datpoint) {
            scan->point = successor;
        }

        if (scan->value < datum) {
            datpoint->point = scanold->point;
            scanold->point = datpoint;
            datum = STOPPER;
        }

        if (scan == &small) {
            break;
        }

        scanold = scan;
        scan = scan->point;
    }
    return median->value;
}

int main() {
    int mass[12] = {3, 2, 5, 7, 1, 10, 7, -3, 6, 15, 100, 0};
    for (int i = 0; i < 12; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", median_filter(mass[i]));
    }
}