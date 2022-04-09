// 2 5 9
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int x,k,p;
    unordered_map<int,int> m;
    vector<int> a;
    cin>>x>>p>>k;
    for(int i=0;i<=p;i++){
        m[i] = 0;
    }
    int i=0;
    int temp;
    while(true){
        if(m[p] == p) break;
        temp = (x*i)%p;
        if(m[temp] == temp) m[p]++;
        if(m[temp] < temp){
            a.push_back(temp);
        }
        m[temp]++;
        i++;
    }
    cout<<a[k-1];
    return 0;
}
