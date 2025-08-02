#include<bits/stdc++.h>
using namespace std;

int Ones(vector<int> &nums){

    int count = 0, max = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1){
            count++;
        }
        else if(nums[i] == 0){
            if(max < count){
                max = count;
                count = 0;
            }
        }
    }

    if( max < count){
        max = count;
    }

    return max;
}

int OnesBetter(vector<int> &nums){
    int maxi = 0; 
    int count = 0;

    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxi = max(maxi, count);
        }
        else{
            count = 0;
        }
    }

    return maxi;
}

int main(){

    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1};

    // cout<<Ones(nums);
    cout<<OnesBetter(nums);

    return 0;
}