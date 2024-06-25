#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct job {
    char id[5];
    int deadline;
    int profit;
} job;

void job_sequencing_with_deadline(job jobs[], int n);
int minValue(int x, int y);

int main(void) {
    int i, j;
    job jobs[5] = {
        {"j1", 2, 60},
        {"j2", 1, 100},
        {"j3", 3, 20},
        {"j4", 2, 40},
        {"j5", 1, 20}
    };

    job temp;
    int n = 5;

    // Sorting jobs by profit in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    printf("%-5s %-8s %-7s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++) {
        printf("%-5s %-8d %-7d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    job_sequencing_with_deadline(jobs, n);

    return 0;
}

void job_sequencing_with_deadline(job jobs[], int n) {
    int i, j, k, maxProfit = 0;
    int timeSlot[MAX];
    int filled_timeSlot = 0;
    int maxDeadline = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Initialize timeslots to -1
    for (i = 1; i <= maxDeadline; i++) {
        timeSlot[i] = -1;
    }

    // Assign jobs to timeslots
    for (i = 0; i < n; i++) {
        for (j = minValue(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (timeSlot[j] == -1) {
                timeSlot[j] = i;
                filled_timeSlot++;
                break;
            }
        }

        if (filled_timeSlot == maxDeadline) {
            break;
        }
    }

    printf("\nRequired Jobs: ");
    for (i = 1; i <= maxDeadline; i++) {
        if (timeSlot[i] != -1) {
            printf("%s", jobs[timeSlot[i]].id);
            if (i < maxDeadline) {
                printf(" ---> ");
            }
            maxProfit += jobs[timeSlot[i]].profit;
        }
    }
    printf("\nMax Profit: %d\n", maxProfit);
}

int minValue(int x, int y) {
    return (x < y) ? x : y;
}




// OUTPUT --
// Job   Deadline Profit 
// j2    1        100    
// j1    2        60     
// j4    2        40     
// j3    3        20     
// j5    1        20     
// Required Jobs: j2 ---> j1 ---> j3
// Max Profit: 180
