#include<iostream>
#include<assert.h>

using namespace std;

const int Max = 100;

class Queue{
    private:
        int element[Max];
        int head;
        int tail;
    public:
        Queue();
        bool empty();
        int length();
        void enQueue(int x);
        int deQueue();
        int getHead();
        
};

Queue::Queue()
{
    head =0;
    tail=-1;
}

bool Queue::empty()
{
    return (tail==-1);
}

int Queue::length()
{   
    if(head<=tail) return tail-head+1;
        else if(head>tail && tail!=-1)
                return Max+tail-head+1;
             else return 0;    
}

void Queue::enQueue(int x)
{
    assert(length()<Max);
    element[++tail]=x;
}

int Queue::deQueue()
{
    assert(!empty());
    int x = element[head];
    if(head==tail){
        tail=-1;
        head=0;
    }else head++;
    return x;
}

int Queue::getHead()
{
    assert(!empty());
    return element[head];
}        

//-----------------------------------------------------------
int main()
{
    Queue Q;
    Q.enQueue(3);
    Q.enQueue(4);
    cout<<Q.deQueue()<<endl;
    cout<<Q.getHead()<<endl;
    cout<<Q.deQueue()<<endl;
    cout<<Q.length()<<endl;    
    return 0;
}    
    
        
