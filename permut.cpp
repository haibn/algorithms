//==================================
//name:    Bui Ngoc Hai
//class:   K51CD nhom 3
//purpose: permutation
//==================================

#include <iostream>
using namespace std;

int n;  // the number to calculate permuttation
int array[10];
int mark[10];

void permut(int d)
{
   for (int i=0;i<n;i++)
      if (mark[i]==0){
          array[d]=i+1;
          mark[i]=1;
      if (d==n-1){
         for (int i=0;i<n;i++)
            cout<<" "<<array[i]<<" ";
            cout<<endl;
      } 
      else permut(d+1);
      mark[i]=0;
   } 
}
int main()
{ 
   cout<<" input n <10 "<<endl; 
   do{
       cout<<" n= ";
       cin>>n;
       if(n<=0)cout<<" please input n > 0"<<endl;
       if(n>=10)cout<<" please input n < 10 "<<endl;
   }while(n<=0||n>=10);
   cout<<" "<<n<<"! permutations are : \n"<<endl;    
   for (int i=0;i<n;i++) mark[i]=0;
   permut(0);
   return 0;
}



