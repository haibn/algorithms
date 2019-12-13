// ho ten :Bui Ngoc Hai


#include<iostream>
#include<assert.h>
#include<conio.h>
using namespace std;

template<class item>
class node{
    private:
        item data;
        node* next;
    public:
        node();                         
        void setData(item x);          
        item getData();
        void setNext(node* p);
        node* getNext();
        int length();                   
        node* getMax();                 
        node* element(int index);       // access an element
        void insert(int index,item x);     
        void append(item x);            
        void del(int index);            // delete an element
        void show();                    // list all elements      
};


template<class item>
node<item>::node()
{
    next=NULL;
};
//setData
template<class item>
void node<item>::setData(item x)
{
    this->data = x;   
};
//getData
template<class item>
item node<item>::getData()
{
    return this->data;   
};
//setNext
template<class item>
void node<item>::setNext(node* p)
{
    this->next = p;   
};
//getNext
template<class item>
node<item>* node<item>::getNext()
{
    return this->next;   
};

//getMax    
template<class item>
node<item>* node<item>::getMax()
{
    node* p = this;
    node* q=p; 
    while(p!=NULL){
          if(q->data < p->data)q=p;
          p = p->next;  
    }
    return q;   
};
//element
template<class item>
node<item>* node<item>::element(int index)
{
    node* p = this;
    assert(index<this->length() && index>=0);
    for(int i=0;i<index;i++){
        p=p->next;
    }
    return p;    
};        
//insert
template<class item>
void node<item>::insert(int index,item x)
{
    assert(index<=this->length() && index>=0);
    node* q = new node;
    q->data =x;
    if(index>0){
        node* p = this->element(index-1);
        q->next = p->next;
        p->next = q;
    }else if(index==0){              
                q->next = this->next;
                this->next = q;
                item t = this->data;
                this->data = q->data;
                q->data = t; 
          }       
};
//append
template<class item>
void node<item>::append(item x)
{
    this->insert(this->length(),x);   
};
//del
template<class item>
void node<item>::del(int index)
{
    node* p = this->element(index-1);
    node* q = this->element(index);
    p->next = q->next;
    delete q;  
};
//show
template<class item>
void node<item>::show()
{
    cout<<" All the elements are : ";
    node* p = this;
    while(p!=NULL){
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<endl;      
};


//length
template<class item>
int node<item>::length()
{
    int x=0;
    node* p=this;
    while(p!=NULL){
         x++;
         p=p->next;
    }
    return x;    
};
int main()
{
    
    node<int> *head = new node<int>;
    head->setData(1);
    head->append(2);
    head->append(3);
    head->getNext()->append(4);
    head->show();
    cout<<" Length : "<<head->length()<<endl;
    cout<<" Max : "<<head->getMax()->getData()<<endl;
    cout<<" Second element : "<<head->element(1)->getData()<<endl;
    head->insert(0,9);
    cout<<" After insert "<<endl;
    head->show();
    head->del(3);
    cout<<" After delete"<<endl;
    head->show();

    getch();
    return 0;
}    
