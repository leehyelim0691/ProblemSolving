#include <iostream>
#include <ctype.h>
#include <string>
#include <cstring>

using namespace std;

int weight[1000000];

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
    int m, i = 0, carrier = 0;

    while(1){
        char str[1000000];
        cin.getline(str, 1000000);
        if(strlen(str)==0) break;
        if(i==0) m = stoi(str);
        else weight[i-1] = stoi(str); 
        i++;       
    }

    int n = i-1, start = 0, end = n-1;

    quick_sort(0, n-1);

    while(start <= end){
        if(weight[end]+weight[start] <= m) start++;
        carrier++;
        end--;      
    }
    
    cout << carrier;
}