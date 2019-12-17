//==================================
//name:    Bui Ngoc Hai
//class:   K51CD nhom 3
//project: bt tuan 3
//purpose: bai 2d
//==================================

#include<iostream>
#include<conio.h>

using namespace std;

int n,k,x[20],a[20],b[40],c[40];
void chuanbi()
{
   cout << " Nhap xin moi nhap vao n = ";
   cin >> n;
   k=0;   
   for (int i=0;i<20;i++)
   {
       x[i]=0; 
       a[i]=0; 
   }
   for (int i=0;i<40;i++)
   { 
       b[i]=0;     
       c[i]=0; 
   }  
}
void xuat()
{
       k++;
       cout << " cach xep thu " <<k<< endl<<endl;
       for (int i=1;i<=n;i++)
       {         
         for (int j=1;j<=x[i]-1;j++) cout << " * "; 
         cout << " H ";
         for (int j=x[i]+1;j<=n;j++) cout << " * ";          
         cout << endl;
       } 
       cout << endl;
}
void xephau( int i)
{  
 for (int j=1;j<=n;j++)
   if (a[j]==0 && b[i+j]==0 && c[i-j+20]==0)     
   {
     x[i]=j;
     a[j]=1;
     b[i+j]=1;
     c[i-j+20]=1;
     if (i==n) xuat();
      else xephau(i+1);
     a[j]=0;
     b[i+j]=0;
     c[i-j+20]=0;                            
   }   
}

int main()
{
   cout<<" chuong trinh xep n quan hau tren ban co n*n o vuong /n"<<endl; 
   chuanbi();   
   xephau(1);
   if (k==0) cout << " Ko co cach sap xep nao" << endl;
      else 
          cout << " Co " <<k<< " cach xep " << endl; 
   getch();
   return 0;
}
