#include <stdio.h>
#include <math.h>

#define STEP 0.05

int main() {
    freopen("input.txt", "r", stdin);

    int n = 0;
    scanf("%d", &n);
    double l, r, t;
    double c[3][4];
    double x, y, z;
    double result = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &l, &r);
        scanf("%lf %lf %lf %lf", &c[0][0], &c[0][1], &c[0][2], &c[0][3]);
        scanf("%lf %lf %lf %lf", &c[1][0], &c[1][1], &c[1][2], &c[1][3]);
        scanf("%lf %lf %lf %lf", &c[2][0], &c[2][1], &c[2][2], &c[2][3]);


        /*
        for (t = l + STEP; t <= r; t += STEP) {
            x = c[0][0] + c[0][1] * (t - l) + c[0][2] * (t - l) * (t - l) + c[0][3] * (t - l) * (t - l) * (t - l);
            y = c[1][0] + c[1][1] * (t - l) + c[1][2] * (t - l) * (t - l) + c[1][3] * (t - l) * (t - l) * (t - l);
            z = c[2][0] + c[2][1] * (t - l) + c[2][2] * (t - l) * (t - l) + c[2][3] * (t - l) * (t - l) * (t - l);
        }
        */
        t = (l + r) / 2;
        x = c[0][0] + c[0][1] * (t - l) + c[0][2] * (t - l) * (t - l) + c[0][3] * (t - l) * (t - l) * (t - l);
        y = c[1][0] + c[1][1] * (t - l) + c[1][2] * (t - l) * (t - l) + c[1][3] * (t - l) * (t - l) * (t - l);
        z = c[2][0] + c[2][1] * (t - l) + c[2][2] * (t - l) * (t - l) + c[2][3] * (t - l) * (t - l) * (t - l);


        result = simpson(x,y,z);
    }


    printf("%.15lf\n", result);
    return 0;
}
