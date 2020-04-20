#include <stdio.h>
#include <stdlib.h>
//单调栈
#define Max(a, b) a>b ?a:b
//按层数求
int trap(int* height, int heightSize){
    if(heightSize == 0 || heightSize ==1 ) return 0;
     int sum =0;
     int high  =0;  
     int right =heightSize -1 ;
     int  left = 0;  
     int level = 1;     
     int max =0 ;
     //求柱子体积
     for(int i =0 ; i <heightSize  ;i++ ){
         high= high+ height[i];
         max = Max(max ,height[i]);
     }                       
    while(level <= max  ){
        while( height[left] < level) left++;
        while (height[right] <level )right--;
        sum = sum + right-left+1;
        level++;
    }


     return sum - high;
}
int main()
{
    //[0,1,0,2,1,0,1,3,2,1,2,1]
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightSize = sizeof(height) / sizeof(int);
    
    int ans = trap(height, heightSize);
    printf("%d", ans);
    system("pause");
    return 0;
}