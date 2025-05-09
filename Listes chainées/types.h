#ifndef TYPES_H
#define TYPES_H

// Structure for a node in the doubly linked list
struct ListNode {
    char data;
    struct ListNode* right;
    struct ListNode* down;
};

// Structure for a cluster of DLLs
struct ClusterNode {
    struct ListNode* head;
};

#endif /* TYPES_H */
