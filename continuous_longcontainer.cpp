#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> b{1, 1};
    vector<int> a = b;
    
// counts the number of previous blocks with same level or higher
    int temp_count=0;
    int max_dist=0;

    for(int i=0; i<a.size(); i++){
        int start=i;
        int curr_dist=temp_count+1;
        int prev_same_lvls=0;
        if(start+1 < a.size() && a[start] > a[start+1]) temp_count=0;
        while(start+1 < a.size()){
            if(a[start] < a[start+1]){
                curr_dist++;
                start++;
                prev_same_lvls=0;
            }
            else if(a[start] == a[start+1]){
                curr_dist++;
                start++;
                prev_same_lvls++;
            }
            else{
                temp_count+=prev_same_lvls+1;
                break;
            }
        }
        if(curr_dist > max_dist){
            max_dist=curr_dist;
        }
        i = start;
    }
    cout<<max_dist;
    return 0;
}