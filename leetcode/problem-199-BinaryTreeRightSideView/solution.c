/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXSIZE 1024
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *rightSideView(struct TreeNode *root, int *returnSize)
{
  
    int *ret = (int *)malloc(sizeof(int) * MAXSIZE);
    *returnSize = -1;
    if(root==NULL){
        *returnSize =0;
        return ret;
    }
    struct TreeNode *Quee[MAXSIZE]; //队列
    int top = 0;                   //队首
    int size = 1;                  //队尾
    //入队第root
    Quee[0] = root;
    int level = 0; //每层的最后一个节点在队列中坐标
    while (top < size)
    {
        //将该节点的值加入ret
        //队首出队,子节点入队

        if (Quee[top]->left)
        {
            Quee[size] = Quee[top]->left;
            size++;
        }
        if (Quee[top]->right)
        {
            Quee[size] = Quee[top]->right;
            size++;
        }
        if (top == level)
        {
            (*returnSize)++;
            ret[*returnSize] = Quee[top]->val;
            level = size - 1;
        }
        top++;
    }
    (*returnSize)++;
    return ret;
}