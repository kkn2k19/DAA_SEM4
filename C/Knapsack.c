#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int p[MAX], w[MAX], n;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Knapsack(int i, int m) {
    if (i == n) {
        if (w[i] > m) {
            return 0;
        } else {
            return p[i];
        }
    }
    if (w[i] > m) {
        return Knapsack(i + 1, m);
    }
    return max(Knapsack(i + 1, m), Knapsack(i + 1, m - w[i]) + p[i]);
}

int main() {
    int m, i, opt;
    printf("Enter no. of Objects : ");
    scanf("%d", &n);
    printf("Enter the Weights : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    printf("Enter the profits : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter the Knapsack Capacity : ");
    scanf("%d", &m);
    opt = Knapsack(1, m);
    printf("The Optimal Solution is : %d", opt);
    return 0;
}



// OUTPUT --
// Enter no. of Objects : 3
// Enter the Weights : 4 5 1
// Enter the profits : 1 2 3
// Enter the Knapsack Capacity : 4
// The Optimal Solution is : 3
