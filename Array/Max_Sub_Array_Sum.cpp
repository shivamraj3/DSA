#include<bits/stdc++.h>
using namespace std;

int MaxSumBrute(vector<int> &nums){
    int maxSum = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum+=nums[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

int MaxSumBetter(vector<int> &nums){
    int maxSum = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        int sum = 0;

        for(int j = i; j < nums.size(); j++){
            sum+=nums[j];
            maxSum = max(sum, maxSum);
        }

    }

    return maxSum;
}

int MaxSumOptimal(vector<int> &nums){
    int sum = 0, maxSum = INT_MIN;
    
    for(int num:nums){
        sum+=num;

        maxSum = max(sum, maxSum);

        if(sum < 0){
            sum = 0;
        }
    }

    return maxSum;
}

pair<int, pair<int, int>> MaxSumLength(vector<int> &nums){
    int sum = 0, maxSum = INT_MIN;
    int start = 0, ansStart = -1, ansEnd = -1;
    
    for(int i = 0; i < nums.size(); i++){
        if(sum == 0){
            start = i;
        }

        sum+=nums[i];

        if(sum > maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return {maxSum, {ansStart, ansEnd}};
}

int main(){

    vector<int> nums = {-1, 2, 3, -4, 1, -5, 3, -2, 5, -1};

    cout<<MaxSumBrute(nums);
    cout<<MaxSumBetter(nums);
    cout<<MaxSumOptimal(nums);
    cout<<endl;
    cout<<MaxSumLength(nums).first;
    cout<<MaxSumLength(nums).second.first;
    cout<<MaxSumLength(nums).second.second;

    return 0;
}