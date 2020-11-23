#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int coinSize;
cout<<"Enter Size of N : "<<endl;
cin>>n;
cout<<"Enter Coin Number : "<<endl;
cin>>coinSize;
int coins[coinSize];
cout<<"Enter Coins : "<<endl;
for(int i=0;i<coinSize;i++){
    cin>>coins[i];
}
int table[coinSize+1][n+1];
for(int i=0;i<=coinSize;i++){
 for(int j=0;j<=n;j++){
  if(i==0 && j==0){
            table[i][j]=1;
        }
        else if (i==0 && j>0){
            table [i][j]=0;
        }
        else if (i>0 && j==0){
            table [i][j]=1;
        }
        else {
           int exclude;
           int include;
           int incl;
            exclude=table[i-1][j];
            incl=j-coins[i-1];
            if(incl>=0){
                include=table[i][incl];
                table[i][j]=exclude+include;
            }
            else{
                table[i][j]=exclude;
            }
        }
    }
}
cout<<"Solution's Are : "<<endl;
cout<<endl;
for ( int i = 0; i <=coinSize; i++ ){
    for ( int j = 0; j <=n; j++ ) {
         cout << table[i][j]<<"\t";
      }
      cout<<endl;
}
cout<<endl;
cout<<"Optimal Solution Is : "<<table[coinSize][n]<<endl;
return 0;
}
