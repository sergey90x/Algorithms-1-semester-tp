//
//  main.c
//  DZ1_3_3
//
//  Created by Serqey Cheremisin on 10/03/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *Intersection(int *A, int *B, int n, int m){

    return ;
}


int main(int argc, const char * argv[]) {
   
    int n, m;
    scanf("%d ", &n);
    scanf("%d ", &m);
    
    int *A = (int *)malloc(n);
    int *B = (int *)malloc(m);
    for(int i =0; i<n; i++){
        scanf("%d ", &A[i]);
    }
    for(int i =0; i<m; i++){
        scanf("%d ", &B[i]);
    }
    
    
    
    return 0;
}
