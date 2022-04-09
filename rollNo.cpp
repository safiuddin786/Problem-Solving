// using c++
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    string t;
    string rollNo;
    cin>>t;
    cin>>rollNo;
    unordered_map<string,int> values;
    vector<int> result;
    for(int i=0;i<rollNo.length();i++){
        values[t[i]] += 1;
    }
    unordered_map::iterator p;
    for(int i=0;i<t.length();i++){
        for(p = values.begin();p!=values.end();p++){
            if(t[i] == p.second){
                result.push_back(p.first);
            }
        }
    }
    cout<<result;
}