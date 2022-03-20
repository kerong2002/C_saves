#include<stdio.h>
#include<stdlib.h>
//遞迴函數通常分成兩個部分
/*
    1.遞迴結束條件
    2.遞迴內容
*/
int ans[21];
void permutation(int n,int cnt){
    if(cnt == n){
        for(int i=0;i<n;i++){
            printf("%d",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        ans[cnt]=i;
        permutation(n,cnt+1);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    permutation(n,0);
    return 0;
}
