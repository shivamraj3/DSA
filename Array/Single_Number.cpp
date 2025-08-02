#include<bits/stdc++.h>
using namespace std;

    int SingleNumberBrute(vector<int> &nums){

        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j< n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }    

            if(count == 1){
                return nums[i];
            }
        }
    }

    
    int SingleNumberBetter1(vector<int> &nums){

        int maxi = nums[0];

        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }

        vector<int> hash(maxi, 0);
        for(int i = 0; i< nums.size(); i++){
            hash[nums[i]]++;
        }

        for(int i = 0; i< nums.size(); i++){
            if(hash[nums[i]] == 1){
                return nums[i];
            }
        }

        return -1;
    }

    int SingleNumberBetter2(vector<int> &nums){
        
        map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }

        for(auto it: freq){
            if(it.second == 1){
                return it.first;
            }
        }

        return -1;
    }

    int SingleNumberOptimal(vector<int> &nums){
        int Xor = 0;
        for(int i = 0; i < nums.size(); i++){
            Xor = Xor ^ nums[i];
        }

        return Xor;
    }
    

int main(){

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5, 5};

    // cout<<SingleNumberBrute(nums);
    // cout<<SingleNumberBetter1(nums);
    cout<<SingleNumberBetter2(nums);
    cout<<SingleNumberOptimal(nums);

    return 0;
}