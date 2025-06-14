#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "library.c"

int main() {
    int numClusters;
    printf("Enter the number of clusters: ");
    scanf("%d", &numClusters);

    struct ClusterNode** clusterArray = (struct ClusterNode**)malloc(numClusters * sizeof(struct ClusterNode*));
    if (clusterArray == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Initialize each cluster in the array
    for (int i = 0; i < numClusters; i++) {
        clusterArray[i] = (struct ClusterNode*)malloc(sizeof(struct ClusterNode));
        if (clusterArray[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        clusterArray[i]->head = NULL;
    }

    int choice;
    do {
        printf("\n * THE MENU *:\n");
        printf("1. Inserting a new DLL to its cluster at the appropriate index position in the dynamic array CArr;\n");
        printf("2. Display a DLL\n");
        printf("3. Search for the existence of an image by reading the image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int clusterIndex;
                printf("Enter the cluster index to insert the DLL: ");
                scanf("%d", &clusterIndex);

                if (clusterIndex < 0 || clusterIndex >= numClusters) {
                    printf("Invalid cluster index.\n");
                    break;
                }

                printf("Enter filename to construct DLL: ");
                char filename[100];
                scanf("%s", filename);
                struct ListNode* newDLL = constructListFromFile(filename);

                // Find the last node of the DLL to link to the head of the cluster
                struct ListNode* lastNode = newDLL;
                while (lastNode->down != NULL) {
                    lastNode = lastNode->down;
                }

                // Update the last node to point to the head of the cluster
                lastNode->down = clusterArray[clusterIndex]->head;
                clusterArray[clusterIndex]->head = newDLL;

                printf("DLL inserted to cluster %d.\n", clusterIndex);
                break;
            }
            case 2: {
                int clusterIndex;
                printf("Enter the cluster index to display: ");
                scanf("%d", &clusterIndex);

                if (clusterIndex < 0 || clusterIndex >= numClusters) {
                    printf("Invalid cluster index.\n");
                    break;
                }

                printf("Image(s) reconstructed from the DLL in cluster %d:\n", clusterIndex);
                displayList(clusterArray[clusterIndex]->head);
                break;
            }
            case 3: {
                printf("Enter filename to search for: ");
                char filename[100];
                scanf("%s", filename);
                struct ListNode* imageToSearch = constructListFromFile(filename);

                int foundIndex;
                struct ListNode* foundDLL = searchList(imageToSearch, clusterArray, numClusters, &foundIndex);
                if (foundDLL != NULL) {
                    printf("Image found in cluster %d.\n", foundIndex);
                } else {
                    printf("Image not found.\n");
                }
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free memory allocated for clusterArray
    for (int i = 0; i < numClusters; i++) {
        struct ListNode* current = clusterArray[i]->head;
        while (current != NULL) {
            struct ListNode* temp = current;
            current = current->down;
            free(temp);
        }
        free(clusterArray[i]);
    }
    free(clusterArray);

    return 0;
}
