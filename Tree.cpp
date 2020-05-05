// basic tree
#include<iostream>

#include<assert.h>

using namespace std;

template <class item>
class Node{
    item data;
    bool visited;
    int NumOfChildren;
    Node** children;
};

template <class item>
void preOrder(Node<item>* root)
{
    root->visited = 1;
    for(int i=0;i<root->NumOfChildren;i++)
        preOrder(root->children[i]);
}
    
template <class item>
void postOrder(Node<item>* root)
{
    for(int i=0;i<root->NumOfChildren;i++)
        postOrder(root->children[i]);
    root->visited = 1;    
}



template <class item>
class Node2{
    private:
        item data;
        bool visited;
        int NumOfChildren;
        Node2** children;
    public:
        Node2();
        void preOrder();
        void postOrder();
};

template <class item>
void Node2<item>::preOrder()
{
    this->visited = 1;
    for(int i=0;i<this->NumOfChildren;i++)
       this->children[i]->preOrder();
}
    
template <class item>
void Node2<item>::postOrder()
{
    for(int i=0;i<this->NumOfChildren;i++)
        this->children[i]->postOrder();
    this->visited = 1;    
}    
