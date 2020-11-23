#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int setSize;
cout<<"Enter Size of Sum : "<<endl;
cin>>n;
cout<<"Enter Size of Set : "<<endl;
cin>>setSize;
int element[setSize];
cout<<"Enter Set's Element : "<<endl;
for(int i=0;i<setSize;i++){
    cin>>element[i];
}
bool table[setSize+1][n+1];
for(int i=0;i<=setSize;i++){
 for(int j=0;j<=n;j++){
      if(i==0 && j==0){
        table[i][j]=true;
      }
      else if(i==0 && j>0){
        table[i][j]=false;
      }

      else{
            if(j>=element[i-1])
      {
          int sum;
            sum=j-element[i-1];
            table[i][j]=table[i-1][sum];
      }
      else{
        table[i][j]=table[i-1][j];
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
if(table[setSize][n]==true){
  cout<<"There Exist At Least One Subset Who's Element Sum Up To The Given Sum "<<endl;
}
else{
  cout<<"There Doesn't Exist Any Subset Who's Element Sum Up To The Given Sum "<<endl;
}
return 0;
}
