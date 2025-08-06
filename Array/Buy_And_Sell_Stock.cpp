#include<bits/stdc++.h>
using namespace std;

int MaxProfitBrute(vector<int> &nums){
    int profit = 0;

    for(int i = nums.size() - 1; i > 0; i--){
        for(int j = i; j >= 0; j--){
            profit = max(profit, nums[i] - nums[j]);
        }
    }

    if(profit == 0){
        return 0;
    }
    else{
        return profit;
    }
}

int MaxProfitOptimal(vector<int> &nums){
    int profit = 0, mini = nums[0];

    for(int i = 1; i < nums.size(); i++){
        profit = max(profit, nums[i] - mini);
        mini = min(mini, nums[i]);
    }

    if(profit == 0){
        return 0;
    }
    else{
        return profit;
    }
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    cout<<MaxProfitBrute(prices);
    cout<<MaxProfitOptimal(prices);

    return 0;
}