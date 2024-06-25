//18.04.2024
// TOWER OF HANOI

#include <stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter the number of disks : ");
    int n;
    scanf("%d", &n);
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}

void towerOfHanoi(int n, char src, char aux, char dest)
{
    if (n == 1) {
        // printf("%c -> %c\n" , src, dest);
        printf("Transfer disk 1 from %c to %c\n", src, dest);
        return;
    }
    towerOfHanoi(n-1, src, dest, aux);
    towerOfHanoi(1, src, aux, dest);
    towerOfHanoi(n-1, aux, src, dest);
}



// OUTPUT -- 

// Enter the number of disks : 3
// Transfer disk 1 from A to C
// Transfer disk 1 from A to B
// Transfer disk 1 from C to B
// Transfer disk 1 from A to C
// Transfer disk 1 from B to A
// Transfer disk 1 from B to C
// Transfer disk 1 from A to C
