#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector <int> freqord(vector<int> arr){
    unordered_map<int, int> mp;
   
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    vector<pair<int, int>>v;
    for(auto it: mp){
        v.push_back(it);
    }
    sort(v.begin(), v.end(),[](auto &a, auto &b){
        return a.second> b.second;
    });
    vector<int> res;
    for(auto &it: v){
        res.push_back(it.first);
    }
    
    return res;

}
int main(){
    vector<int> arr = {4,6,4,3,6,4,2};
    vector<int> res = freqord(arr);
    cout<<"Elements in frequency order: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
