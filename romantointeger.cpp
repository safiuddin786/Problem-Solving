// optimal roman to integer 

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int checkExists(vector<string> &s,string k){
    for(int i=0;i<s.size();i++){
        if(s[i] == k){
            return i;
        }
    }
    return -1;
}
int main(){
    string str = "III";
    int result = 0;
    vector<string> s{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int n[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    for(int i=0;i<str.length();i++){
        int y = -1;
        int x = checkExists(s,{str[i]});
        if(i!=str.length()-1){
            y = checkExists(s,{str[i],str[i+1]});
        }
        if(y!=-1){
            result += n[y];
            i ++;
        }else{
            result += n[x];
        }
    }
    cout<<result;
    return 0;
}