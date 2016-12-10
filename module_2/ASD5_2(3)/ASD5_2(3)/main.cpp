
// Name        : ads12.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;
int n;

class A{
    int **a = new int*[n];
    int size;
public:
    A(int n){
        *a = new int[n];
    }
};

void Heapify(int **a, size_t size, size_t i) {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t min = i;
    
    if (left < size && a[left][0] < a[i][0]) {
        min = left;
    }
    
    if (right < size && a[right][0] < a[min][0]) {
        min = right;
    }
    
    if (min != i) {
        std::swap(a[i], a[min]);
        
        Heapify(a, size, min);
    }
}

void pop_front(int **a, size_t k){
    int cc=0;
    for(int i =0; i<k-1; i++){
        a[0][i] = a[0][i+1];
        cc++;
    }
    a[0][cc] = 1110;
    
}

void BuildHeap(int **a, size_t size) {
    for (size_t i = size / 2; i > 0; --i) {
        Heapify(a, size, i - 1);
    }
}

int getSize(int **a, size_t k){
    int size=0;
    for(int i =0; i<k;i++){
        if(a[0][i]!= 1110){
            size++;
        }
        else break;
    }
    return size;
}


int main() {
    size_t n, k, k2, k3, m, t=0, mm, s=0;
    
    std::cin >> n;
    std::cin >> k;
    k2 = k;
    k3 = k-1;

    m = (n-1)%k;
    if(n%k == 0)
        mm = n/k;
    else
        mm = n/k +1;
    
    int **a = new int *[k];
    
    for (size_t i = 0, j=0, p =0; i < n; ++i, p++) {
        if (i < k) {
            a[i] = new int[mm];
        }
        
        int value;
        
        cin >> value;
        
        if(p == k){
            p=0;
            j++;
        }
        a[i % k][j] = value;
    }
    
    int ii = n%k;
    if(ii != k){
    for(int i =0; i<(k - n%k); i++){
        a[ii][mm-1] = 1110;
        ii++;
    }
    }
    

    
    BuildHeap(a, k);
    
    for (;;) {
        int ss;
        for(int i=0; i<k; i++){
            for(int j=0; j<mm; j++){
                cout << a[i][j]<< " ";
            }
            cout << endl;
        }
        cout << endl;

        
   //    std::cout << a[0][0] << " ";
        

        pop_front(a, mm);
        if (getSize(a, k) == 0) {
            a[0] = a[k2 - 1];
            --k2;
        }
        
        if (k2 == 0) {
            break;
        }
        
        Heapify(a, k, 0);
    }
    
    
    return 0;
}