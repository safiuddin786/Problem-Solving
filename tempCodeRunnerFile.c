/*#include<stdio.h>
#include<string.h>
void calculate(char *a,int i, int n);
void swap(char *x, char *y);
int m=0;
void main(){
    char str[10]="SVCE";
    int len=0,i=0;
    len = strlen(str);
    calculate(str,0,len-1);
    printf("%d\n",m);
}
void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void calculate(char *a, int i, int n){
    int j=0;
    if(i==n){
        m++;
    }else{
        for(j=i;j<=n;j++){
            swap((a+i),(a+j));
            calculate(a,i+1,n);
            swap((a+i),(a+j));
        }
    }
}
#include<stdio.h>
int Decode(char* pStr){
    int iRetVal = 0;
    if(pStr)
    {
        while(*pStr && *pStr <= '9' &&  *pStr >= '0'){
            iRetVal = (iRetVal*10)+(*pStr - '0');
            pStr++;
        }
    }return iRetVal;
}*/
#include<stdio.h>

int incr(int i){
     static int count =5;
     count = count+i;
     return (count);
 }
 int main(){
     int i,j;
     for(i=0;i<=4;i++)
        j= incr(i);
    printf("%d",j);
    return 0;
 }

