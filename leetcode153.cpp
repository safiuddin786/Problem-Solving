// minimum in rotated sorted array
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int s[7] = {4,5,6,7,0,1,2};
    int n = *(&s+1) - s;
    // for(int i=0;i<n;i++){
    //     cout<<s[i];
    // }
    int l = 0;
    int h = n-1;
    int mid = (l+h)/2;
    while (true){
        if(s[l] <= s[mid] && s[mid] <= s[h]){
            break;
        }else if(s[l] > s[mid] && s[mid] < s[h]){
            h = mid;
        }else if(s[l] < s[mid] && s[mid] > s[h]){
            l = mid;
        }else{
            break;
        }
        mid = (l+h)/2;
    }
    if(s[l] < s[h]){
        cout<<s[l];
    }else{
        cout<<s[h];
    }
    return 0;
}