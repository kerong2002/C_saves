#include <stdio.h>
#include<string.h>
int main(int argc, const char * argv[]) {
    int E=1;
    while (E) {
        int N;
        char i[99][99];
        int o[53]={0};
        int j;
        
        
        scanf("%d",&N);
        
        if (N<=0) {
            E=0;
        }
        
        for (int x=0; x<N; x++) {
            scanf("%s",i[x]);
        }
        
        for (int y=0; y<N; y++) {
            for (int x=0; x<strlen(i[y]); x++) {
                for (int z=0; z<53; z++) {
                    if (z<27) {
                        j=z+65;
                    }
                    if (z>=27) {
                        j=z+70;
                    }
                    if (i[y][x]==j) {
                        o[z]+=1;
                    }
                }
            }
        }
        
    
        int max=0;
        for (int z=0; z<53; z++) {
            if (o[z]>max) {
                max=o[z];
            }
        }
        
        
        for (int x=max; x>0; x=x-1) {
            for (int z=0; z<53; z++) {
                if (o[z]==x) {
                    if (z<27) {
                        j=z+65;
                    }
                    if (z>=27) {
                        j=z+70;
                    }
                    printf("%c(%d) ",j,x);
                }
            }
            
        }
        printf("\n");
        
        
        
        
    }
}
