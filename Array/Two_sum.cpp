#include<bits/stdc++.h>

using namespace std;

int twoSum( int arr[], int n, int target)
{
    
    for(int i = 0; i < n; i++){
        int rem = target - arr[i];
        for(int j = 0; j < n; j++){
            if(rem == arr[j]){
                cout<<i<<" "<<j<<endl;
            }
            
        }
        
    }
}


// vector<int> twoSum(vector<int>& arr, int target){
//     int n = arr.size();

//     for(int i = 0; i<n; i++){

//         int rem = target - arr[i];
//         for(int j=0; j<n; j++){
//             if(rem == arr[j]){
//                 return {j, i};
//             }
//         }
//     }

//     return {};
// }




int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i< n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    twoSum(arr, n, target);

    // for(int i = 0; i < n; i++){
    //     int rem = target - arr[i];
        
    //     for(int j = 0; j < n; j++){
    //         if(rem == arr[j]){
    //             cout<<i<<" "<<j<<endl;
    //             break;
    //         }

    //     }
    //     break;
    // }

    
    return 0;
}