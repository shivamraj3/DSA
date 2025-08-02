#include<bits/stdc++.h>
using namespace std;

vector<int> IntersectionBrute(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int visited[n2] = {0};
    vector<int> Intersect;
    
    for(int i = 0; i < n1; i++){
        for( int j = 0; j < n2; j++){
            if(a[i] == b[j] && visited[j] == 0){
                Intersect.push_back(b[j]);
                visited[j] = 1;
                break;
            }
            if(b[j] > a[i]){
                break;
            }
        }
    }   

    return Intersect;
}

vector<int> IntersectionOptimal(vector<int> &a, vector<int> b){

    int i = 0; 
    int j = 0;
    int m = a.size();
    int n = b.size();
    vector<int> Intersect;

    while( i < m && j < n ){
        if(a[i] < b[j]){
            i++;
        }
        else if( a[i] > b[j]){
            j++;
        }
        else{
            Intersect.push_back(a[i]);
            i++;
            j++;
        } 
    }

    return Intersect;
} 

int main(){

    vector<int> a = { 1, 2, 3, 3 ,4 ,5};
    vector<int> b = { 2, 2 , 3, 4, 5, 5};

    // vector<int> result = IntersectionBrute(a, b);
    vector<int> result = IntersectionOptimal(a, b);

    for(auto it: result){
        cout<<it<<" ";
    }

    return 0;
}