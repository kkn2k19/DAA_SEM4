#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int n, cost[10][10], nears[10];

void readV();
void primsAlgo();
int find_next_inside(int cost[10][10], int nears[10]);

void readV() {
    int i, j;
    printf("\nEnter the number of nodes or vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = 999;
            }
        }
    }
}

void primsAlgo() {
    int k, l, min, i, j, minCost;
    int t[10][2];

    min = 999;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j && cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[0][0] = k;
    t[0][1] = l;
    printf("\nThe minimum cost spanning tree is ....");
    printf("\n(%d, %d) ---> %d", k, l, min);

    for (i = 1; i <= n; i++) {
        if (i != k) {
            if (cost[i][l] < cost[i][k]) {
                nears[i] = l;
            } else {
                nears[i] = k;
            }
        }
    }

    nears[k] = nears[l] = 0;
    minCost = min;

    for (i = 1; i < n - 1; i++) {
        j = find_next_inside(cost, nears);
        t[i][0] = j;
        t[i][1] = nears[j];
        printf("\n(%d, %d) ---> %d", j, nears[j], cost[j][nears[j]]);
        minCost += cost[j][nears[j]];
        nears[j] = 0;

        for (k = 1; k <= n; k++) {
            if (nears[k] != 0 && cost[k][nears[k]] > cost[k][j]) {
                nears[k] = j;
            }
        }
    }

    printf("\nThe required minimum cost of the spanning tree: %d\n", minCost);
}

int find_next_inside(int cost[10][10], int nears[10]) {
    int min = 999, k = -1, p;
    for (int a = 1; a <= n; a++) {
        p = nears[a];
        if (p != 0 && cost[a][p] < min) {
            min = cost[a][p];
            k = a;
        }
    }
    return k;
}

void main() {
    readV();
    primsAlgo();
    getch();
}


// OUTPUT --
// Enter the number of nodes or vertices: 7
// Enter the cost adjacency matrix of the graph: 
// 0 20 0 0 0 10 0 
// 20 0 16 0 0 0 14 
// 0 16 0 12 0 0 0
// 0 0 12 0 22 0 18   
// 0 0 0 22 0 25 24
// 10 0 0 0 25 0 0
// 0 14 0 0 24 0 0
// The minimum cost spanning tree is ....
// (1, 6) ---> 10
// (2, 1) ---> 20
// (7, 2) ---> 14
// (3, 2) ---> 16
// (4, 3) ---> 12
// (5, 4) ---> 22
// The required minimum cost of the spanning tree: 94
