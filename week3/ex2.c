#include <stdio.h>
void bubble_sort(int *a, int n)
 {
    int i = 0, j = 0, t;
    for (i = 0; i < n; i++) 
    {   
        for (j = 0; j < n - i - 1; j++) { 
            if (a[j] > a[j + 1]) 
            {  
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

