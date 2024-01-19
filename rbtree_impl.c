#ifndef RBTREE
#define RBTREE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data_structure.c"

void rightRotate(pStaffTree tree, pStaffNode node) {
    pStaffNode parent = node->parent;
    pStaffNode left = node->leftChild;
    node->leftChild = left->rightChild;

    if (left->rightChild) {
        left->rightChild->parent = node;
    }

    left->rightChild = node;
    node->parent = left;

    if (parent) {
        if (node == parent->leftChild) {
            parent->leftChild = left;
        } else {
            parent->rightChild = left;
        }
    } else {
        tree->root = left; // Update tree's root
    }
}

void leftRotate(pStaffTree tree, pStaffNode node) {
    pStaffNode parent = node->parent;
    pStaffNode right = node->rightChild;
    node->rightChild = right->leftChild;

    if (right->leftChild) {
        right->leftChild->parent = node;
    }

    right->leftChild = node;
    node->parent = right;

    if (parent) {
        if (node == parent->leftChild) {
            parent->leftChild = right;
        } else {
            parent->rightChild = right;
        }
    } else {
        tree->root = right ; // Update tree's root
    }
}


pStaffNode createStaffNode(pStaff staff, int color) {
    pStaffNode newNode = (pStaffNode)malloc(sizeof(StaffNode));
    newNode->Staff = staff;
    newNode->color = color;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    return newNode;
}

void rbTreeAdjust(pStaffTree tree, pStaffNode node) {
    pStaffNode father, grandfather, uncle;

    while (node != tree->root && node->parent->color == 1) {
        father = node->parent;
        grandfather = father->parent;

        if (father == grandfather->leftChild) {
            uncle = grandfather->rightChild;

            if (uncle && uncle->color == 1) {
                father->color = 0;
                uncle->color = 0;
                grandfather->color = 1;

                node = grandfather;
            } else {
                if (node == father->rightChild) {
                    node = father;
                    leftRotate(tree, node);
                    father = node->parent;
                }

                father->color = 0;
                grandfather->color = 1;
                rightRotate(tree, grandfather);
            }
        } else {
            uncle = grandfather->leftChild;

            if (uncle && uncle->color == 1) {
                father->color = 0;
                uncle->color = 0;
                grandfather->color = 1;

                node = grandfather;
            } else {
                if (node == father->leftChild) {
                    node = father;
                    rightRotate(tree, node);
                    father = node->parent;
                }

                father->color = 0;
                grandfather->color = 1;
                leftRotate(tree, grandfather);
            }
        }
    }

    tree->root->color = 0;
}


void rbTreeInsert(pStaffTree tree, pStaff staff) {
    pStaffNode node = createStaffNode(staff, 1);
    pStaffNode parent = NULL;
    pStaffNode current = tree->root;

    while (current != NULL) {
        parent = current;
        if (strcmp(staff->id, current->Staff->id) < 0) {
            current = current->leftChild;
        } else if (strcmp(staff->id, current->Staff->id) > 0) {
            current = current->rightChild;
        } else {
            printf("Insert failed! Duplicate ID.\n");
            free(node);
            return;
        }
    }

    node->parent = parent;

    if (parent == NULL) {
        tree->root = node;
    } else if (strcmp(staff->id, parent->Staff->id) < 0) {
        parent->leftChild = node;
    } else {
        parent->rightChild = node;
    }

    rbTreeAdjust(tree, node);
}

void destroyTree(pStaffNode node) {
    if (node) {
        destroyTree(node->leftChild);
        destroyTree(node->rightChild);
        free(node->Staff);
        free(node);
    }
}

#endif
