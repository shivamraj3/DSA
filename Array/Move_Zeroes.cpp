#include<bits/stdc++.h>
using namespace std;

// void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;

//         for(int i = 0; i < n; i++){
//             if(nums[i] != 0){
//                 temp.push_back(nums[i]);
//             }
//         }

//         int zero = n - temp.size();

//         for(int i = 0; i < temp.size(); i++){
//             nums[i] = temp[i];
//         }

//         for(int i = n - zero; i < n; i++){
//             nums[i] = 0;
//         }
//     }

void moveZeroesOptimal(vector<int> &nums){

    int j = -1;
    int n = nums.size();
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }

    for(int i = j+1; i < n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

   int main(){

    vector<int> nums = {0, 1, 0, 3, 12};

    // moveZeroes(nums);
    moveZeroesOptimal(nums);

    for(int i=0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }

    return 0;
   }