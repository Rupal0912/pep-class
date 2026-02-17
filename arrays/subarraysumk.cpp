#include<iostream>
using namespace std;
int subarraysum(int arr[], int n,int k){
  
  int count=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=arr[j];
        if(sum==k) count++;
    }
  }
  return count;
}

int main(){
    int arr[]={1,-1,0};
    int n=3;
    int k=0;
    cout << subarraysum(arr, n, k);
}