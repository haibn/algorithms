//==================================
//name:    Bui Ngoc Hai
//class:   K51CD 
//purpose: put Queen
//==================================

#include<iostream>
#include<conio.h>

using namespace std;
const int maxsize = 20;  //20 is max size
int size,k,x[maxsize],a[maxsize],b[2*maxsize],c[2*maxsize]; // is is number of solutions, a, b, c are 3 arrays to mark columns and diagonal lines
void prepare()
{
   cout << " input size = ";
   cin >> size;
   k=0;   
   for (int i=0;i<maxsize;i++)
   {
       x[i]=0; 
       a[i]=0; 
   }
   for (int i=0;i<2*maxsize;i++)
   { 
       b[i]=0;     
       c[i]=0; 
   }  
}
void ouput()
{
       k++;
       cout << " solution" <<k<< endl<<endl;
       for (int i=1;i<=size;i++)
       {         
         for (int j=1;j<=x[i]-1;j++) cout << " * "; 
         cout << " H ";
         for (int j=x[i]+1;j<=size;j++) cout << " * ";          
         cout << endl;
       } 
       cout << endl;
}
void putQueen( int i)
{  
 for (int j=1;j<=size;j++)
   if (a[j]==0 && b[i+j]==0 && c[i-j+maxsize]==0)     
   {
     x[i]=j;
     a[j]=1;
     b[i+j]=1;
     c[i-j+20]=1;
     if (i==size) ouput();
      else putQueen(i+1);
     a[j]=0;
     b[i+j]=0;
     c[i-j+20]=0;                            
   }   
}

int main()
{
   cout<<" program to put Queens in size*size chess board/n"<<endl; 
   prepare();   
   putQueen(1);
   if (k==0) cout << " No solution" << endl;
      else 
          cout << " there are " <<k<< " solutions " << endl; 
   getch();
   return 0;
}
