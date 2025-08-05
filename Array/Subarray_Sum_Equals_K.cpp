#include<bits/stdc++.h>
using namespace std;

int SubArrayCount(vector<int> &nums, int k){

    int n = nums.size();
    int len = 0;

    for(int i = 0; i < n; i++){

        for(int j = i; j < n; j++){

            int sum = 0;
            for(int k = i; k < j; k++){

                sum += nums[k];
            }

            if(sum == k){
                len++;
            }
        }
    }
    
    return len;

}

int SubArrayBrute1(vector<int> &nums, int k){

    int n = nums.size();
    int len = 0;

    for(int i = 0; i < n; i++){

        for(int j = i; j < n; j++){

            int sum = 0;
            for(int k = i; k < j; k++){

                sum += nums[k];
            }

            if(sum == k){
                len = max(len, j - i + 1);
                return len;
            }
        }
    }

}

int SubArrayBrute2(vector<int> &nums, int k){

    int n = nums.size();
    int len = 0;

    for(int i = 0; i < n; i++){

        int sum = 0;
        for(int j = i; j < n; j++){

            sum += nums[j];
            
            if(sum == k){
                len = max(len, j - i + 1);
            }
        }
    }
    return len;

}

int SubArrayBetter(vector<int> &nums, int k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if( sum == k ){
            maxLen = max( maxLen, i+1 );
        }

        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max( len, maxLen );
        }

        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int SubArrayOptimal(vector<int> &nums, int k){
    int left = 0;
    int right = 0;
    long long sum = nums[0];
    int maxLen = 0;

    while ( right < nums.size()){
        while( left <= right && sum > k){
            sum -= nums[left];
            left++;
        }

        if( sum == k){
            maxLen = max( maxLen, right - left + 1);
        }
        right++;

        if( right < nums.size() ){
            sum += nums[right];
        }
    }
    
    return maxLen;
}



int main(){

    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 2, 1, 3};
    int k = 3;

    // cout<<SubArrayCount(nums, k);
    // cout<<SubArrayBrute1(nums, k);
    // cout<<SubArrayBrute2(nums, k);
    cout<<SubArrayBetter(nums, k);
    cout<<SubArrayOptimal(nums, k);

    return 0;
}