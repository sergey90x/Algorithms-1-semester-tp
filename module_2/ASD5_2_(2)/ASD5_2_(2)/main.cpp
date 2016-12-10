#include <iostream>
#include <list>

using namespace std;

void Heap(list<int> *a, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    
    if (left < size && a[left].front() < a[i].front()) {
        min = left;
    }
    
    if (right < size && a[right].front() < a[min].front()) {
        min = right;
    }
    
    if (min != i) {
        swap(a[i], a[min]);
        
        Heap(a, size, min);
    }
}

void BuildHeap(list<int> *a, int size) {
    for (int i = size / 2; i > 0; --i) {
        Heap(a, size, i - 1);
    }
}

int main() {
    int n, k;
    
    cin >> n;
    cin >> k;
    
    list<int> *a = new list<int>[k];
    
    for (int i = 0; i < n; ++i) {

        
        int value;
        
        cin >> value;
        
        a[i % k].push_back(value);
         
    }
    
    BuildHeap(a, k);
    
    for (;;) {
        cout << a[0].front() << " ";
        
        a[0].pop_front();
        
        if (a[0].size() == 0) {
            a[0] = a[k - 1];
            --k;
        }
        
        if (k == 0) {
            break;
        }
        
        Heap(a, k, 0);
    }
/*
    for(int i =0 ; i<k; i++){
         delete [] a;
    }
  */

    for(int i =0; i<k; i++)
  //  a[i].clear();

    
    
    
    return 0;
}