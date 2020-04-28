/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
#include<stdio.h>
int *singleNumbers(int *nums, int numsSize, int *returnSize)
{
    if(numsSize==0) return NULL;
    //将所有的数字进行异或运算
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    //选择ret为1的一位进行与操作将数字分为两组
    int first = 1; //从第一位开始
    while ((first & ret) == 0)
    {
        first <<= 1; //如果该位不为1，左移一位
    }
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = 0;
    ans[1] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if ((first & nums[i]) == 0)
        {
            ans[0]^=nums[i];
        }
        else
        {
            ans[1]^=nums[i];
        }
    }
 //*returnSize=2;
    return ans;
}
int main(){
    int testCae[4]={1,2,5,2};
    int numsSize=4;
    int *Size =0;
    int *result = singleNumbers(testCae,numsSize,Size);
    printf("%d-------------%d", result[0],result[1]);
    system("pause");
    return 0;
}