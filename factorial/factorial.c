#include <stdio.h>
#include <stdlib.h>

int factorial_it(int n){    /* solver factorial using iteration */
    int acc = 1;

    if(n < 0)
        return -1;
    if(n == 0) 
        return 0;

    while(n > 0){
        acc *= n;           /*acc = acc*n*/
        n--;
    };
    return acc;
};

int factorial_rek (int n){  /* solve factorial using recursion */
    if(n < 0)
        return -1;
    if(n == 0) 
        return 1;
    if(n > 0)
        return (n*factorial_rek(n-1));
};

int main(int lb, char *argv[]){
    int n;
    int result1, result2;
    char *end;

    if (lb > 2){
        printf("%s\n", "Please enter only one number to calculate the factorial");
        return 1;
    };

    n = strtod(argv[1], &end); /*int*/

    result1 = factorial_it(n);
    result2 = factorial_rek(n);
    
    if (*end != '\0'){
        printf("%s\n", "Please enter an interger");
        return 1;
    };

    if ((result1 < 0) || (result2 < 0)){
        printf("Error - wrong number to calcualte factorial");
        };

    if ((result1 >= 0) || (result2 >= 0)){
        printf("Result: %d, %d\n", result1, result2);
    };
}
/* this program works for numbers <= 12 */
