#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int* A, int i, int j){
    if(A[i] != A[j]){
        int t = A[i];
        A[i] =  A[j];
        A[j] = t;
    }
}

int quicksort_random(int* A, int l, int u){
    int count = 0;
    if(l < u){
        int i = l + 1, p = l, p_l = l;



        swap(A, l, l + rand() % (u - l));
        count++;


        while(i <= u){
            while(A[i] <= A[p] && i <= u){
                if(i != p + 1){
                    swap(A, p, p + 1);
                    swap(A, p_l, p);
                    }
                swap(A, i, p_l);
                p++;
                i++;
                count++;
                p_l += (A[p_l] != A[p]);
            }
            while(A[i] > A[p] && i <= u) {i++;count++;}

        }



        count += quicksort_random(A , l, p_l - 1) + quicksort_random(A, p + 1, u);

    }
    return count;
}


int quicksort_not_random(int* A, int l, int u){
    int count = 0;
    if(l < u){
        int i = l + 1, p = l, p_l = l;



        while(i <= u){
            while(A[i] <= A[p] && i <= u){
                if(i != p + 1){
                    swap(A, p, p + 1);
                    swap(A, p_l, p);
                    }
                swap(A, i, p_l);
                p++;
                i++;
                count++;
                p_l += (A[p_l] != A[p]);
            }
            while(A[i] > A[p] && i <= u) {i++;count++;}

        }

        count += quicksort_not_random(A , l, p_l - 1) + quicksort_not_random(A, p + 1, u);

    }
    return count;
}


double* foo(int n){
    double* count = calloc(2,sizeof(int));
    int* A = calloc(n,sizeof(int));

    int (*f[2]) (int*,int,int) = {quicksort_random,quicksort_not_random};

    for(int x = 1;x <= 1000;x++){
        for(int i = 0;i < n;i++){
            A[i] = n-i;
        }
        for(int i = 0; i < 0.25*n;i++){
            swap(A,rand()%n,rand()%n);
        }
        count[0] += (f[0](A, 0, n - 1) - count[0])/(double)x;

        for(int i = 0;i < n;i++){
            A[i] = n-i;
        }

        for(int i = 0; i < 0.25*n;i++){
            swap(A,rand()%n,rand()%n);
        }
        count[1] += (f[1](A, 0, n - 1) - count[1])/(double)x;

    }
    free(A);
    return count;
}

int main(){


    srand(time(NULL));

    for(int n = 100;n <= 1000;n += 10){
        double* count = foo(n);
        printf("%d\t%f\n", n, count[1]/count[0]);
        free(count);
    }

}
