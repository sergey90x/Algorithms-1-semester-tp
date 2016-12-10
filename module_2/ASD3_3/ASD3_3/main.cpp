#include <iostream>

using namespace std;


class Segment{
public:
    int x1;
    int x2;

    
};

class Heap
{
    Segment *heap;
    int size;
    
public:
    
    Heap(int n){heap = new Segment[n]; size = 0;}
    
    void Add(Segment ob);
    void downHeap(int k, int n);
    void heapSort();
    void filedPaint();
    void Print();
};

void Heap::Add(Segment ob){
    
    heap[size] = ob;
    size++;
    
}


void Heap:: downHeap(int k, int n) {
    Segment new_elem;
    int child;
    new_elem = heap[k];


  while(k <= n/2) {  		// пока у a[k] есть дети
        child = 2*k;
        //  выбираем большего сына
        if( child < n && heap[child].x1 < heap[child+1].x1 )
            child++;
        if( new_elem.x1 >= heap[child].x1 ) break;
        // иначе
        heap[k] = heap[child]; 	// переносим сына наверх
        k = child;
    }
   
    heap[k] = new_elem;
   
}



void Heap::heapSort() {
    int i;
    Segment temp;
    
    // строим пирамиду
    for(i=size/2-1; i >= 0; i--) downHeap(i, size - 1);
    
    // теперь a[0]...a[size-1] пирамида
    
    for(i=size-1; i > 0; i--) {
        // меняем первый с последним
        temp=heap[i]; heap[i]=heap[0]; heap[0]=temp;
        
        // восстанавливаем пирамидальность a[0]...a[i-1]
        downHeap(0, i-1);
    }
    
}


void Heap::filedPaint(){
    int result=0;
    int max_x2=0;
    
    for(int i=0; i<size; i++){
        if(max_x2 < heap[i].x2){
            if(max_x2 < heap[i].x1){
        result += (heap[i].x2 - heap[i].x1);
        max_x2 = heap[i].x2;
            }
            else{
                result += (heap[i].x2 - max_x2);
                max_x2 = heap[i].x2;
            }
        }
        
    }
    cout <<result;
}

void Heap::Print(){
    
    
    for(int i =0; i<size; i++){
        cout << i << ": " << heap[i].x1 << " " << heap[i].x2 << "     ";
        cout << endl;
        
    }
    cout << endl<<endl;

}


int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    
    Segment ob;
    Heap heap(n);
    
    for(int i = 0; i<n; i++){
        scanf("%d%d", &ob.x1, &ob.x2);
        heap.Add(ob);
    }
    heap.heapSort();

    heap.filedPaint();
 
    
    return 0;
}



