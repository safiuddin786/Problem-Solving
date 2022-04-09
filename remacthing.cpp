// Regular Expression matching using DP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<vector<int>> dp;
    vector<int> v;
    v.push_back(1);
    string s = "abca";
    string p = "ab*ca";
    for(int i=1;i<=s.size();i++){
        v.push_back(0);
    }
    dp.push_back(v);
    for (int i=1;i<=p.size();i++){
        for(int j=0;j<=s.size();j++){
            if(j==0){
                if(p[i-1] == '*' && dp[i-2][0] == 1){
                    dp.push_back({1});
                }else{
                    dp.push_back({0});
                }
            }else if(p[i-1]=='*'){
                char pc = p[i-2];
                if(pc == s[j-1] || pc == '.'){
                    dp[i].push_back(max(dp[i-2][j],dp[i][j-1]));
                }else{
                    dp[i].push_back(dp[i-2][j]);
                }
            }else if(p[i-1] == '.' || p[i-1] == s[j-1]){
                dp[i].push_back(dp[i-1][j-1]);
            }else{
                dp[i].push_back(0);
            }
        }
    }

    for(int i = 0; i<dp.size();i++){
        for(int j =0;j<dp[i].size();j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }

    if(dp[p.size()][s.size()]){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}