
#include<iostream>
#include<conio.h>
#include<assert.h>

using namespace std;

void breadthFirstSearch(int v,int n,int dd[],int a[][])
{   
    Queue Q;
    Q.enQueue(v);
    dd[v]=1;
    while(!Q.empty())
    {
        int w = Q.getHead();
        for(int u=0;u<n;u++)
           if(a[w][u]==1 && dd[u]==0){
              Q.enQueue(u);
              dd[u]=1;        
           }
        Q.deQueue();            
    }     
}

void breadthFirstSearch_traversal(int n,int dd[],int a[][])
{
    for(int v=0;v<n;v++)dd[v]=0;
    for(int v=0;v<n;v++)
        if(dd[v]==0)
            breadthFirstSearch(v,n,dd,a);            
}

void DepthFirstSearch(int v,int n,int dd[],int a[][])
{   
    dd[u]=1;
    for(int u=0;u<n;u++)
        if(a[v][u]==1 && dd[u]==0){
            DepthFirstSearch(u,n,dd,a);
        }    
}

void DepthFirstSearch_traversal(int n,int dd[],int a[][])
{
    for(int v=0;v<n;v++)dd[v]=0;
    for(int v=0;v<n;v++)
        if(dd[v]==0)
           DepthFirstSearch(v,n,dd,a);            
}                    

void topoSort(list T,int u,int n,int dd[],int a[][])
{
    dd[u]=1;
    for(int v=0;v<n;v++)
        if(a[u][v]==1 && dd[v]==0)
           topoSort(T,v,n,dd,a);
    T.insert(0,u);            
}

void topoSortGraph(list T,int n,int dd[],int a[][])
{
    for(int u=0;u<n;u++)dd[u]=0;
    while(!T.empty()) T.del(T.length()-1);
    for(int u=0;u<n;u++)
        if(dd[u]==0)
           topoSort(T,u,n,dd,a);           
}    

void FindConnectedComponent(int v,int ci,int n,int dd[],int a[][])
{
    Queue Q;
    Q.enQueue(v);
    dd[v]=ci;
    while(!Q.empty())
    {
        int w = Q.getHead();
        for(int u=0;u<n;u++)
           if(a[w][u]==1 && dd[u]==0){
              Q.enQueue(u);
              dd[u]=ci;        
           }
        Q.deQueue();            
    }   
}     

void FindAllConnectedComponent(int n,int dd[],int a[][])
{
    for(int v=0;v<n;v++)dd[v]=0;
    int ci=1;
    for(int v=0;v<n;v++)
        if(dd[v]==0){
            FindConnectedComponent(v,ci,n,dd,a);
            ci++;
        }    
}
    
const int infinite = 32000;

float Dijkstra(int start,int end,int n,float weight[][],int path[])
{
    int dd[n];
    for(int i=0;i<n;i++) dd[i]=0;
    dd[start]=1;
    float dist[n];
    for(int i=0;i<n;i++) dist[i]= infinite;
    dist[start]=0;
    int pre[n];
    for(int v=0;v<n;v++)
        if(weight[start][v]>0){
            dist[v] = weight[start][v];
            pre[v]  = start;
        }
    int u=start;
    while(u != end){
        int x;
        for(int i=0;i<n;i++)
            if(dd[i]==0){
                x=i;
                break;
            }            
        for(int i=0;i<n;i++)
           if(dd[i]==0 && dist[x]>dist[i]) x=i;
        u=x;        
        dd[u]=1;   
        for(int v=0;v<n;v++)
            if(dd[v]==0 && weight[u][v]>0 && (dist[u]+weight[u][v])< dist[v]) {
                dist[v]= dist[u] + weight[u][v];
                pre[v]=u;        
            }                                   
    }
    for(int i=0;i<n;i++)path[i]=0;
    path[0]=end+1;
    int k=1;
    int x=end;
    while(x!=start){
        x=pre[x];
        path[k++]=x+1;
    }        
    return dist[end];        
}          
        
                    
