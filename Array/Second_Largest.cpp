#include<bits/stdc++.h>
using namespace std;

int secondSmallest(vector<int>& arr){
    int smallest = arr[0];
    int secsmall = INT_MAX;
    
    for(int i =1; i < arr.size(); i++){
        if(arr[i] < smallest){
            secsmall = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < secsmall){
            secsmall = arr[i];
        }
    }

    if( secsmall == INT_MAX){
        return -1;
    }
    else{       
        return secsmall;
    }
}

int main(){

    vector<int> arr = {1, 3, 5, 7, 7, 9, 11};

    int result = secondSmallest(arr);

    cout<<result;

    return 0;
}