#include <stdio.h>

const int TABLE_LENGTH = 100;

int main() {
    int n; //number of intervals
    double is [TABLE_LENGTH];
    bool ans [TABLE_LENGTH];
    int a, b; //buffer variables
    
    //Input: pair tab cases are minimas, even ones are maximas
    scanf("%d", &n);
    int i;
    for (i = 0; i < 2*n; i += 2) {
        scanf("%d %d", &a, &b);
        is[i] = a;
        is[i+1] = b;
    }
    
    for (i = 0; i < 2*n; i++) {
        ans[i] = true;
    }
    
    //Treatments    
    int intervalCounter = n;
    for (i = 0; i < 2*(n-1); i += 2) {
        if (is[i+1] >= is[i+2]) {
            //If the intervals intersect but the second isn't inside the first
            if (is[i+1] < is[i+3]) {
                ans[i+1] = false;
                ans[i+2] = false;
                intervalCounter--;
            }
            //If the second is inside the first
            else {
                ans[i+2] = false;
                ans[i+3] = false;
                intervalCounter--;
            }
        }
    }
    
    //Output
    printf("%d\r\n", intervalCounter);
    int nbOfTrues = 0;
    for (i = 0; i < 2*n; i++) {
        if (ans[i] == true) {
            nbOfTrues++;
            if (nbOfTrues == 1) {
                a = is[i];
            }
            if (nbOfTrues == 2) {
                b = is[i];
                printf("%d %d\r\n", a, b);
                nbOfTrues = 0;
            }
        }
    }
    
    return 0;
}