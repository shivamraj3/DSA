#include<bits/stdc++.h>
using namespace std;

int MajorityBrute(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count > (nums.size()/2)){
            return nums[i];
        }
    }
    return -1;
}

int MajorityBetter(vector<int> &nums){
    map<int, int> mpp;
    for(int num:nums){
        mpp[num]++;
    }

    for(auto it:mpp){
        if(it.second > (nums.size()/2)){
            return it.first;
        }
    }
    return -1;
}

int MajorityOptimal(vector<int> &nums){
    int count = 0;
    int element = -1;

    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            element = nums[i];
            count = 1;
        }
        else if(element == nums[i]){
            count++;
        }
        else{
            count--;
        }
    }

    int freq = 0;
    for(int i = 0; i < nums.size(); i++){
        if(element == nums[i]){
            freq++;
        }
    }

    if(freq > (nums.size()/2)){
        return element;
    }
    return -1;
}

int main(){

    vector<int> nums = {3,2,3,2,7,3,7,3,3,3,2};

    cout<<MajorityBrute(nums);
    cout<<MajorityBetter(nums);
    cout<<MajorityOptimal(nums);

    return 0;
}