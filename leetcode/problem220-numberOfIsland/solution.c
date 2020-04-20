#include <stdlib.h>
//bfs
typedef struct Quee
{
    int x;
    int y;
    struct Quee *next;

} Quee;

void BFS(char **grid, int x, int y, int gridSize, int colSize)
{
    Quee *head = (Quee *)malloc(sizeof(Quee));
    head->x = x;
    head->y = y;
    head->next = NULL;
    Quee *p = head;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (head)
    {
        //将周围未访问的1加入队列
        for (int i = 0; i < 4; i++){
            int newX = head->x + dx[i];
            int newY = head->y + dy[i];
            if(newX >= 0 && newY>=0 && newX <gridSize &&  newY <colSize){
                    //如果为'1'，将其加入队列，且标志为以访问
                    if(grid[newX][newY] == '1'){
                        grid[newX][newY] = '2';
                         p->next = (Quee *)malloc(sizeof(Quee));
                         p->next->x = newX;
                         p->next->y = newY;
                         p->next->next = NULL;
                         p = p->next;
                    }
            }
          
        }
        head =head->next;
    }
}
int numIslands(char **grid, int gridSize, int *gridColSize)
{
    
    int ans = 0;
    for (int x = 0; x < gridSize;x++){
        for (int y = 0; y < *gridColSize; y++){
            if(grid[x][y]=='1'){
                ans++;
                grid[x][y] = '2';
                BFS(grid, x, y, gridSize, *gridColSize);
            }
        }
    }
    return ans;
}