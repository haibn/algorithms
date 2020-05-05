
#include<iostream>
#include<assert.h>

using namespace std;

//breasth first search from vertex v, n is the number of vertex (size of graph), marked[] is an array to mark if v is visited or not
void breadthFirstSearch(int v,int size,int marked[],int graph[][])
{   
    Queue Q;
    Q.enQueue(v);
    marked[v]=1;
    while(!Q.empty())
    {
        int w = Q.getHead(); //w is temporary vertex
        for(int u=0;u<size;u++)
           if(graph[w][u]==1 && marked[u]==0){
              Q.enQueue(u);
              marked[u]=1;        
           }
        Q.deQueue();            
    }     
}

void breadthFirstSearch_traversal(int size,int marked[],int graph[][])
{
    for(int v=0;v<size;v++)marked[v]=0;
    for(int v=0;v<size;v++)
        if(marked[v]==0)
            breadthFirstSearch(v,size,marked,graph);            
}

void DepthFirstSearch(int v,int size,int marked[],int graph[][])
{   
    marked[v]=1;
    for(int u=0;u<size;u++)
        if(graph[v][u]==1 && marked[u]==0){
            DepthFirstSearch(u,size,marked,graph);
        }    
}

void DepthFirstSearch_traversal(int size,int marked[],int graph[][])
{
    for(int v=0;v<size;v++)marked[v]=0;
    for(int v=0;v<size;v++)
        if(marked[v]==0)
           DepthFirstSearch(v,size,marked,graph);            
}                    

void topoSort(list T,int u,int size,int marked[],int graph[][])
{
    marked[u]=1;
    for(int v=0;v<size;v++)
        if(graph[u][v]==1 && marked[v]==0)
           topoSort(T,v,size,marked,graph);
    T.insert(0,u);            
}

void topoSortGraph(list T,int size,int marked[],int graph[][])
{
    for(int u=0;u<size;u++)marked[u]=0;
    while(!T.empty()) T.del(T.length()-1);
    for(int u=0;u<size;u++)
        if(marked[u]==0)
           topoSort(T,u,size,marked,graph);           
}    
// ci is the label of the connected component
void FindConnectedComponent(int v,int ci,int size,int marked[],int graph[][])
{
    Queue Q;
    Q.enQueue(v);
    marked[v]=ci;
    while(!Q.empty())
    {
        int w = Q.getHead(); //w is the temporary visiting vertex
        for(int u=0;u<size;u++)
           if(graph[w][u]==1 && marked[u]==0){
              Q.enQueue(u);
              marked[u]=ci;        
           }
        Q.deQueue();            
    }   
}     

void FindAllConnectedComponent(int n,int marked[],int graph[][])
{
    for(int v=0;v<size;v++)marked[v]=0;
    int ci=1;
    for(int v=0;v<size;v++)
        if(marked[v]==0){
            FindConnectedComponent(v,ci,size,marked,graph);
            ci++;
        }    
}
    
const int infinite = 32000;

float Dijkstra(int start,int end,int size,float weight[][],int path[])
{
    int marked[size];  //marked[] is an array to mark if v is visited or not
    for(int i=0;i<size;i++) marked[i]=0;
    marked[start]=1;
    float dist[size];
    for(int i=0;i<size;i++) dist[i]= infinite;
    dist[start]=0;
    int pre[size];
    for(int v=0;v<size;v++)
        if(weight[start][v]>0){
            dist[v] = weight[start][v];
            pre[v]  = start;
        }
    int u=start;
    while(u != end){
        int x; // temporary node
        for(int i=0;i<size;i++)
            if(marked[i]==0){
                x=i;
                break;
            }            
        for(int i=0;i<size;i++)
           if(marked[i]==0 && dist[x]>dist[i]) x=i;
        u=x;        //select u with smallest dist in UnKnown set 
        marked[u]=1;   // add u to Known 
        for(int v=0;v<size;v++)
            if(marked[v]==0 && weight[u][v]>0 && (dist[u]+weight[u][v])< dist[v]) {
                dist[v]= dist[u] + weight[u][v];
                pre[v]=u;        
            }                                   
    }
	// save shorstest path to an array
    for(int i=0;i<size;i++)path[i]=0;
    path[0]=end+1;
    int k=1;
    int x=end;
    while(x!=start){
        x=pre[x];
        path[k++]=x+1;
    }        
    return dist[end];        
}          
        
                    
