#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int first, digit, num, sum = 0; 
    char s[30];  

    scanf("%d",&num);
    sprintf(s, "%d", num); 
    int count = strlen(s); 

    while(num!=0){
        digit = pow(10,count-1); 
        first = num / digit; 
        if (first<4) sum += first * pow(9,count-1);
        else sum += (first-1) * pow(9,count-1);
        num -= first*digit;
        count -=1;
   }

   if(num<4) sum += num;
   else if (num>4) sum += num-1;
   
   printf("%d",sum); 

   return 0;
}
