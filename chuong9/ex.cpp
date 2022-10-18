// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

#define INF 9999999

// number of vertices in grapj
#define V 7


// create a 2d array of size 5x5
//for adjacency matrix to represent graph
//
void input (int a[][V]){
   for (int i=0;i<V;i++){
       a[i][i]=0;
      for (int j=0;j<i;j++){
           
        
            a[i][j]=rand()%100;
            a[j][i]=a[i][j];
         
      }
   }
}

void  minDistance(int U[], bool sptSet[],int G[][V]){
   int min=INF;
   int index;
   int start;
   int i=0;
   while(U[i]<V) {
      int z=U[i];
         for(int j=0;j<V;j++){
            if (!sptSet[j] && G[z][j]!=0 && min>G[z][j]){
               min=G[z][j];
               index=j;
               start=z; 
            }
         }
      i++;
   }
      U[i]=index;
     sptSet[index]=true;
   cout << start << "-"<< index << ":"<< min<< endl;
}
void prim(int src,int G[][V]){
   bool sptSet[V];
   int U[V];
   for (int i=0;i<V;i++){
      sptSet[i]=false;
      U[i]= V;
   }
   sptSet[src]=true;
   U[0]=src;
   for (int i=0;i<V-1;i++)
   minDistance(U,sptSet,G);
}

int main() {

int a[V][V];
input(a);
for(int i=0;i<V;i++){
   for(int j=0;j<V;j++){
      cout << a[i][j]<<"\t";
   }
   cout << endl;
}
  prim(0,a);


  return 0;
}