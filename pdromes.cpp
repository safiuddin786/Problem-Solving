#include<iostream>
#include<string>
using namespace std;
string s;
cin>>s;
int n = s.length();
bool check(string &s,int i,int n){
    if(s[i] == s[n-i-1]) return false;
    int x=0,y=n-1;
    while(x<=y){
        if(s[x] != s[y] && (x != i || y != i)) return false;
        x++;
        y--;
    }
    return true;
}
for(int i=0;i<n;i++){
    if(check(s,i,n)){
        char temp = s[i];
        s[i] = s[n-i-1];
        cout<<s;
        s[i] = temp;
    }
}