//
//  main.cpp
//  ASD5_2(4)
//
//  Created by Serqey Cheremisin on 18/04/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>

using namespace std;

void Print(int *temp, int size){
    for (int i = 0; i < size; i++)
        cout <<temp[i] << " ";
}


void selection_sort(int *a,int g, int n) {
    for (int i = g; i < n ; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_index]) min_index = j;
        }
        swap(a[i], a[min_index]);
    }
}


void merge(int *data, int *c, int len, int k, int ii){
    
    int i=ii; int j=len;
    int len2 = len+k;
    int ss;
    int pp=0;
    for (;pp<2*k;) {
        if (data[i] < data[j]) {
            c[pp] = data[i];
            
            ss = c[pp];
            ++pp;
            
        } else {
            
            c[pp] = data[j];
            ss = c[pp];
            ++pp;
            
        }
        
        
    }
 /*
    if (i==a_len) {
        
        for (;j < len2;++j) { c[i+j-k] = data[j]; }
        
    } else {
        
        for (;i < len;++i) { c[i+j-k] = data[i]; }
        
    }
   */
    for (int i = 0; i < k; i++){
        ss = c[i];
        cout << c[i] << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < 2*k; i++){
        data[i] = c[i];
    }
}
/*
void merge(int *data, int a_len, int b_len, int k, int kk, int ii, int *c) {
    int i=ii; int j=a_len;
    int ss;
    for (;i < a_len and j < b_len;) {
        
        if (data[i] < data[j]) {
            c[i+j-k] = data[i];
            
            ss = c[i+j-k];
            ++i;
            
        } else {
            
            c[i+j-k] = data[j];
            ss = c[i+j-k];
            ++j;
            
        }
        
        
    }
    
    if (i==a_len) {
        
        for (;j < b_len;++j) { c[i+j-k] = data[j]; }
        
    } else {
        
        for (;i < a_len;++i) { c[i+j-k] = data[i]; }
        
    }
    
    for (int i = 0; i < kk; i++){
        ss = c[i];
        cout << c[i] << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < 2*k; i++){
        data[i] = c[i];
    }
    
}
*/

int main(int argc, const char * argv[]) {
    
    
    
    int n, k;
    scanf("%d%d", &n, &k);
    
    int *data = new int[n];
    int *temp = new int[2*k];
    
    for(int i=0; i<n; i++){
        scanf("%d", &data[i]);
    }
    
  //  cout << endl;
    for(int i =0; i<n+k;i+=k){
        
        
        if((2*k+i)>n){
            selection_sort(data, i, n);
            
            for (int i = 0; i < n; i++)
                cout <<data[i] << " ";
            cout << endl;
             
            
       //     merge(data, k+i, n, k+2*i, k+(n%k), i, temp);
            merge(data, temp, k+i, k, i);
            //  Print(temp, n);
            break;
        }
        else{
            selection_sort(data, i, k+i);
        
            for (int i = 0; i < n; i++)
                cout <<data[i] << " ";
            cout << endl;
            
                        merge(data, temp, k+i, k, i);
          //  merge(data, k+i, 2*k+i, k+2*i, k, i, temp);
            //  Print(temp, k+i);
        }
        
    }
    
    
    
    return 0;
}

/*
 20 7
 -1 7 6 5 4 3 2 1 14 13 12 11 10 9 8 19 18 17 16 15
 
 15 2
 1 0 3 2 5 4 6 5 8 7 10 9 12 11 14 13
 */

