//18.04.2024
// TOWER OF HANOI

#include <stdio.h>

int main()
{
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}

void towerOfHanoi(int n, char src, char aux, char dest)
{
    if (n == 1) {
        printf("%c -> %c\n" , src, dest);
        return;
    }
    towerOfHanoi(n-1, src, dest, aux);
    towerOfHanoi(1, src, aux, dest);
    towerOfHanoi(n-1, aux, src, dest);
}
