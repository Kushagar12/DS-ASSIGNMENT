#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter rows: ";
    cin>>r;
    cout<<"Enter col:" ;
    cin>>c;
    int s=3*r-2;
    int arr[s];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int k=0;
    cout<<"Resultant matrix is: "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i-j==-1 || i==j || i-j==1){
                cout<<arr[k]<<" ";k++;
            }else cout<<"0"<<" ";
        }cout<<endl;
    }


    return 0;
}