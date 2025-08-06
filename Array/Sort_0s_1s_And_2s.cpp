#include<bits/stdc++.h>
using namespace std;

vector<int> SortOptimal(vector<int> &nums){
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid < high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        if(nums[mid] == 1){
            mid++;
        }
        if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;
}

vector<int> SortBetter(vector<int> &nums){

    vector<int> count(3, 0);
    for(int num:nums){
        count[num]++;
    }

    int index = 0;
    for(int i = 0; i < 3; i++){
        while(count[i]-- > 0){
            nums[index] = i;
            index++;
        }
    }
    return nums;
}

int main(){

    vector<int> nums = {2,1,2,0,1,0,2,0,2,1,0,1,2,0,1,0,0,1,1,1,2,0,2,0,1};

    SortOptimal(nums);
    for(auto it:SortOptimal(nums)){
        cout<<it<<" ";
    }

    cout<<endl;
    
    SortBetter(nums);
    for(auto it:SortBetter(nums)){
        cout<<it<<" ";
    }

    return 0;
}