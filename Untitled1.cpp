#include <iostream>
#include <bits/stdc++.h>


using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector <int> answer,arr;
    int lastAns=0;
    
    for (int i=0;i<queries.size();i++){
        if (queries[i][0]==1){
            cout<<1;
            int idx =((queries[i][1]^lastAns)%n);
            arr[idx]=queries[i][2];
        }
        else if  (queries[i][0]==2){
            cout<< 2;
            
        }
    }
        
    return answer;
}

int main() {
    int n=2,q=5;
    vector<vector<int>> queries = {
        {1,0,5},
        {1,1,7},
        {1,0,3},
        {2,1,0},
        {2,1,1}
    };
    vector<int> result = dynamicArray(n, queries);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }
    
}
