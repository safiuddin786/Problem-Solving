#include <iostream>
#include <cmath>
using namespace std;
int sumd(int k){
    int sum=0;
    int temp;
    while(k!=0){
        temp = k%10;
        sum+=temp;
        k=k/10;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long l,r;
        cin>>l;
        cin>>r;
        long count = 0;
        long presum = sumd(l);
        long y = sqrt(presum);
        if(y*y == presum) count++;
        for(long j=l+1;j<=r;j++){
            if((j-1)%10 == 9){
                long temp = j-1;
                while(temp%10 == 9){
                    presum -= 9;
                    temp = temp/10;
                }
                presum++;
                long x = sqrt(presum);
                if(x*x == presum){
                    count++;
                }
            }
            else{
                presum++;
                long x = sqrt(presum);
                if(x*x == presum){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}