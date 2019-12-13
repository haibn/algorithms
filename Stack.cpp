#include<iostream>
#include<conio.h>
#include<assert.h>

using namespace std;

const int Max = 100;

class Stack{
    private:
        int element[Max];
        int top;
    public:
        Stack();
        bool empty();
        int length();
        void push(int x);
        int pop();
        int getTop();
        
};

Stack::Stack()
{
    top=-1;
}

bool Stack::empty()
{
    return (top==-1);
}            

int Stack::length()
{
    return (top+1);
}    

void Stack::push(int x)
{
    assert(length()<Max);
    element[++top]=x;
}

int Stack::pop()
{
    assert(!empty());
    int x = element[top--];
    return x;
}        

int Stack::getTop()
{
    assert(!empty());
    return element[top];
}    
