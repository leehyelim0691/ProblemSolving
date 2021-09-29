#include <stdio.h>

struct Building {  
    int position;             
    int people;
};

void quick_sort(struct Building b[], int start, int end){ 
    if(start >= end) return; 
    int pivot = start; 
    int i = pivot + 1; 
    int j = end; 
    struct Building temp; 

    while(i <= j){ 
        while(i <= end && b[i].position <= b[pivot].position) i++; 
        while(j > start && b[j].position >= b[pivot].position) j--; 
        
        if(i > j){ 
            temp = b[j]; 
            b[j] = b[pivot];
            b[pivot] = temp; 
        }
        else{ 
            temp = b[i]; 
            b[i] = b[j]; 
            b[j] =temp; 
        } 
    } 
    quick_sort(b, start, j - 1); 
    quick_sort(b, j + 1, end); 
} 

int main(){
    int n, k, sum = 0, max = 0, left=0, right=0;;
  
    scanf("%d %d", &n, &k);

    struct Building b[n];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &(b[i].people), &(b[i].position));  
 
    quick_sort(b, 0, n-1);

    while (1) {
        if ((b[right].position - b[left].position) > 2*k) {
            if(sum > max) max = sum;
            sum -= b[left++].people;
        } else if (right == n) {
            break;
        } else {
            sum += b[right++].people;
        }
    }
    printf("%d\n",max);
}


