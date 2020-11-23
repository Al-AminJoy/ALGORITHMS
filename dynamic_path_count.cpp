#include<bits/stdc++.h>
using namespace std;
int main(){
int row;
int column;
cout<<"Enter Size of Row : "<<endl;
cin>>row;
cout<<"Enter Size of Column : "<<endl;
cin>>column;
int table[row][column];
int cost[row][column];
cout<<endl;
for ( int i = 0; i <row; i++ ){
    for ( int j = 0; j <column; j++ ) {
         cout<<"Enter The Weight of ["<<i<<","<<j<<"] : "<<endl;
         cin >>cost[i][j];
      }
}
for(int i=0;i<row;i++){
 for(int j=0;j<column;j++){
  if(i==0 || j==0){
            table[i][j]=1;
            if(i==0 && j>0){
               cost[i][j]=cost[i][j-1]+cost[i][j];
            }
            else if (i>0 && j==0){
                cost[i][j]=cost[i][j]+cost[i-1][j];
            }
        }
        else {
           table[i][j]=table[i-1][j]+table[i][j-1];
           if(cost[i-1][j]>cost[i][j-1]){
            cost[i][j]=cost[i][j]+cost[i][j-1];
           }
           else{
            cost[i][j]=cost[i][j]+cost[i-1][j];
           }
        }
    }
}
cout<<"Solution's of Path Count Are : "<<endl;
cout<<endl;
for ( int i = 0; i <row; i++ ){
    for ( int j = 0; j <column; j++ ) {
         cout << table[i][j]<<"\t";
      }
      cout<<endl;
}
cout<<endl;
cout<<"Total Path Counted :  "<<table[row-1][column-1]<<endl;
cout<<endl;
cout<<"Solution's of Minimum Cost Are : "<<endl;
cout<<endl;
for ( int i = 0; i <row; i++ ){
    for ( int j = 0; j <column; j++ ) {
         cout << cost[i][j]<<"\t";
      }
      cout<<endl;
}
cout<<endl;
cout<<"Minimum Cost  : "<<cost[row-1][column-1]<<endl;
return 0;
}
