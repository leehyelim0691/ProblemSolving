#include <stdio.h>
#include <stdlib.h>

int friend[2005][2005] = {0};
int ind[2005]={0};
int visit[2005]={0};
int n, k, f, problem, out = 0;

int CHECK(int count){ 
    for(int i=1; i<=count; i++){ 
        if((visit[i]==0) && (ind[i]<k)) { 
            problem = i;
            out++; 
            return -1; 
        }
    }
    return 1; 
}

void DELETE(int count){
    visit[problem] = 1;
    ind[problem] = 0;
    for(int i=1; i<=count; i++){
        if(friend[problem][i]){
            friend[problem][i] = 0;
            friend[i][problem] = 0;
            ind[i]--;
        }
    }
}


int main(){
    int first, second, below = 0;

    scanf("%d %d %d",&n, &k, &f);
    int count = n;
   
    for(int i=0; i<f; i++){
        scanf("%d %d", &first, &second);
        friend[first][second] = 1; 
        friend[second][first] = 1;
        ind[first]++; 
        ind[second]++;     
    }

    for(int i=1; i<=n; i++)
        if(ind[i] < k) below++;

    if((n-below) < (k+1)) printf("0\n"); 
    else {
        while(CHECK(count)!=1) DELETE(count);
        if(count-out<0) printf("0\n"); 
        else printf("%d\n",count-out); 
    }
}