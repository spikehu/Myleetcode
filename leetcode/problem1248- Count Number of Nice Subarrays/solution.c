/*
用一个数组记录奇数的下标
用滑窗得到满足k个计数的子数组
记录滑窗第一个奇数到前面一个奇数之前偶数的个数Lcount
记录最后一个奇数到后面一个奇数之前偶数的个数Rcount
该滑窗可能的组合就是Rcount*Lcount
**/
#include<stdio.h>
#include<stdlib.h>
int numberOfSubarrays(int *nums, int numsSize, int k)
{
    if (numsSize < k)
        return 0;
    int count = 0; //统计有多少个奇数
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 == 1)
            count++;
    }
    count = count + 2; //在两边给一个假奇数
    int *record = (int *)malloc(sizeof(int) * count);

    record[0] = -1;
    record[count - 1] = numsSize ;
    int index = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 == 1)
        {
            record[index] = i;
            index++;
        }
    }
    int left = 1;  //滑窗左边起点
    int right = k; //滑窗右边起点
    int ans = 0;
    while (right < count - 1)
    {
        int Lcount = record[left] - record[left - 1];
        int Rcount = record[right + 1] - record[right];
        ans = ans + Lcount * Rcount;
        //移动滑窗
        right++;
        left++;
    }
    return ans;
}
