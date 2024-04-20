#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 2.718281828
int main()
{
    int n,i;
    printf("Enter the number of data = ");
    scanf("%d", &n);
    float x[n], y[n], X[n], Y[n], sumX = 0, sumXY = 0, sumX2 = 0, sumY = 0;
    printf("Enter data:\n");
    for ( i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
        Y[i] = log(y[i]); // in c , log = ln and log10 = log
        X[i] = log(x[i]);
    }
    for ( i = 0; i < n; i++)
    {
        sumX = sumX + X[i];
        sumXY = sumXY + X[i] * Y[i];
        sumX2 = sumX2 + X[i] * X[i];
        sumY = sumY + Y[i];
    }
    // printf("sumX = %f sumXY = %f sumX2 = %f sumY = %f", sumX, sumXY, sumX2, sumY);
    float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float A = (sumY - b * sumX) / n;
    // printf("%f ", A);
    float a = pow(e, A);
    printf("a = %f , b = %f", a, b);
    return 0;
}
