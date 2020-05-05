// Name :  Bui Ngoc Hai
// class :     K51CD
// TravelingSalesmanProblem

#include<fstream>

using namespace std;

const int infinite = 32000;

int    numOfNodes,start;
bool   *checked;
int    *pathTemp,index=0; //array to save the temporary path
int    *minPath;         // array to save the shortest path
float  minPathLength=0;  // length of shortest path
float  **weight;

//---------------length of path passes through all the nodes--------------------------
float pathLength(int* path,int size)
{
    float length =weight[path[size-1]][path[0]];
    for(int i=0;i<size-1;i++){
        length += weight[path[i]][path[i+1]];
    }    
    return length;    
}
//-------------find shortest path from i, passes all the nodes------------------
void findPath(int i)
{
    for(int j=0;j<numOfNodes;j++){
        if(weight[i][j]<infinite && checked[j]==0)
        {
            pathTemp[index++] = j;
            checked[j] = 1;
            if(index < numOfNodes) findPath(j);
               else if(pathLength(pathTemp,numOfNodes) < minPathLength)
                    {
                       minPathLength = pathLength(pathTemp,numOfNodes);        
                       for(int k=0; k < numOfNodes; k++) minPath[k] = pathTemp[k];  
                    }     
            index--;
            checked[j]=0;  
        }                    
    }    
}
//-----------------input----------------------------------------------
void inputGraph(char* fileName)
{
    ifstream inFile(fileName);
    inFile>>numOfNodes;
    inFile>>start;
    
    weight = new float*[numOfNodes];
    for(int i=0;i<numOfNodes;i++) weight[i] = new float [numOfNodes];
    for(int i=0;i<numOfNodes;i++)
       for(int j=0;j<numOfNodes;j++) weight[i][j]=infinite;   
    int i=0,j=0;
    float x;
    while(!inFile.eof()){
        inFile>>i>>j>>x;
        weight[i-1][j-1]=x;
    } 
    minPathLength= numOfNodes*infinite; //initialize minPathlength with a large value
    checked = new bool[numOfNodes];
    pathTemp = new int[numOfNodes];
    minPath = new int [numOfNodes];
    for(int i=0;i<numOfNodes;i++) {
        pathTemp[i]=minPath[i]=-1;
        checked[i]=0;
    }
    pathTemp[index++] = start-1;
    checked[start-1]=1;                         
}     
//----------------write output to file-------------------------------------------
void outputToFile(char* fileName)
{
    ofstream outFile(fileName);
    if(minPathLength < infinite){ 
        outFile<<minPathLength<<endl;
        for(int i=0;i<numOfNodes;i++) outFile<<minPath[i]+1<<" ";
    }    
    else outFile<<"infinite"<<endl;     
}  
//---------------------------------------------------------------------------  
int main()
{
    inputGraph("tsp.in");  
    findPath(start-1);
    outputToFile("tsp.out");
    delete [] checked,pathTemp,minPath;
    delete [] weight;
    return 0;   
}        
    
