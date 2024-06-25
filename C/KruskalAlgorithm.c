#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int i, j, a, b, u, v, n, ne = 1;
int min, minCost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

void main() {
    printf("Kruskal's Algorithm in C\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix : \n");
    for(i = 1; i <= n; i++) {  // Corrected loop bounds
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    printf("The edges of minimum cost spanning tree are \n");
    while(ne < n) {
        for(i = 1, min = 999; i <= n; i++) {  // Added initialization of min
            for(j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);  // Fixed min to display the correct edge cost
            minCost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", minCost);
    getch();
}

int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}



// OUTPUT --
// Kruskal's Algorithm in C
// Enter the number of vertices: 6
// Enter the cost adjacency matrix : 
// 0 3 1 6 0 0
// 3 0 5 0 3 0 
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 2
// 0 0 4 2 6 0
// The edges of minimum cost spanning tree are 
// 1 edge (1, 3) = 1
// 2 edge (4, 6) = 2
// 3 edge (5, 6) = 2
// 4 edge (1, 2) = 3
// 5 edge (2, 5) = 3

// Minimum cost = 11
