//
//  main.c
//  DZ2_2
//
//  Created by Serqey Cheremisin on 04/03/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void AreaPoligon(short *x_coordinate, short *y_coordinate, int N){
    float area = 0;
    int j = N-1;
    for(int i = 0; i<N; i++){
        area = area + (x_coordinate[j] + x_coordinate[i]) * (y_coordinate[j] - y_coordinate[i]);
        j = i;        
    }
    area = area/2;
    if(area < 0)
    area = area*-1;
    
    
    printf("%f", area);
    return;
}

int main(int argc, const char * argv[]) {
    
    short N;
    short x;
    short y;
    scanf("%hd", &N);
    short *x_coordinate = (short*)malloc(N+1);
    short *y_coordinate = (short*)malloc(N+1);
    for(int i =0; i< N; i++){
        scanf("%hd", &x);
        scanf("%hd", &y);
        x_coordinate[i]=x;
        y_coordinate[i]=y;
    }

    AreaPoligon(x_coordinate, y_coordinate, N);
    
    
    return 0;
}

