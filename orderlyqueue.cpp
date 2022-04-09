#include <iostream>
#include <string>
#include <vector>
using namespace std;
int checklex(string s,int k){
    string temp = s;
    temp.push_back(s[k]);
    temp.erase(k,1);
    int calc = 0;
    for(int j=0;j<s.length();j++){
        calc += int(s[j]) - int(temp[j]);
    }
    return calc;
}
int main(){
    string s = "cab";
    int k = 1;
    // vector<string> q;
    int maximum = 0;
    int premax = 0;
    int index = -1;
    int count = 0;
    while (count<3){
        for(int i = 0;i<k;i++){
            int c = checklex(s,i);
            if(c > maximum){
                maximum = c;
                index = i;
            }
        }
        // s.push_back(s[index]);
        // s.erase(index,1);
        // cout<<s<<endl;
        // if(premax <= maximum){
        //     premax = maximum;
        // }else{
        //     break;
        // }
        count++;
    }
}