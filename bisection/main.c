#include <math.h>
#include <stdio.h>

#include "funkction.h"

int main(){
    double x1, x2, *x0, eps;
    int method, result;

    printf("Enter the range for the search of the root ");
    printf("from: ");
        scanf("%lf", &x1);
    printf("to: ");
        scanf("%lf", &x2);

    printf("Choose the method to find the root - for the bisection method enter '1', fot the tangent method enter '2': ");
        scanf("%i", &method);

        if ((method != 1) && (method != 2)){
            printf("Please choose a correct method ");
            return 0;
        }

    printf("Enter the precision of the search of the root: ");
        scanf("%lf", &eps);

    result = mzero(x1, x2, eps, method, x0);

    if (result < 0){
        printf("Error - wrong range");
    } else {
        printf("Number of iterations: %i\n", result);
    }

    return 0;
}
