#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int low,int mi,int high)
{
    int temp[100];
    int start=low;
    int mid=mi+1;
    int Index=low;

    while(start<=mi && mid<=high)
    {
        if(arr[start]<arr[mid])
        {
            temp[Index]=arr[start];
            Index++;
            start++;
        }
        else{
            temp[Index]=arr[mid];
            Index++;
            mid++;
        }
    }
    while(start<=mi)
    {
        temp[Index]=arr[start];
         Index++;
        start++;
    }
    while(mid<=high)
    {
        temp[Index]=arr[mid];
        Index++;
        mid++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }

}

void devide(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    else{
        int mid=(start+end)/2;
        devide(arr,start,mid);
        devide(arr,mid+1,end);

        merge(arr,start,mid,end);
    }

}

int main(){
    int arr[100];
    int n;
    cout<<"Enter How Many Number You Want To Input : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    devide(arr,0,n-1);
    cout<<"Shorted Array : ";
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

return 0;
}

