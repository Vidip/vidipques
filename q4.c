#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(int *a, int size) {
    int i;
    for (i = 0; i<size; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


bool is_in(int *a, int size, int elem) {
    int i;
    for (i=0; i<size; i++) {
        if (a[i] == elem) {
            return true;
        }
    }
    return false;
}

void f(int **a, int a_siz, int* sizes) {
    print_array(a[0],sizes[0]);

    for (int i=1; i< a_siz; i++) {
        bool common_element = false;

        for (int k=0; k< sizes[i]; k++) {
            if (is_in(a[0],sizes[0],a[i][k])) {
                common_element = true;
                break;
            }
        }

        if (! common_element) {
            print_array(a[i],sizes[i]);
        }
    }

}



int main() {
    int s = 3;
    int sizes[] = {3,4,3};
    int **a = malloc(sizeof(int*)*3);
    for (int i=0; i<s; i++) {
        a[i] = malloc(sizeof(int*)*sizes[i]);
    }

    a[0][0] = 2;
    a[0][1] = 3;
    a[0][2] = 4;

    a[1][0] = 4;
    a[1][1] = 7;
    a[1][2] = 8;
    a[1][3] = 9;

    a[2][0] = 5;
    a[2][1] = 44;
    a[2][2] = 12;

    f(a,s,&sizes);
}