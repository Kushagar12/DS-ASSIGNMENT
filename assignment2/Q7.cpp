#include<iostream>
using namespace std;
int main(){
    int arr[9]={1,8,9,1,4,0,18,34,20};
    int count=0;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<"No. of inversion: "<<count<<endl;

    return 0;
}