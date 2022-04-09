#include<iostream>
#include<cmath>
using namespace std;
// binary search
int main(){
    // time complexity is 
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    // binary search untill distance is 0
    int l=0,h=a[n-1];
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        int distance = 0;
        // calculate distance
        for(int i=0; i<n; i++)
            distance += abs(mid-a[i]);
        if(distance < 0){
            l = mid+1;
        }else if(distance > 0){
            h = mid-1;
        }else{
            cout<<mid<<endl;
            return 0;
        }
    }
    cout<<mid<<endl;
    return 0;
}