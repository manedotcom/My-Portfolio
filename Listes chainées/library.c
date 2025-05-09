#include "types.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
struct ListNode* newNode(char data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    node->data = data;
    node->right = NULL;
    node->down = NULL;
    return node;
}

// Function to construct a doubly linked list from a text file
struct ListNode* constructListFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    struct ListNode* head = NULL;
    struct ListNode* currentRow = NULL;
    struct ListNode* prevRow = NULL;
    struct ListNode* firstNodeOfPrevRow = NULL;
    struct ListNode* lastNode = NULL;

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            if (head == NULL) {
                head = currentRow;
            } else {
                prevRow->down = currentRow;
                if (firstNodeOfPrevRow != NULL) {
                    firstNodeOfPrevRow->right = currentRow;
                }
            }
            firstNodeOfPrevRow = head;
            lastNode = currentRow;
            prevRow = currentRow;
            currentRow = NULL;
        } else {
            struct ListNode* node = newNode(ch);
            if (currentRow == NULL) {
                currentRow = node;
            } else {
                lastNode->right = node;
            }
            lastNode = node;
        }
    }

    fclose(file);
    if (lastNode != NULL && firstNodeOfPrevRow != NULL) {
        lastNode->right = firstNodeOfPrevRow;
    }

    return head;
}

// Function to display a doubly linked list
void displayList(struct ListNode* head) {
    struct ListNode* currentRow = head;
    while (currentRow != NULL) {
        struct ListNode* currentNode = currentRow;
        while (currentNode != NULL) {
            printf("%c", currentNode->data);
            currentNode = currentNode->right;
        }
        printf("\n");
        currentRow = currentRow->down;
    }
}

// Function to search for the existence of an image within a cluster
struct ListNode* searchList(struct ListNode* image, struct ClusterNode** clusters, int size, int* index) {
    for (int i = 0; i < size; i++) {
        struct ListNode* current = clusters[i]->head;
        while (current != NULL) {
            struct ListNode* currentImage = image;
            struct ListNode* currentCluster = current;
            while (currentImage != NULL && currentCluster != NULL) {
                if (currentImage->data != currentCluster->data) {
                    break;
                }
                currentImage = currentImage->right;
                currentCluster = currentCluster->right;
            }
            // If currentImage is NULL, it means the entire image matched with the current cluster
            if (currentImage == NULL) {
                *index = i;
                return clusters[i]->head;
            }
            current = current->down; // Move to the next image in the cluster
        }
    }
    return NULL; // Image not found in any cluster
}
