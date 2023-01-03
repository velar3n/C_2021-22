#include <math.h>
#include <stdio.h>

#include "function.h"

int mzero(double x1, double x2, double eps, int method, double* x0){

    double f0, f1, f2;
    int iter = 1, max_iter = 10000;
    f1 = f(x1);
    f2 = f(x2);

    
    
    if(method == 1){
        if (f1*f2 > 0)
            return -1; /*wrong range*/

        do{ 
            *x0 = (x1 + x2)/2;
            f0 = f(*x0);
            iter ++;
                if( f1 * f0 > 0){
                    x1 = *x0; 
                    f1 = f0;
                } else{
                    x2 = *x0; 
                    f2 = f0;}
        }
        while ((fabs(f0) > eps) || (fabs((x2 - x1)/ *x0)) > eps);
    }

    if(method == 2){
        if (f1 == f2)
            return -1; /*wrong range*/
        do{
            *x0 = x2 - (x2 - x1) * f2/(f2-f1);
            f0 = f(*x0);

            x1 = x2; 
            f1 = f2; 
            x2 = *x0; 
            f2 = f0;
            iter ++;
            
            if (iter > max_iter)
                return -1;
        }
    while ((fabs(f0) > eps) || (fabs((x2 - x1)/ *x0)) > eps);
    }
      
    printf("Root found in x = %lf\n", *x0);
    printf("The root equals %lf\n", f(*x0));
    
    return iter;
}
