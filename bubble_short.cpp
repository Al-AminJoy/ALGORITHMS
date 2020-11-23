#include<iostream>
using namespace std;
int main(){
int arr[50], temp,n;
cout<<"Enter Number You Want To Input : ";
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
        if (arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            /*Also can try this for swap
            swap(arr[j],arr[j+1])*/
        }
    }

}

cout<<"Shorted Numbers Are : ";
for(int i=0;i<n;i++)

{
    cout<<arr[i]<<" " ;
}


return 0;

}
