#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int a[5][2] = {{1,2},{2,2},{3,3},{0,1},{0,1}};
    int n = 5;
    int min_a = ;
    int min_d = 2;
    int weakCount = 0;
    for(int i = 0;i<5;i++){
        if(a[i][0] < min_a){
            if(a[i][1] < min_d){
                min_a = a[i][0];
                min_d = a[i][1];
                weakCount = 1;
            }
        }
        else if(a[i][0] == min_a){
            if(a[i][1] == min_d){
                weakCount ++;
            }
        }
    }
    cout<<weakCount;
    return 0;
}