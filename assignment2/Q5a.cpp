#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter no. of rows:";
    cin>>r;
    cout<<"Enter no. of col: ";
    cin>>c;
    int arr[r];
    cout<<"Enter Diagonal Elements of matrix: ";
    for(int i=0;i<r;i++){
        cin>>arr[i];
    }
    cout<<"Your resultant matrix is: "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }else cout<<"0"<<" ";
        }cout<<endl;
    }

    return 0;
}