#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int k, rod[51] = {0}, two[51] = {1};

int Tower(int i){
    if(i == 0) return 0;
    else if(rod[i] != k){
        k = 6 - rod[i] - k;
        return Tower(i-1) + two[i-1]; 
    }
    return Tower(i-1);
}

int main(){
    int n, num[4], disk = 0;

    scanf("%d %d\n", &n, &k);

    for(int i = 1; i <= 3; i ++){
        scanf("%d", &num[i]);
        for(int j = 1; j <= num[i]; j++) {
            scanf(" %d", &disk);
            rod[disk] = i;
        }
    }

    for(int i = 1; i <= n; i++) two[i] = two[i-1] * 2;
   
    printf("%d\n",Tower(n));
}

