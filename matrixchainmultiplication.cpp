#include<iostream>
using namespace std;

void chained(int n,int d[]){
  int m[n+1][n+1],s[n+1][n+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        m[i][j]=0;
        s[i][j]=0;
    }
  }
  
  for(int diag=1;diag<n;diag++){
    for(int i=1;i<=n-diag;i++){
      int j=i+diag;
      int smol=999;
      for(int k=i;k<j;k++){
        int q=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
        if(q<smol){
          smol=q;
          s[i][j]=k;
        }
      }
      m[i][j]=smol;
    }
  }
  //m matrix output
  /*for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
          cout<<m[i][j]<<" ";
      }
      cout<<endl;
  }*/
  
  cout<<"Minimum number of multiplications are : "<<m[1][n];
  
}

int main(){
  int n;
  cout<<"Enter the number of matrices : ";
  cin>>n;
  int d[n+1],temp;
  cout<<"Enter the order of the matrices : "<<endl<<"matrix 1 :";
  cin>>d[0]>>d[1];
  for(int i=2;i<=n;i++){
    cout<<"matrix "<<i<<" : ";
    cin>>temp>>d[i];
  }
  
  chained(n,d);
  
  return 0;
}
