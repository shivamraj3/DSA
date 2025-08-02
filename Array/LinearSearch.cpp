#include<bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> &arr, int target){
    int n = arr.size();

    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){

    vector<int> nums = {1, 3 ,4 ,5,3,3 , 6,8,96,66,5,45,23};

    int index = LinearSearch(nums, 96);
    cout<<index;


    return 0;
}