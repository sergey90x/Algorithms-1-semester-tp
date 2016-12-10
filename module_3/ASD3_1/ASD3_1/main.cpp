//
//  main.cpp
//  ASD3_1
//
//  Created by Serqey Cheremisin on 16/05/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Treap
{
    int x;
    int y;
    
    Treap *Left;
    Treap *Right;
    
public:
    
    Treap(int a, int b, Treap *left = NULL, Treap *right = NULL)
    {
        x = a;
        y = b;
        Left = left;
        Right = right;
    }
    
    Treap* Merge(Treap *L, Treap *R);
    void Split(int x, Treap *L, Treap *R);
    Treap Add(int x);
    Treap Remove(int x);
    
    
};

void Treap::Split(int a, Treap *L, Treap *R)
{
    Treap *newTree = NULL;
    if (x <= a)
    {
        if (Right == NULL)
            R = NULL;
        else
            Right->Split(x, newTree, R);
        L = new Treap(x, y, Left, newTree);
    }
    else
    {
        if (Left == NULL)
            L = NULL;
        else
            Left->Split(x, L, newTree);
        R = new Treap(x, y, newTree, Right);
    }
}

Treap* Treap::Merge(Treap *L, Treap *R)
{
    if (L == NULL) return R;
    if (R == NULL) return L;
    
    if (L->y > R->y)
    {
        Treap *newR = Merge(L->Right, R);
        return new Treap(L->x, L->y, L->Left, newR);
    }
    else
    {
        Treap *newL = Merge(L, R->Left);
        return new Treap(R->x, R->y, newL, R->Right);
    }
}


Treap Treap:: Add(int a)
{
    Treap *l, *r;
    Split(a, l, r);
    Treap *m = new Treap(x, rand());
    return *Merge(Merge(l, m), r);
}

Treap Treap:: Remove(int x)
{
    Treap *l, *m, *r;
    Split(x - 1, l, r);
    r->Split(x,  m, r);
    return *Merge(l, r);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
