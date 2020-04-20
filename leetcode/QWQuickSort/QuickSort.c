#include <stdio.h>
#include <stdlib.h>
void QuickSort(int **nums, int left, int right)
{
    if (left >= right )
        return;
    int pivot1 = nums[left][0];
    int pivot2 = nums[left][1];
    int h = right;
    int l = left;
    while (l < h)
    {
        while (nums[h][0] >= pivot1 && h > l)
            h--;
        while (nums[l][0] <= pivot1 && l < h)
            l++;
        int tmp1 = nums[h][0];
        nums[h][0] = nums[l][0];
        nums[l][0] = tmp1;
        int tmp2 = nums[h][1];
        nums[h][1] = nums[l][1];
        nums[l][1] = tmp2;
    }
    nums[left][0] = nums[l][0];
    nums[left][1] = nums[l][1];
    nums[l][0] = pivot1;
    nums[l][1] = pivot2;
    QuickSort(nums, left, l-1);
    QuickSort(nums, l+1, right);
}
int main()
{
    //[[1,3],[2,6],[8,10],[15,18]]
    int **nums = (int **)malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++)
    {
        nums[i] = (int *)malloc(sizeof(int)*2);
    }
    nums[0][0] = 2;
    nums[0][1] = 3;

    nums[1][0] = 2;
    nums[1][1] = 6;

    nums[2][0] = 30;
    nums[2][1] = 10;

    nums[3][0] = 1;
    nums[3][1] = 18;
    QuickSort(nums, 0, 3);
    for (int i = 0; i < 4;i++){
        printf("%d---%d ", nums[i][0], nums[i][1]);
        printf("\n");
    }
        system("pause");
    return 0;
}