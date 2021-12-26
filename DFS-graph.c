#include <stdio.h>

int n = 4;
int visited[100];
// int G[4][4] = {
//                 {0, 1, 1, 0},
//                 {1, 0, 0, 1},
//                 {1, 0, 0, 0},
//                 {0, 1, 0, 0},
//             };

void DFS(int G[n][n], int s)
{
    printf("%d", s);
    visited[s] = 1;
    for (int j=0; j<n; j++)
    {
        if (G[s][j]==1 && visited[j]!=1)
        {
            DFS(G, j);
        }
    }
}

// int main()
// {
//     for (int i=0; i<n; i++)
//     {
//         visited[i] = 0;
//     }
//     DFS(G, 0);
//     return 0;
// }

int main()
{
    for (int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the adjacency matrix: \n");
    int G[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("Enter element G[%d][%d]: ", i, j);
            scanf("%d",  &G[i][j]);
        }
    }
    DFS(G, 0);
    return 0;
}
