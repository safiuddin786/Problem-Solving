// maximum profit from 'a'(strengths) by splitting groups in 'h'(heights)
// strength of a group is calculted by selecting the strength of largest height
// total strength is sum of strength of each group
// Finding the highest strength possible from given 'a' and 'h'


// Using Dynamic Programming
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>a[i];

    // O(n^2)
    int dp[n][n];
    int max_profit = INT_MIN;
    int temp;
    for(int i=0;i<n;i++){
        int maximum_index=i;
        for(int j=i;j<n;j++){
            if(i==0){
                if(j==i) dp[i][j] = a[j];
                else{
                    if(h[maximum_index] < h[j]){
                        dp[i][j] = a[j];
                        maximum_index = j;
                    }
                    else if(h[maximum_index] == h[j]){
                        if(a[maximum_index] > a[j]) dp[i][j] = a[maximum_index];
                        else{
                            dp[i][j] = a[j];
                            maximum_index = j;
                        }
                    }
                    else dp[i][j] = a[maximum_index];
                }
            }
            else{
                if(j==i){
                    temp = dp[i-1][j-1];
                    dp[i][j] = temp + a[j];
                }
                else{
                    if(h[maximum_index] < h[j]){
                        dp[i][j] = temp + a[j];
                        maximum_index = j;
                    }
                    else if(h[maximum_index] == h[j]){
                        if(a[maximum_index] > a[j]) dp[i][j] = temp + a[maximum_index];
                        else{
                            dp[i][j] = temp + a[j];
                            maximum_index = j;
                        }
                    }
                    else dp[i][j] = temp + a[maximum_index];
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
            if(dp[i][j] > max_profit) max_profit = dp[i][j];
        }
    }
    cout<<endl<<max_profit<<endl;
    return 0;
}


//   5 10 -14 14   3 4 2 1
//   5 10  10 10
//     15  15 15
//         15 15
//            29