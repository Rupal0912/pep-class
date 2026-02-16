#include<iostream>
#include<unordered_set>
using namespace std;

int printduplicates(vector<int>& arr){
    int n= arr.size();
    unordered_set<int,int> seen;
    for(int i=0;i<n;i++){
       if(seen.find(arr[i])!=seen.end()){
        return arr[i];
       }
       seen.insert(arr[i]);
    }
   
      return -1;  
}

