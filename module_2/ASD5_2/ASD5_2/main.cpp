#include <iostream>
#include <algorithm>

using namespace std;

void Sort(int* array, int arraySize);
void inputSort(int arraySize, int bufSize);
void mergePrint(int* array1, int &arraySize1, int* array2, int arraySize2, int elemPrint);

int main() {
    int arraySize = 0;
    int bufSize = 0;
    cin >> arraySize >> bufSize;
    
    inputSort(arraySize, bufSize);
    
    return 0;
}

void Sort(int* array, int arraySize) {
    int minElem = 0;
    int minElemPos = 0;
    int swapBuf = 0;
    
    for (int i = 0; i < arraySize - 1; ++i) {
        minElem = array[i];
        minElemPos = i;
        
        for (int j = i + 1; j < arraySize; ++j) {
            if (array[j] < minElem) {
                minElemPos = j;
            }
        }
        
        swapBuf = array[minElemPos];
        array[minElemPos] = array[i];
        array[i] = swapBuf;
    }
}

void inputSort(int arraySize, int bufSize) {
    int* firstBuf = new int[bufSize];
    int* secondBuf = new int[bufSize];
    
    int firstBufSize = 0;
    int secondBufSize = 0;
    
    int elemRead = 0;
    
    while (elemRead < arraySize) {
        elemRead++;
        if (firstBufSize < bufSize) {
            cin >> firstBuf[firstBufSize++];
            continue;
        }
        else if (secondBufSize < bufSize - 1) {
            cin >> secondBuf[secondBufSize++];
            continue;
        }
        else {
            cin >> secondBuf[secondBufSize++];
            Sort(firstBuf, firstBufSize);
            Sort(secondBuf, secondBufSize);
            mergePrint(firstBuf, firstBufSize, secondBuf, secondBufSize, bufSize);
            
            //delete [] secondBuf;
            
            secondBufSize = 0;
            
            //secondBuf = new int[bufSize];
        }
    }
    
    if (firstBufSize < bufSize) {
        Sort(firstBuf, firstBufSize);
        for (int i = 0; i < firstBufSize; ++i) {
            cout << firstBuf[i] << " ";
        }
    }
    else {
        Sort(firstBuf, firstBufSize);
        Sort(secondBuf, secondBufSize);
        mergePrint(firstBuf, firstBufSize, secondBuf, secondBufSize, bufSize);
        
        
        for (int i = 0; i < firstBufSize; ++i) {
            cout << firstBuf[i] << " ";
        }
        
        //delete [] firstBuf;
    }
    delete [] firstBuf;
    delete [] secondBuf;
}

void mergePrint(int* array1, int &arraySize1, int* array2, int arraySize2, int elemPrint) {
    int flag1 = 0;
    int flag2 = 0;
    
    int maxSize = arraySize1 + arraySize2;
    
    int* bufArray = new int[maxSize];
    int bufPos = 0;
    
    for (int i = 0; i < maxSize; ++i) {
        if (flag1 == arraySize1) {
            bufArray[bufPos++] = array2[flag2++];
        }
        else if (flag2 == arraySize2) {
            bufArray[bufPos++] = array1[flag1++];
        }
        else {
            if (array1[flag1] > array2[flag2]) {
                bufArray[bufPos++] = array2[flag2++];
            }
            else {
                bufArray[bufPos++] = array1[flag1++];
            }
        }
        
    }
    
    
    for (int i = 0; i < elemPrint; ++i) {
        cout << bufArray[i] << " ";
    }
    
    arraySize1 = 0;
    for (int i = elemPrint; i < maxSize; ++i) {
        array1[arraySize1++] = bufArray[i];
    }
    delete [] bufArray;
}

