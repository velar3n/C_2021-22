#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    if((*(double*)a - *(double*)b)  == 0){
        return 0;
    }
    if((*(double*)a - *(double*)b) > 0){
        return 1;
    }
    else{
        return -1;
    }
}

void exchange(double* a, double* b){
    double t = *a;
    *a = *b;
    *b = t;
}

double partition(double cases[], int begin, int end){
    double pivot = cases[end];  
    int i = (begin - 1); 
    int j;
    for (j = begin; j <= end-1; j++){
        if (cases[j] <= pivot){
            i++; 
            exchange(&cases[i], &cases[j]);
        }
    }
    exchange(&cases[i + 1], &cases[end]);
    return (i + 1);
}

void quicksort(double cases[], int p, int r){
    if(p < r){
        double q;
        q = partition(cases, p, r);
        quicksort(cases, p, q-1);
        quicksort(cases, q+1, r);
    }
}


int main(){

    int N, n, i, j, lb, numberOfStars, max = 0, method;
    int ranges[100] = {0};
    double *cases, sortTime, numberO;
    clock_t tp1, tk1, tp2, tk2, tp3, tk3;

    printf("Enter the number of random generated numbers: ");
    scanf("%i", &N);

    printf("Enter the number of ranges: ");
    scanf("%i", &n);

    printf("Choose a sorting method:\n 1. qsort\n 2. bubblesort\n 3. quicksort\n");
    scanf("%i", &method);

    if((method != 1) && (method != 2) && (method != 3)){
        printf("Wrong method, pick again.\n\n");
        return 0;
    }

    cases = malloc(N * sizeof(double));                    /* dynamic memory allocation */
    srand48(time(0));

    for(i = 0; i < N; i++){
        cases[i] = drand48();                              /* random number generator - rand()*/
        i++;
        printf("%i", i);
        printf(": ");
        i--;
        printf("%lf", cases[i]);
        printf("\n");
    }

    if(method == 1){
        tp1 = clock();                                          /* qsort*/
        qsort(cases, N, sizeof(double), compare);
        tk1 = clock();
        sortTime = (tk1 - tp1)/(double)CLOCKS_PER_SEC;
        printf("Time of qsort: %f \n", sortTime);
    }

    if(method == 2){
        tp2 = clock();                                          /* bubblesort*/
        for (i = 0 ; i < (N - 1); i++){ 
            for (j = 0 ; j < (N - i - 1); j++){
              if (cases[j] > cases[j+1]){
                numberO = cases[j];
                cases[j] = cases[j+1];
                cases[j+1] = numberO;
              }
            }
        }
        tk2 = clock();
        sortTime = (tk2 - tp2)/(double)CLOCKS_PER_SEC;
        printf("Time of bubblesort: %f \n", sortTime);
    }


    if(method == 3){
        tp3 = clock();                                          /* own quicksort implementation */            
        quicksort(cases, 0, N - 1);
        tk3 = clock();
        sortTime = (tk3 - tp3)/(double)CLOCKS_PER_SEC;
        printf("Time of own quicksort: %f \n", sortTime);
    }


    printf("\n");


    for(i = 0; i < N; i++){
        j = (cases[i] - cases[i - 1]) * n;
        ranges[j] = ranges[j] + 1;
    }

    for(j = 0; j < n; j++){
        if(max < ranges[j]){
            max = ranges[j];
        }
    }

    printf("\nDifferences between numbers: \n\n");

    for(j = 0; j < n; j++){
        numberOfStars = ranges[j] * 78 / max;
        j++;
        if(j < 10){
            printf("%i", j);
            printf(":   ");
        }
        if((j >= 10) && (j < 100)){
            printf("%i", j);
            printf(":  ");
        }
        if(j == 100){
            printf("%i", j);
            printf(": ");
        }

        for(lb = 0; lb < numberOfStars; lb++){
            printf("*");
        }

        printf("\n");
        j--;
    }

    return 0;
}
