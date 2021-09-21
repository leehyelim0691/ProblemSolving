#include <stdio.h>
#include <stdlib.h>

int M, n =0,count = 0;
    int weight[1000000] = {0};


void quick_sort(int start, int end){ 
    if(start >= end) return; 
    int pivot = start; 
    int i = pivot + 1; 
    int j = end; 
    int temp; 

    while(i <= j){ 
        while(i <= end && weight[i] <= weight[pivot]) i++; 
        while(j > start && weight[j] >= weight[pivot]) j--; 
        
        if(i > j){ 
            temp = weight[j]; 
            weight[j] = weight[pivot];
            weight[pivot] = temp; 
        }
        else{ 
            temp = weight[i]; 
            weight[i] = weight[j]; 
            weight[j] =temp; 
        } 
    } 
    quick_sort(start, j - 1); 
    quick_sort(j + 1, end); 
} 

int main(){
    char str[1000000];
    int index = 0;
    int visit[1000000] = {0};

    scanf("%d\n", &M);

    while(1){
        fgets(str, 1000000, stdin);
        if(str[0]=='\n')  break;
        weight[n] = atoi(str);
        n++;
    }

    quick_sort(0, n-1);

    int start = 0, end = n-1;

    while(index < n){
        if(!visit[end]){
            if(weight[end] >= M){
                printf("1. weight[%d] is %d and now count is %d\n",end,weight[end],count);
                visit[end] = 1;
                count++;
                end--;
                index++;
            }
            else{
                if((weight[end] + weight[start]) <= M){
                    printf("2. weight[%d] is %d, weight[%d] is %d and now count is %d\n",end,weight[end],start,weight[start],count);
                    visit[end] = 1;
                    visit[start] = 1;
                    count++;
                    end--;
                    start++;
                    index += 2;
                }
                else{
                    printf("3.  weight[%d] is %d andnow count is %d\n",end,weight[end],count);
                    visit[end] = 1;
                    count++;
                    end--;
                    index++;
                }
            }
        }
    }
    
    printf("%d\n", count);
}