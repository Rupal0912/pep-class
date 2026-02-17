#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
pair<int,int> complimentpairsum(vector<int> &arr, int T, int k){
    // vector<pair<int, int>> res;
    for(int i=0;i<arr.size();i++){
        for(int j= i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==T && abs(i-j)>=k){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}
int main(){
    vector<int> arr = {2,7,11,15};
    int T = 9;
    int k = 1;
    pair<int,int> res = complimentpairsum(arr,T,k);
    if(res.first != -1){
        cout<<"Pair found at indices: "<<res.first<<" and "<<res.second<<endl;
    } else {
        cout<<"No pair found."<<endl;
    }
    return 0;
}
