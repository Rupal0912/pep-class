#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int arr[]= {1,2,2,3,6,6,7,8};
     int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
//     cout<<"After removing duplicates";
//     unordered_map<int, int> mp;
//     for(int i=0;i<n;i++){
//         mp[arr[i]]++;
//     }
//    for(auto it : mp) {
//         cout << it.first << " ";
//     }
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    cout<<endl;
    cout<<"After removing duplicates: ";
    
     for(int k = 0; k <= i; k++){
        cout << arr[k] << " ";
    }


}