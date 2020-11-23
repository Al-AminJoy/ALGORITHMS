#include<bits/stdc++.h>
using namespace std;
int main(){
    int towerSize;
    cout<<"Enter Tower's Number :" ;
    cin>>towerSize;
    int people[towerSize];
    int peopleCopy[towerSize];
    people[0]=0;
    int towers[towerSize];

    for(int i=1;i<=towerSize;i++){
      cout<<"Enter People of Tower "<<i<<" : ";
      cin>>people[i];
    }
     for(int i=0;i<=towerSize;i++){
      peopleCopy[i]=people[i];
    }
     for (int i=2;i<=towerSize;i++){
        people[i]=std::max(people[i-1],(people[i]+people[i-2]));

     }
     cout<<"Max Served People :" ;
     for(int i=0;i<=towerSize;i++){
      cout<<people[i]<<endl;
    }

    cout<<"Used Towers :" ;
    int j =towerSize;
    while(j>0){
        if((people[j]-peopleCopy[j])==people[j-2]){
        cout<<j<<"\t";
        j=j-2;
      }
      else{
        cout<<j-1<<"\t";
        j=j-1;
      }

    }

return 0;
}
