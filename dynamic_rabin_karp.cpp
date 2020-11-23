#include<bits/stdc++.h>
using namespace std;
int main()
{
    string textInput;
    string keyInput;
    int prime=3;
    cout<<"Enter Text : ";
    cin>>textInput;
    cout<<"Enter The Pattern : ";
    cin>>keyInput;
    int textSize=textInput.length();
    char text[textSize];
    strcpy(text, textInput.c_str());

    int keySize=keyInput.length();
    char key[keySize];
    strcpy(key, keyInput.c_str());
    int keySum=0;
    for(int i=0; i<keySize; i++)
    {
        int result;
        if (i==0)
        {
            keySum=keySum+(int(key[i]));
        }
        else
        {
            result=(int(key[i]))*(pow(prime,i));
            keySum=keySum+result;
        }

    }
    int textSum=0;
    for(int i=0; i<keySize; i++)
    {
        int result;
        if (i==0)
        {
            textSum=textSum+(int(text[i]));
        }
        else
        {
            result=(int(text[i]))*(pow(prime,i));
            textSum=textSum+result;
        }

    }
    if(keySum==textSum)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        int result;
        bool find=false;
        for(int i=1; i<textSize-(keySize-1); i++)
        {
            result=textSum-(int(text[i-1]));
            result=result/prime;
            result=result+((int(text[i+(keySize-1)]))*(pow(prime,keySize-1)));
            textSum=result;
            if(result==keySum)
            {
                find=true;
                break;
            }
        }
        cout<<endl;
        if(find==true)
        {
            cout<<"This Pattern Exist in This Text"<<endl;
        }
        else
        {
            cout<<"This Pattern Doesn't Exist in This Text"<<endl;
        }

    }
    return 0;

}

