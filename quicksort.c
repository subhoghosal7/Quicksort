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

void quicksort(int* A, int l, int u){
    if(l < u){
        int i = l + 1, p = l, p_l = l;


        swap(A, l, l + rand() % (u - l));

        while(i <= u){
            while(A[i] <= A[p] && i <= u){
                if(i != p + 1)
                    swap(A, p, p + 1);
                    swap(A, p_l, p);
                swap(A, i, p_l);
                p++;
                i++;
                p_l += (A[p_l] != A[p]);
            }
            while(A[i] > A[p] && i <= u) i++;
        }

        quicksort(A , l, p_l - 1);
        quicksort(A, p + 1, u);

    }
}


int main(){
    int n = 1000000;
    int* A = calloc(n,sizeof(int));


    srand(time(NULL));


    for(int i = 0;i < n;i++){
        A[i] = rand() % n;
    }


    printf(" ");

    quicksort(A, 0, n - 1);

    for(int x = 0;x < n;x++)
        printf("%d \n",A[x]);

    free(A);

}
