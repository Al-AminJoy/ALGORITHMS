#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int setSize;
cout<<"Enter Total Rod Size : "<<endl;
cin>>n;
cout<<"Enter Number of Sizes : "<<endl;
cin>>setSize;
int element[setSize];
int profit[setSize];
cout<<"Enter Size's : "<<endl;
for(int i=0;i<setSize;i++){
    cin>>element[i];
}
for(int i=0;i<setSize;i++){
    cout<<"Enter Profits of "<<element[i]<<" Size : "<<endl;
    cin>>profit[i];
}
int table[setSize+1][n+1];
for(int i=0;i<=setSize;i++){
 for(int j=0;j<=n;j++){
      if(i==0 || j==0){
        table[i][j]=0;
      }

      else if(j<element[i-1]){
        table[i][j]=table[i-1][j];
      }

      else{
            int exclude;
            int prof;
            prof=profit[i-1];
            int include;
            exclude=table[i-1][j];
            include=j-element[i-1];
            prof=prof+table[i][include];

            if(include>=0){


            }
            if(prof>exclude){
                table[i][j]=prof;
            }
            else{
               table[i][j]=exclude;
            }

      }

      }

    }
cout<<"Solution's Are : "<<endl;
cout<<endl;
for ( int i = 0; i <=setSize; i++ ){
    for ( int j = 0; j <=n; j++ ) {
         cout << table[i][j]<<"\t";
      }
      cout<<endl;
}
cout<<endl;
cout<<"Maximum Profit Can Be : "<<table[setSize][n]<<endl;
return 0;
}
