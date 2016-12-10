#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>


using namespace std;

int partition(vector<int> &mas, int left, int right){
    
    if (left!=right)
        swap(mas[left + rand() % (right - left)], mas[left]);
    int x = mas[left];
    
    int i = right+1;
    for (int j = right; j >= left; j--) {
        if (mas[j] >= x)
            swap(mas[--i],mas[j]);
    }
    return i;
}

int search_k(vector<int> & arr, const int k, int left, int right) {

    while(1) {
        int pos = partition(arr, left, right);
        
        
        if (pos < k)
            left = pos + 1;
        else if (pos > k)
            right = pos - 1;
        else
            return arr[k];
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> array;
    int item;
    for (int i = 0; i < n; ++i) {
        cin >> item;
        array.push_back(item);
    }
    
    cout << search_k(array, k, 0, n - 1);
    
    return 0;
}

/*
 10 0
 3 6 5 7 2 9 8 10 4 1
*/