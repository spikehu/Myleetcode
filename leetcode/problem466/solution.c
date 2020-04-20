#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
#include <string.h>
void count(int* nums ,char* s ,int n ){
    for(int i =0 ; i < strlen(s)  ; i++ ){
        int j = s[i] - 'a';
        nums[ j]++;
    }
    for(int i = 0; i < strlen(s) ; i++){
        
         nums[i]=n*nums[ i];
    }
}
int getMaxRepetitions(char * s1, int n1, char * s2, int n2){
//统计si,s2出现的单词个数
int numOfS1[26] ={0};
int  numOfS2[26]={0};
int min = INT_MAX;
count(numOfS1 , s1, n1);
count(numOfS2 , s2, n2);
for(int i =0 ;i <26 ;i++){
    if(numOfS2[i] == 0){
        continue;
    }else{
        int c = numOfS1[i]/ numOfS2[i];
        min = min >c ? c : min; 
    }

}
return min;
}
int main(){
    char s2[3] = "aa\0";
      int n1 = 3;
    char s1[4] = {'a', 'a', 'a','\0'};
  
   
    int n2 = 1;
    int ret = getMaxRepetitions(s1, n1, s2, n2);
    printf("the result is %d", ret);
    system("pause");
    return 0;
}