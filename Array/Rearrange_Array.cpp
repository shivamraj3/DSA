#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangeBrute(vector<int> &nums){
    vector<int> positive;
    vector<int> negative;
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
            positive.push_back(nums[i]);
        }
        else{
            negative.push_back(nums[i]);
        }
    }
    
    for(int i = 0; i < nums.size()/2; i++){
        nums[2 * i] = positive[i];
        nums[2 * i + 1] = negative[i];
    }
    return nums;
}

vector<int> RearrangeOptimal(vector<int> &nums){
    int positive = 0;
    int negative = 1;
    int n = nums.size();

    vector<int> result(n, 0);

    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            result[positive] = nums[i];
            positive+=2;
        }
        else{
            result[negative] = nums[i];
            negative += 2;
        }
    }

    return result;
}

int main(){

    vector<int> nums = {3,1,-2,-5,2,-4};

    RearrangeBrute(nums);
    for(auto it:RearrangeBrute(nums)){
        cout<<it<<" ";
    }

    cout<<endl;
    
    RearrangeOptimal(nums);
    for(auto it:RearrangeOptimal(nums)){
        cout<<it<<" ";
    }

    return 0;
}