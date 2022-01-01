#include<stdio.h>
#include "sortpoints.h"
void bsort(struct points *pointstable,int n){
	int i, j;
    struct points temp;
    for (i = 1; i < n ; i++)
    {
        for (j = 1; j <= (n -i); j++)
        {
            if ( pointstable[j].points <= pointstable[j + 1].points )
            {
                temp = pointstable[j];
                pointstable[j] = pointstable[j + 1];
                pointstable[j + 1] = temp;
            } 
        }
    }
    }
