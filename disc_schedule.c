#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CYLINDER 200

void sstf(int requests[], int n, int initial_head) {
    int seek_sequence[MAX_CYLINDER], completed[MAX_CYLINDER] = {0};
    int current_head = initial_head, count = 0;
    int total_seek_time = 0;

    while (count < n) {
        int min_distance = 10000, index = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                int distance = abs(requests[i] - current_head);
                if (distance < min_distance) {
                    min_distance = distance;
                    index = i;
                }
            }
        }

        completed[index] = 1;
        seek_sequence[count++] = requests[index];
        total_seek_time += abs(requests[index] - current_head);
        current_head = requests[index];
    }

    printf("SSTF Seek Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

void c_scan(int requests[], int n, int initial_head, int total_cylinders) {
    int seek_sequence[MAX_CYLINDER], index = 0;
    int total_seek_time = 0;

    qsort(requests, n, sizeof(int), (int (*)(const void *, const void *)) strcmp);

    for (int i = 0; i < n; i++) {
        if (requests[i] >= initial_head) {
            seek_sequence[index++] = requests[i];
        }
    }
    total_seek_time += total_cylinders - 1 - initial_head;
    seek_sequence[index++] = total_cylinders - 1;

    for (int i = 0; i < n; i++) {
        if (requests[i] < initial_head) {
            seek_sequence[index++] = requests[i];
        }
    }

    for (int i = 1; i < index; i++) {
        total_seek_time += abs(seek_sequence[i] - seek_sequence[i - 1]);
    }

    printf("C-SCAN Seek Sequence: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

void c_look(int requests[], int n, int initial_head) {
    int seek_sequence[MAX_CYLINDER], index = 0;
    int total_seek_time = 0;

    qsort(requests, n, sizeof(int), (int (*)(const void *, const void *)) strcmp);

    for (int i = 0; i < n; i++) {
        if (requests[i] >= initial_head) {
            seek_sequence[index++] = requests[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (requests[i] < initial_head) {
            seek_sequence[index++] = requests[i];
        }
    }

    for (int i = 1; i < index; i++) {
        total_seek_time += abs(seek_sequence[i] - seek_sequence[i - 1]);
    }

    printf("C-LOOK Seek Sequence: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int requests[MAX_CYLINDER], n, initial_head, total_cylinders;

    printf("Disk Scheduling Program\n");
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    printf("Enter the disk requests : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial_head);

  

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. SSTF\n");
        printf("2. C-SCAN\n");
        printf("3. C-LOOK\n");
        printf("4. Exit\n");
        
        printf("Choose a disk scheduling algorithm: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sstf(requests, n, initial_head);
                break;
            case 2:
                c_scan(requests, n, initial_head, total_cylinders);
                break;
            case 3:
                c_look(requests, n, initial_head);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
	
