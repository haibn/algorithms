#include<iostream>

using namespace std;


int Partition(int A[],int a ,int b)
{   
 	int   pivot = A[a];
 	int   left = a + 1;
 	int   right =	b;
 	do{
        while (( left <= right )&&(A[left] <= pivot )) 
                            left ++;
        while (( left <= right )&&(A[right]> pivot )) 
                            right --;
        if (left < right)
		{
				swap(A[left], A[right]);
				left ++;
				right --;
		}
    }
    while (left <= right);
    swap (A[a], A[right]) ;
    return right;
}

void quickSort2(int A[],int a,int b)
{
    if (a < b){
         int k = Partition(A,a,b);
         if (a <= k - 1) 
   	         quickSort2(A,a,k-1);
         if (k + 1 <= b) 
             quickSort2(A,k+1,b);
    }
}

void quickSort3(int A[],int a,int b)
{
    if (a < b){
         int k = Partition(A,a,b);
         quickSort3(A,a,k-1);
         quickSort3(A,k+1,b);
    }
}

void quickSort4(int s[], int first, int last)
{
     int mid,tmp,left,right;
     left=first;
     right=last;
     mid=s[(first+last)/2];
     do{
        while(s[left]<mid)left++;
        while(s[right]>mid)right--;
        if(left<=right){
          tmp=s[left];
          s[left]=s[right];
          s[right]=tmp;
          left++;
          right--;
        }
     } 
     while(left<=right);
     if(left<last)quickSort4(s,left,last);
     if(first<right)quickSort4(s,first,right); 
}

int main()
{
    int a[7] = {1,4,7,6,8,3,2};
    quickSort2(a,0,6);
    for(int i=0;i<7;i++)cout<<a[i]<<" ";    
    return 0;
   
}

 
      
      
