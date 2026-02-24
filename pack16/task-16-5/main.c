#include <stdio.h>
#include <stdlib.h>

double Function(double x);

// #include "func.c"

int main() {


    int M;
    scanf("%d", &M);

    double h = 5e-10;

    for (int i = 0; i < M; ++i) {
        double x;
        scanf("%lf", &x);

        double derivative;

        if (x - h < 0) {
            double delta_f = Function(x + h);
            double f_x = Function(x);
            derivative = (delta_f - f_x) / h;
        } else if (x + h > 1) {
            double f_x = Function(x);
            double delta_f = Function(x - h);
            derivative = (f_x - delta_f) / h;
        } else {
            double plus_f = Function(x + h);
            double minus_f = Function(x - h);
            derivative = (plus_f - minus_f) / (2 * h);
        }

        printf("%.15lf\n", derivative);
    }

    return 0;
}
