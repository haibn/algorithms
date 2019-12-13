#include<iostream>
#include<conio.h>

using namespace std;

void Merge(int a[],int start,int mid,int end)
{   
    int b[end - start +1];
    int i=start,j=mid+1,k=0;
    
    while(i<=mid && j<=end){
         if(a[i]<a[j]) b[k++] = a[i++];
            else b[k++] = a[j++];      
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= end) b[k++] = a[j++];
    //gan mang b vao mang a   
    for(int count = start; count <= end; count ++)
        a[count] = b[count - start];     
} 

void  MergeSort(int  a[],int start,int end) 
{
    if (start < end) {
        int mid = (start + end)/2;
        MergeSort (a,start,mid);
        MergeSort (a,mid+1,end);
        Merge (a,start,mid,end);
    }
}   

int main()
{
    int a[7] = {1,4,7,6,8,3,2};
    MergeSort(a,0,6);
    for(int i=0;i<7;i++)cout<<a[i]<<" ";
    int b[4] = {1,4,7,6};
    cout<<endl;
    MergeSort(b,0,3);
    for(int i=0;i<4;i++)cout<<b[i]<<" ";       
    getch();
    return 0;
   
}
