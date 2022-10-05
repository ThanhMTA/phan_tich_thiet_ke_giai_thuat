#include<iostream>
#include<cstdlib>
using namespace std;
int a[100];
int f[100];
int n=6;
void input(){
    for (int i=1;i<n;i++){

         a[i]=rand()%10 +1;
    }

}
void output (int b[]) {
    for (int i=0;i<n;i++){
        cout << b[i]<<"\t";
    }
}
int max(int a, int b){
    if (a>=b)
        return a;
    else 
        return b;
}
int  coinRow(){
  input();
  cout <<"\n";
    output(a);
    f[0]=0;
    f[1]=a[1];
    int i=0;
    for (i=2;i<n;i++){
        f[i]=max(a[i]+f[i-2],f[i-1]);
       
    }
    return f[i];
}

int main(){
  
  
   coinRow();
   cout <<"\n";

   output(f);
   
  
  
}