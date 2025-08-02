#include<bits/stdc++.h>
using namespace std;

vector<int> UnionOptimal(vector<int> &a, vector<int> &b){

    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> UnionArray;

    while(i < n1 & j < n2){
        if(a[i] <= b[j]){
            if(UnionArray.size() == 0 || UnionArray.back() != a[i]){
                UnionArray.push_back(a[i]);
            }
            i++;
        }
        else{
            if(UnionArray.size() == 0 || UnionArray.back() != b[j]){
                UnionArray.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(UnionArray.size() == 0 || UnionArray.back() != a[i]){
            UnionArray.push_back(a[i]);
        }
        i++;
    }

    while(j < n2){
        if(UnionArray.size() == 0 || UnionArray.back() != b[j]){
            UnionArray.push_back(b[j]);
        }
        j++;
    }

    return UnionArray;
}

vector<int> UnionBrute(vector<int> &a, vector<int> &b){
    set<int> st;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> UnionArray;

    for(int i = 0; i<n1; i++){
        st.insert(a[i]);
    }

    for(int i = 0; i<n2; i++){
        st.insert(b[i]);
    }

    for( auto it: st){
        UnionArray.push_back(it);
    }

    return UnionArray;
}

int main(){

    vector<int> a = {1, 1, 2, 3, 4, 4, 5, 6, 7,7 ,8,9};
    vector<int> b = {1,10, 11, 12, 12, 15};

    // vector<int> Union = UnionOptimal(a, b);
    vector<int> Union = UnionBrute(a, b);
    for(auto it: Union){
        cout<<it<<" ";
    }

    return 0;
}