// Prim's Algorithm in C++
//  5 test, tính thời gian 
//  đọc trc phần 9.4 
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

#define INF 9999999

// number of vertices in grapj
#define V 6


// create a 2d array of size 5x5
//for adjacency matrix to represent graph

void input (int a[][V]){
   for (int i=0;i<V;i++){
       a[i][i]=0;
      for (int j=0;j<i;j++){
           
        
            a[i][j]=rand()%100;
            a[j][i]=a[i][j];
         
      }
   }
}
// tim vi tri  nho nhat co khoang cach nho nhat 
int minDistance(int dist[], bool sptSet[]){
  int min= INF;
  int min_index;
  for (int i=0;i<V;i++){
    if (sptSet[i]==false && dist[i]<min){
      min=dist[i];
      min_index=i;
    }
  }
  sptSet[min_index]=true;
  return min_index;
}
void output(int dist[]){
  for (int i=1;i<V;i++){
    cout<< i <<"\t\t\t\t\t"<< dist[i]<<endl;
  }
}
// thuat toan tim cay khung nho nhat 
void dijkstra(int src,int G[][V]){
   int dist[V];// mang dau ra 
   bool sptSet[V];
   for (int i=0;i<V;i++){
    dist[i]=INF;
    sptSet[i]=false;
   }
   dist[src]=0;
   for (int i=0;i<V-1;i++){
      int u=minDistance(dist,sptSet);
      for(int j=0;j<V;j++){
        if(!sptSet[j] && G[u][j]!=0 && dist[u]+G[u][j]<dist[j])
        dist[j]=dist[u]+G[u][j];
      }
   }
   output(dist);

}
int  main (){
  int a[V][V];
  input(a);
  for(int i=0;i<V;i++){
   for(int j=0;j<V;j++){
      cout << a[i][j]<<"\t";
   }
   cout << endl;
}
  dijkstra(0,a);
}