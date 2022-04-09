// largest container
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<int> s{1,2,1};
    int l = 0,r = s.size()-1;
    int maximum = 0;
    while(l!=r){
        if(s[r]>=s[l]){
            if(s[l]*(r-l) > maximum){
                maximum = s[l]*(r-l);
            }
            l++;
        }else{
            if(s[r]*(r-l) > maximum){
                maximum = s[r]*(r-l);
            }
            r--;
        }
    }
    cout<<maximum;
    return 0;
}