//
//  main.cpp
//  ASD6_3
//
//  Created by Serqey Cheremisin on 21/04/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>

using namespace std;


const int bitsword = 64;


int digit(long long value, int w) {
    return ( value >> ( bitsword - w - 1 ) & 1 );
}


void quickSortB(long long *data, int l, int r, int w) {
    int i = l, j = r;
    if (r <= l || w > bitsword) return;
    
    while (j != i) {
        
        while (digit(data[i], w) == 0 && (i < j)) i++;
        while (digit(data[j], w) == 1 && (j > i)) j--;
        swap(data[i],data[j]);
    }
    
    if (digit(data[r], w) == 0) j++;
    quickSortB(data, l, j-1, w+1);
    quickSortB(data, j, r, w+1);
}


int main(){
    int n;
    cin >> n;
    
    long long *array = new long long[n];
    
    for (int i = 0; i < n;i++) {
        cin >> array[i];
    }
    
    quickSortB(array, 0, n - 1, 0);
    
    for (int i = 0; i < n;i++) {
        cout << array[i] <<" ";
    }
    

    return 0;
}
