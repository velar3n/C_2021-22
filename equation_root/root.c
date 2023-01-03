#include <stdio.h>
#include <math.h>
int main(){

    double a, b, c, delta;
    int error;
    error = 0;

    printf("Enter a: ");
    error = scanf("%lf", &a);
    if (error != 1){
        printf("Please enter correct values");
        return 1;
    };

    printf("Enter b: ");
    error = scanf("%lf", &b);
    if (error != 1){
        printf("Please enter correct values");
        return 1;
    };

    printf("Enter c: ");
    error = scanf("%lf", &c);
    if (error != 1){
        printf("Podaj poprawne wartości liczb");
        return 1;
    };

    delta = b*b - 4.*a*c;

    const char *i = "*i";
    const char *ii = "*i (where 'i' equals the squareroot of -1) ";


    if(delta > 0){
        printf("Two real roots: %lf, %lf\n", ((-b)-(sqrt(delta)))/(2*a), ((-b)+(sqrt(delta)))/(2*a));
        } else if(delta == 0){
            printf("One double root: %lf\n", (-b)/(2*a));
        } else if(delta < 0){
            printf("Two complex roots: %lf%s, %lf%s\n", ((-b)-(sqrt(-delta)))/(2*a), i, ((-b)+(sqrt(-delta)))/(2*a), ii);
        };

    return 0;
}
