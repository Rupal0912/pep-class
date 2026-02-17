#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2){
    unordered_set <int> s(nums1.begin(), nums1.end());
    unordered_set<int> res;
    for(int num: nums2){
        if(s.find(num) != s.end()){
            res.insert(num);
        }
    }
    return vector<int> (res.begin(), res.end());
}
int main(){
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> result=intersect(nums1, nums2);
    for(int num: result){
        cout << num << " ";
    }
}