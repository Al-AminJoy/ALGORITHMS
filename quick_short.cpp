#include<bits/stdc++.h>
using namespace std;
int quick_short(int arr[],int start,int ending){
int pivot=arr[ending];
int i=start-1;

for(int j=start;j<=ending;j++)
{
    if(arr[j]<pivot)
    {
        i++;
        swap(arr[i],arr[j]);
    }
}
i++;
swap(arr[i],arr[ending]);
return i;

}
void devide(int Arr[],int Start,int End)
{
    int temp;
    if(Start>=End)
    {
        return;
    }
    else
    {
        temp=quick_short(Arr,Start,End);
        devide(Arr,Start,temp-1);
        devide(Arr,temp+1,End);
    }
}
int main()
{
    int size;
    cout<<"How Many Number Want To Enter : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter "<<i+1<<" Number Element : ";
        cin>>arr[i];
    }
    devide(arr,0,size-1);
   cout<<"Shorted Array's Are : "<<endl;

     for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
}
 return 0;
}
