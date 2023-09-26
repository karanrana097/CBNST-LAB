#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the dimensions:: ");
    scanf("%d", &n);
    double a[n][n + 1];
    int i=0,j=0;
    printf("Enter the matrix in form [A|B]: \n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Input Matrix:: \n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
int k=0;
    for ( i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            for ( j = i + 1; j < n; j++) {
                if (a[j][i] != 0) {
                    for ( k = 0; k < n + 1; k++) {
                        double temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                }
            }
        }
        if (a[i][i] == 0) {
            fprintf(stderr, "Given system of eq do not have a Unique Solution.");
            return 1;
        }

        double temp = a[i][i];
        for ( j = i; j < n + 1; j++) {
            a[i][j] = a[i][j] / temp;
        }
        for ( j = i + 1; j < n; j++) {
            if (a[j][i] != 0) {
                double div = a[j][i] / a[i][i];
                for ( k = i; k < n + 1; k++) {
                    a[j][k] = a[j][k] - a[i][k] * div;
                }
            }
        }
    }

    for ( i = n - 1; i >= 0; i--) {
        for ( j = i - 1; j >= 0; j--) {
            double div = a[j][i] / a[i][i];
            for ( k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - div * a[i][k];
            }
        }
    }

    printf("Solutions: \n");
    for ( i = 0; i < n; i++) {
        printf("x_%d = %lf\n", i, a[i][n]);
    }
    return 0;
}

