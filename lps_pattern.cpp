#include<bits/stdc++.h>
using namespace std;
void createTable(char patt[],int lpsSize){
    int lps[lpsSize];
    int i,j;
    i=0;
    j=1;
    lps[0]=0;

    for(int x=0;x<lpsSize;x++){

      if(patt[i]==patt[j]){
        lps[j]=i+1;
        i++;
        j++;
      }
      else {
         if((patt[i]!=patt[j]) && i==0){
            lps[j]=0;
            j++;
         }
         else{
            i=lps[i-1];

         }
      }
    }
    cout<<"LPS Table : "<<endl<<endl;
    for(int p=0;p<lpsSize;p++){
        cout<<lps[p]<<"\t";
    }

}
int main()
{
    string keyInput="seualamincse";
    int keySize=keyInput.length();
    char pattern[keySize];
    strcpy(pattern, keyInput.c_str());
    cout<<"Pattern Is : "<<endl<<endl;
    cout<<keyInput<<endl;
    cout<<endl;

    createTable(pattern,keySize);

   return 0;
}
