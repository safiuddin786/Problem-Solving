#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    // string s,x;
    // cin>>s;
    // cin>>x;
    // int size_s = s.length();
    // int size_x = x.length();
    // int result = -1;
    // for(int i=0; i<=size_s-size_x; i++){
    //     int j=0;
    //     while((i+j < size_s) && (j<size_x) && (s[i+j] == x[j] || x[j] == '*')){
    //         j++;
    //     }
    //     if(j == size_x){
    //         result = i;
    //         break;
    //     }
    // }
    // return result;
    // return 0;

    int n,o;
    cin>>n;
    int volcanic[n];
    unordered_map<int, int> compare;
    for(int i=0; i<n; i++){
        cin>>volcanic[i];
        if(compare.find(volcanic[i]) != compare.end()){
            compare[volcanic[i]]++;
        }else{
            compare[volcanic[i]] = 1;
        }
    }
    cin>>o;
    int nonVolcanic[o];
    priority_queue<int> pq;
    for(int i=0; i<o; i++){
        cin>>nonVolcanic[i];
        if(compare.find(nonVolcanic[i]) != compare.end() && compare[nonVolcanic[i]] != 0){
            pq.push(nonVolcanic[i]);
            compare[nonVolcanic[i]]--;
        }
    }
    vector<int> result;
    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }
    for(int i=0; i<result.size(); i++){
        cout<<result[i];
    }
}