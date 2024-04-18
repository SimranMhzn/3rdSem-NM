#include <stdio.h>

// Function to calculate the Lagrange basis polynomial for a given index i
double lagrange_basis(int i, int n, double x[], double X) {
    double result = 1.0;
    for (int j = 0; j < n; j++) {
        if (j != i) {
            result *= (X - x[j]) / (x[i] - x[j]);
        }
    }
    return result;
}

// Function to perform Lagrange interpolation
double lagrange_interpolation(int n, double x[], double y[], double X) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += y[i] * lagrange_basis(i, n, x, X);
    }
    return result;
}

int main() {
    int n;
    printf(" Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf(" Enter the x and y data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double X;
    printf(" Enter the value of x for interpolation: ");
    scanf("%lf", &X);

    double interpolated_value = lagrange_interpolation(n, x, y, X);
    printf(" The interpolated value at x = %.2f is %.2f\n", X, interpolated_value);

    return 0;
}

