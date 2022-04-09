#include<iostream>
#include<string>
using namespace std;
// string score(string input){
//     int res=0;
//     int wickets=0;
//     for(int i=0;i<input.length();i++){
//         if(input[i] != 'W') res++;
//         else wickets++;
//     }
//     string s = ""+res)+"/"+str(wickets); 
//     return s;
// }
// int main(){
//     cout<<score("WW123456778");
//     return 0;
// }

int sumMax(int Arr[],int N){
    int dp[N];
    dp[0] = Arr[0];
    int maximum = dp[0];
    for(int i=1;i<N;i++){
        if(Arr[i] <= dp[i-1]+Arr[i]) dp[i] = dp[i-1]+Arr[i];
        else dp[i] = Arr[i];
        if(dp[i] > maximum) maximum = dp[i];
    }
    return maximum;
}
int main(){
    int Arr[3] = {-1,-2,-1};
    cout<<sumMax(Arr,3);
    return 0;
}