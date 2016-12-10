//
//  main.cpp
//  ASD2_3
//
//  Created by Serqey Cheremisin on 08/04/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>

using namespace std;

int max_heap=0;

class train{
    public:
    int arrival;
    int departure;
    void Add(int arrival, int departure);
};

void train::Add(int arrival, int departure){
    this->arrival = arrival;
    this->departure = departure;
}

class BinaryHeap
{
    train *binary_heap;
    int size;
    
public:
    
    BinaryHeap(int n){binary_heap =new train[n]; size = 0;}
    void Add(train ob);
    void Clean();
    void Print();
};

void BinaryHeap::Add(train ob){
    
    
    binary_heap[size] = ob;
    int i = size;
    int parent = (i - 1) / 2;
    
    while( i > 0 && binary_heap[parent].arrival > binary_heap[i].arrival){
        train temp = binary_heap[i];
        binary_heap[i] = binary_heap[parent];
        binary_heap[parent] = temp;
        
        i = parent;
        parent = (i-1)/2;
    }
    
    size++;
    if(max_heap < size) max_heap = size;

}

void BinaryHeap::Clean(){

    int sign=0;
    int index=0;
    int *buffer = new int[size];
    buffer[0] = binary_heap[0].departure;
    index++;
    for(int j=1; j<size; j++){
        for(int i=0; i<index; i++){
        if(buffer[i] < binary_heap[j].arrival){
            buffer[i]=binary_heap[j].departure;
            sign++;
            break;
        }
        }
            if(sign==0){
                buffer[index]=binary_heap[j].departure;
                index++;
            }else{
                sign =0;
            }
    }
    
    cout << index;
    delete [] buffer;
    
}

void BinaryHeap::Print(){

    cout<< endl << endl;
    
    
    for(int i =0; i<size; i++){
        cout << i << ": " << binary_heap[i].arrival << " " << binary_heap[i].departure << "     ";
        cout << endl;
        
    }
    
    cout << endl<<endl <<size << endl<<endl;

}



int main(int argc, const char * argv[]) {
    
    int n, arrival, departure;
    
    cin>>n;
    
    BinaryHeap heap(n);
    train ob;
    
    for(int i=0; i<n; i++){
        scanf("%d%d", &arrival, &departure);
        ob.Add(arrival, departure);
        heap.Add(ob);
    }
    
    
    heap.Clean();
    return 0;
}
