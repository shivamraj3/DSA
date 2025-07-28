#include<bits/stdc++.h>
using namespace std;

void rotateArrLeft( vector<int>& arr, int d){
    int n = arr.size();

    d%n;

    reverse(arr.begin(), arr.begin() + d);

    reverse(arr.begin() + d, arr.end());

    reverse(arr.begin(), arr.end());
}

void rotateArrRight( vector<int>& arr, int d){
    int n = arr.size();

    d%n;

    reverse(arr.end()-d, arr.end());

    reverse(arr.begin(), arr.end()-d);

    reverse(arr.begin(), arr.end());
}

int main(){
    
    vector<int> arr = {1, 2, 3, 4, 5, 6 };
    int d = 2;

    // rotateArrLeft(arr, d);
    rotateArrRight(arr, d);

    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i] << " ";
    }

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i = 0; i<n;i++){
    //     cin>>arr[i];
    // }
    // int d;
    // cin>>d;

    // d = d%n;

    // for(int i=0; i<d;i++){

    //     int temp = arr[n-1];
    //     for(int j = n-1; j>0; j--){
    //         arr[j] = arr[j-1];
    //     }
    //     arr[0]=temp;
    // }

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}