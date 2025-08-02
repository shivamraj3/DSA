#include<bits/stdc++.h>
using namespace std;

int MissingBrute(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i <= n; i++){

        int flag = 0;
        for(int j = 0; j<n; j++){
            if(nums[j] == i){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            return i;
        }
    }
}

int MissingBetter(vector<int> &nums){
    int n = nums.size();
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++){
        hash[nums[i]] = 1;
    }

    for(int i = 0; i <= n; i++){
        if(hash[i] == 0){
            return i;
        }
    }

    return -1;
}

int missingOptimal1(vector<int> &nums){
    int n = nums.size();
    int target = (n * (n+1))/2;
    int sum = 0;
    int missing=0;
    for(int i =0; i < n; i++){
        sum = sum + nums[i];
    }    

    missing = target - sum;

    return missing;
}

int missingOptimal2(vector<int> &nums){
    int N = nums.size();
    int xor1 = 0, xor2 = 0;

    for(int i=0; i<N; i++){
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i+1);
    }

    // xor1 = xor1 ^ N;
    return xor1 ^ xor2;

}

int main(){

    vector<int> nums = { 3, 1, 0, 4, 5};

    // cout<<MissingBrute(nums);
    // cout<<MissingBetter(nums);
    // cout<<missingOptimal1(nums);
    cout<<missingOptimal2(nums);

    return 0;
}