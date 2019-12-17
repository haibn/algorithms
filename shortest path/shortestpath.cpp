// Ho ten : Bui Ngoc Hai
// lop    : K51CD 
// bai tap: duong di ngan nhat

#include<iostream>
#include<fstream>
#include<assert.h>

using namespace std;

const int infinite = 32000;

float Dijkstra(int start,int end,int NumberOfPoint,float** weight,int* path)
{
    int Known[NumberOfPoint]; 
    for(int i=0;i<NumberOfPoint;i++) Known[i]=0;
    Known[start]=1;
    
    float dist[NumberOfPoint];
    for(int i=0;i<NumberOfPoint;i++) dist[i]= infinite;
    dist[start]=0;
    
    int pre[NumberOfPoint];
    
    for(int v=0;v<NumberOfPoint;v++)
        if(weight[start][v]>0){
            dist[v] = weight[start][v];
            pre[v]  = start;
        }    
    int u=start;
    while(u != end){
        int x;
        for(int i=0;i<NumberOfPoint;i++)
            if(Known[i]==0){
                x=i;
                break;
            }            
        for(int i=0;i<NumberOfPoint;i++)
           if(Known[i]==0 && dist[x]>dist[i])
              x=i;
        u=x;               //chon u la phan tu co nhan~ nho nhat trong tap UnKnown       
        Known[u]=1;        // dua u vao tap Known  
        // dan' nhan~
        for(int v=0;v<NumberOfPoint;v++)
            if(Known[v]==0 && weight[u][v]>0 && (dist[u]+weight[u][v])< dist[v]) {
                dist[v]= dist[u] + weight[u][v];
                pre[v]=u;        
            }                                   
    }  // ket thuc vong while

    // luu duong di vao mang path
    for(int i=0;i<NumberOfPoint;i++)path[i]=0;
    path[0]=end+1;
    int k=1;
    int x=end;
    while(x!=start){
        x=pre[x];
        path[k++]=x+1;
    }       
    return dist[end];        
}

// ----------------nhap du lieu vao tu file---------------------------------------------
void inputFromFile(char* FileName,int& NumberOfPoint,int& start,int& end,float** &weight)
{
        ifstream inFile(FileName);
        inFile>>NumberOfPoint;
        inFile>>start;
        inFile>>end;
        
        weight = new float* [NumberOfPoint];
        for(int i=0;i<NumberOfPoint;i++)weight[i] = new float [NumberOfPoint]; 
        for(int i=0;i<NumberOfPoint;i++)
             for(int j=0;j<NumberOfPoint;j++) weight[i][j]=0;
                     
        int i=0,j=0;
        float x=0;
        while(!inFile.eof()){
                inFile>>i;
                inFile>>j;
                inFile>>x;
                weight[i-1][j-1]=x;
                weight[j-1][i-1]=x;
        }                
}    

//----------xuat du lieu ra file--------------------------------------
void outputToFile(char* FileName,int NumberOfPoint,float way,int* path)
{
        ofstream outFile(FileName);
        if(way!=infinite)outFile<<way<<endl;
            else outFile<<"infinite"<<endl;
        for(int i=NumberOfPoint-1; i>=0 ; i--)
            if(path[i]>0)outFile<<path[i]<<" ";
        outFile<<endl;    
}
//------------------------------------------------------------------- 
int main()
{
    int NumberOfPoint,start,end;
    float** weight;
    
    inputFromFile("map.in",NumberOfPoint,start,end,weight); 
    int* path = new int[NumberOfPoint];       
    float way = Dijkstra(start-1,end-1,NumberOfPoint,weight,path);

    outputToFile("map.out",NumberOfPoint,way,path);
 
    delete path;
    delete weight;       
    return 0;                                              
}    

