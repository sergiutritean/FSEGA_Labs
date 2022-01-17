//
// Created by Tritean Sergiu on 22-Nov-21.
//

#include "greedy.h"

int RECURSIVE_ACTIVITY_SELECTOR(int *s, int *f, int k, int n, int *a) {
    static int na = 0;
    int m = k+1;

    while(m<=n && s[m] < f[k] ) {
        m++;
    }

    if( m <= n ) {
        //RECURSIVE_ACTIVITY_SELECTOR(s,f,m,n,a);
        a[++na] = m;
        RECURSIVE_ACTIVITY_SELECTOR(s,f,m,n,a);
    }

    return na;
}

int GREEDY_ACTIVITY_SELECTOR(int *s, int *f, int n, int *a) {
    static int na = 0;
    int k = 0;
    for(int m = 1; m<=n; ++m) {
        if( s[m] >= f[k]) {
            a[++na] = m;
            k = m;
        }
    }
    return na;
}
