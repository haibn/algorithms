// Ho ten :  Bui Ngoc Hai
// lop :     K51CD
// bai tap : TravelingSalesmanProblem

#include<fstream>

using namespace std;

const int infinite = 32000;

int    numOfPoint,start;
bool   *checked;
int    *pathTemp,index=0; //mang luu duong di tam thoi va index la chi so cua no
int    *minPath;         // mang luu duong di ngan nhat
float  minPathLength=0;  // do dai duong di ngan nhat
float  **weight;

//---------------tim do dai cua duong di khi di qua tat ca cac dinh--------------------------
float pathLength(int* path,int n)
{
    float length =weight[path[n-1]][path[0]];
    for(int i=0;i<n-1;i++){
        length += weight[path[i]][path[i+1]];
    }    
    return length;    
}
//-------------tim duong di ngan nhat qua tat ca cac dinh, bat dau tu dinh i------------------
void findPath(int i)
{
    for(int j=0;j<numOfPoint;j++){
        if(weight[i][j]<infinite && checked[j]==0)
        {
            pathTemp[index++] = j;
            checked[j] = 1;
            if(index < numOfPoint) findPath(j);
               else if(pathLength(pathTemp,numOfPoint) < minPathLength)
                    {
                       minPathLength = pathLength(pathTemp,numOfPoint);        
                       for(int k=0; k < numOfPoint; k++) minPath[k] = pathTemp[k];  
                    }     
            index--;
            checked[j]=0;  
        }                    
    }    
}
//-----------------nhap cac thong so cua do thi----------------------------------------------
void inputGraph(char* fileName)
{
    ifstream inFile(fileName);
    inFile>>numOfPoint;
    inFile>>start;
    
    weight = new float*[numOfPoint];
    for(int i=0;i<numOfPoint;i++) weight[i] = new float [numOfPoint];
    for(int i=0;i<numOfPoint;i++)
       for(int j=0;j<numOfPoint;j++) weight[i][j]=infinite;   
    int i=0,j=0;
    float x;
    while(!inFile.eof()){
        inFile>>i>>j>>x;
        weight[i-1][j-1]=x;
    } 
    minPathLength= numOfPoint*infinite; //khoi tao cho minPathlength 1 gia tri lon
    checked = new bool[numOfPoint];
    pathTemp = new int[numOfPoint];
    minPath = new int [numOfPoint];
    for(int i=0;i<numOfPoint;i++) {
        pathTemp[i]=minPath[i]=-1;
        checked[i]=0;
    }
    pathTemp[index++] = start-1;
    checked[start-1]=1;                         
}     
//----------------ghi ket qua ra file-------------------------------------------
void outputToFile(char* fileName)
{
    ofstream outFile(fileName);
    if(minPathLength < infinite){ 
        outFile<<minPathLength<<endl;
        for(int i=0;i<numOfPoint;i++) outFile<<minPath[i]+1<<" ";
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
    
