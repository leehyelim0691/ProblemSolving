#include <stdio.h>
#include <stdlib.h>

struct Building {  
    int position;             
    int people;
};

int main(){
    int n, k, g, x, temp, sum = 0;
    int max = 0;

    scanf("%d %d", &n, &k);

    struct Building *b[n]; 

    for (int i = 0; i < sizeof(b)/sizeof(struct Building *); i++)
        b[i] = malloc(sizeof(struct Building));   

    for(int i = 0; i < n; i++){
        scanf("%d %d", &(b[i]->people), &(b[i]->position));
        sum += (b[i]->people);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if ((b[j]->position) > (b[j+1]->position)){    
                temp = (b[j]->position);
                (b[j]->position) = (b[j+1]->position);
                (b[j+1]->position) = temp; 
                temp = (b[j]->people);
                (b[j]->people) = (b[j+1]->people);
                (b[j+1]->people) = temp; 
            }
        }
    }

    if(((b[n-1]->position)-(b[0]->position)) <= (2*k)) printf("%d\n",sum);
    else{
        for(int i = 0; i < n; i++){
            sum = 0;
            if((b[i]->position+2*k) > b[n-1]->position){
                for(int j = i; j <= (n-1); j++) {
                    if(b[j]->people!=0)  sum += b[j]->people;
                }
                break;
            }
            else{
                int j = i;
                while(b[j]->position <= (b[i]->position + 2*k)){
                    sum += (b[j]->people);
                    j++;
                }
            }
            if(sum > max) max = sum;
        }
    }

    printf("%d\n", max);
}
