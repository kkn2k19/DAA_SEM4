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
    printf("\nEnter the Weights : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    printf("\nEnter the profits : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("\nEnter the Knapsack Capacity : ");
    scanf("%d", &m);
    opt = Knapsack(1, m);
    printf("\nThe Optimal Solution is : %d", opt);
    return 0;
}
