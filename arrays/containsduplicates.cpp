#include<iostream>
#include<unordered_set>

using namespace std;
bool containsdup(vector<int>& arr)
{
    int n= arr.size();
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])!=s.end()){
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    cout << containsdup(arr);
}