#include<bits/stdc++.h>
using namespace std;

int UniqueBrute(vector<int> &arr){

    set<int> st;
    for(int i =0; i< arr.size(); i++){
        st.insert(arr[i]);
    }

    int idx = 0;
    for(auto it: st){
        arr[idx] = it;
        idx++;
    }

    return idx;
}

int UniqueOptimal(vector<int> &arr){
    int i =0;

    for(int j=1; j< arr.size(); j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){

    vector<int> v = {1,1,2};
    int l = UniqueBrute(v);
    int k = UniqueOptimal(v);

    cout<<l<<" "<<k<<endl;

    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }



    return 0;
}
