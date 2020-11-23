#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mi,int high)
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
int arr[100],tem[100],size;
int year,month,day;
int Year,Month,Day,remainder;
cout<<"Enter People Number : ";
cin>>size;
for(int i=0;i<size;i++)
{
    cout<<"Enter "<<i+1<< " Number Persons Birthday Year : ";
    cin>>year;
    cout<<"Enter "<<i+1<< " Number Persons Birthday Month : ";
    cin>>month;
    cout<<"Enter "<<i+1<< " Number Persons Birthday Date : ";
    cin>>day;
    arr[i]=(year*365)+(month*30)+day;
    tem[i]=arr[i];
}

devide(arr,0,size-1);
cout<<"Shorted Age's Are : "<<endl;
for(int i=0;i<size;i++)
{
   int position;
   for(int j=0;j<size;j++)
   {
       if(arr[i]==tem[j])
       {
         position=j+1;
       }

   }
   Year =arr[i]/365;

if (arr[i]%365!=0)
{

    remainder=arr[i]%365;
    Month=remainder/30;
    if(remainder%30!=0)
    {
        Day=arr[i]-((Year*365)+(Month*30));

    }
    else
    {
        Day=0;
    }
}
else
{
    Month=0;
    Day=0;
}

    cout<<Year<<" Year "<<Month<<" Month "<<Day<<" Day ("<<position<<" Number Person)"<<endl;

}

return 0;
}
