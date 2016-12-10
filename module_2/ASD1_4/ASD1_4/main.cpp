//
//  main.cpp
//  ASD1_4
//
//  Created by Serqey Cheremisin on 06/04/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>

using namespace std;

bool compar(char *tmp, char *a){
    
    for(int i=0; i<256 && tmp[i]!='\0' && a[i]!='\0'; i++){
        if(tmp[i] < a[i]) return true;
        if(tmp[i] > a[i]) return false;
    }
    return false;
}

void swap(char *a1, char *a2){
    
    for(int i =0; i<255; i++){
        a1[i] = a2[i];
    }
}

void insertion_sort(char **a, int n) {
    
    char *tmp=new char[255];
    for (int i = 1; i < n; ++i) {
        swap(tmp, a[i]);

        for (int j = i; j > 0 && compar(tmp, a[j-1]); j--) {
            swap(a[j], a[j-1]);
            swap(a[j-1], tmp);

        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    char **strings = new char*[n];
    for(int i=0; i<n; i++){
        strings[i] = new char[255];
    }
    
    for(int i =0; i< n; i++){
            if(scanf("%s", &*strings[i])== '\n') break;
        
    }
    
    insertion_sort(strings, n);
    
    for(int i =0; i<n; i++){
            cout<<strings[i]<<endl;
        
    }
    
    
    return 0;
}

