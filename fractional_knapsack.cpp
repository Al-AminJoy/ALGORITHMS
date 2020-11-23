#include<bits/stdc++.h>
using namespace std;
struct goods {
double w,p,u;

};
bool cmp(goods a,goods b){
if(a.u>b.u) return true;
else return false;
}

int main(){
int W,P=0,size;
cout<<"Enter Element Number : ";
cin>>size;
goods arr[size];
for(int i=0;i<size;i++){
    cin>>arr[i].w>>arr[i].p;
    arr[i].u=arr[i].p/arr[i].w;
}
sort(&arr[0],&arr[size],cmp);
cout<<"Enter Max Weight : ";
cin>>W;
for(int i=0;i<size;i++){

    if(W>arr[i].w)
    {
        P=P+arr[i].p;
        W=W-arr[i].w;

    }
    else {
        P=P+W*arr[i].u;
        W=0;
    }
}
cout<<"Optimal Solution : "<<P;
return 0;
}
