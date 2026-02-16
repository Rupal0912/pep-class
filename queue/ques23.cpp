#include <iostream>
#include <unordered_map>
#include<queue>
using namespace std;

vector<int> firstnonrepeating(const vector<int>& stream){
    unordered_map<int, int> freq;
    vector<int> result;
    queue<int> q;
    for(int nums: stream){
        freq[nums]++;

        q.push(nums);
        while(!q.empty() && freq[q.front()]>1){
            q.pop();
        }
        if(q.empty()){
            result.push_back(-1);

        }
        else{
            result.push_back(q.front());
        }

    }
    return result;

}