#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

int main() {
    double ini = 2;
    double fin = 2.6;
    int n_int = 6;
    double h = (fin - ini) / n_int;
    double total = 0;

    #pragma omp parallel
    {
        double local_total = 0;

        #pragma omp for
        for (int i = 0; i <= n_int; i++) {
            double x = ini + i * h;
            if (i == 0 || i == n_int) {
                local_total += f(x);
            } else {
                local_total += 2 * f(x);
            }
        }

        #pragma omp critical
        {
            total += local_total;
        }
    }

    total = (h / 2) * total;

    printf("resultado para o intervalo [%f,%f] é: %f \n", ini, fin, total);

    return 0;
}
