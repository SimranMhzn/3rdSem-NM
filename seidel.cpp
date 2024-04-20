#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOLERANCE 0.00001

void gaussSeidelMethod(double A[][10], double b[], double x[], int n) {
    double error = 0;
    int iter = 0;

    do {
        error = 0;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            double new_x = (b[i] - sum) / A[i][i];
            error += fabs(new_x - x[i]);
            x[i] = new_x;
        }

        iter++;
    } while (iter < MAX_ITER && error > TOLERANCE);

    if (iter >= MAX_ITER) {
        printf("Gauss-Seidel method did not converge within maximum iterations.\n");
    } else {
        printf("Solution converged after %d iterations.\n", iter);
        printf("Solution (x):\n");
        for (int i = 0; i < n; i++) {
            printf("x%d = %0.6f\n", i + 1, x[i]);
        }
    }
}

int main() {
    int n;
    double A[10][10], b[10], x[10];

    printf("Enter size of matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter elements of vector b:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Initial guess for x
    for (int i = 0; i < n; i++) {
        x[i] = 0; // You can set initial guesses to any value you want
    }

    gaussSeidelMethod(A, b, x, n);

    return 0;
}

