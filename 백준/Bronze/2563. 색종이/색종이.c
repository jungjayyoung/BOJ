#include <stdio.h>

int paper[101][101];
int main() {

    int n;
    int sum=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);

        for(int a = x; a< x + 10; a++){
            for(int b =y; b < y + 10;b++){
                if(!paper[a][b]){
                    paper[a][b] = 1;
                    sum++;
                }
            }
        }
    }

    printf("%d",sum);
    return 0;
}
