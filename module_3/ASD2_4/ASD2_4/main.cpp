//
//  main.cpp
//  ASD2_4
//
//  Created by Serqey Cheremisin on 15/05/16.
//  Copyright © 2016 Serqey Cheremisin. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class CBinaryNode {
    friend class Tree;
protected:
    int Data;
    CBinaryNode* Left; // NULL, если нет.
    CBinaryNode* Right; // NULL, если нет.
    CBinaryNode* Parent; // NULL, если корень.
    
public:
    CBinaryNode(int value){
        Data = value;
        Left = 0;
        Right = 0;
        Parent = 0;
    }
    int get_data();
};


int CBinaryNode::get_data(){
    return Data;
}



class Tree{
    CBinaryNode *root;
public:
    Tree();
    int Insert(const int &node);
    void TraverseBFS();
    
};

Tree::Tree(){
    root = 0;
}

int Tree::Insert(const int &x)
{
    
    CBinaryNode* n=new CBinaryNode(x);  /* создаем новый узел, его мы будем вставлять */
    CBinaryNode* ptr;
    CBinaryNode* ptr1=NULL;
    
    n->Parent=n->Left=n->Right=0;          /* он - лист */
    ptr=root;
    while(ptr!=0)                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
    {
        ptr1=ptr;                 /* будущий родитель нового узла */
        if(x < ptr->get_data() )  /* по определению нашего дерева - слева значение ключа меньше родителя, */
            ptr=ptr->Left;
        else
            ptr=ptr->Right;   /* справа - больше */
    }
    n->Parent=ptr1;
    if(ptr1==0)                       /* дерево было пусто? */
        root=n;
    else
    {
        if(x < ptr1->get_data() )
            ptr1->Left=n;
        else
            ptr1->Right=n;
    }
    
    return 0;
}

void Tree::TraverseBFS(){
    queue<CBinaryNode*> q;
    q.push(root);
    while( !q.empty() ) {
        CBinaryNode* node = q.front();
        q.pop();
        //   visit( node );
       cout << node->Data << " ";
        if( node->Left != 0 )
            q.push( node->Left );
        if( node->Right != 0 )
            q.push( node->Right );
    }
}


int main(int argc, const char * argv[]) {
    
    int n, value;
    cin >> n;

    Tree Btree;
    
    for(int i=0; i<n; i++){
        cin >> value;
        Btree.Insert(value);
    }
    
    Btree.TraverseBFS();
    
    
    return 0;
}
