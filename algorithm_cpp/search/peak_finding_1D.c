/*
 * =====================================================================================
 *
 *       Filename:  peak_finding_1D.c
 *
 *    Description:  find a peak in 1D array
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 15时17分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 100

typedef struct NODE {
    int value;
    struct NODE *next;
} Node;

static Node *store_peak[N];
static int count = 0;

void Init_Store_Peak (void) {
    int i;
    for (i = 0 ; i < N ; i++)
        store_peak[i] = 0x0;
}

bool Exist (Node *current, Node **store_peak) {
    int i = 0;
    while(store_peak[i]) {
        if (current == store_peak[i])
            return true;
        i++;
    }
    return false;
}

void Display (Node **index) {
    int i;
    for (i = 0 ; i < N ; i++) {
        if (Exist(index[i], store_peak))
            printf("%d <--\n",index[i]->value);
        else
            printf("%d\n",index[i]->value);
    }
}

void Create_List (Node **current, Node **index) {
    int i;
    for (i = 0 ; i < N ; i++) {
        *current = malloc(sizeof(**current));
        (*current)->value = random() % 100;
        index[i] = *current;
        current = &(*current)->next;
    }
    *current = NULL;
}

void Free_List (Node *current) {
    Node *free_node;
    while (current) {
        free_node = current;
        current = current->next;
        free(free_node);
    }
}

void Peak_Finding_1D (Node **index, int left, int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (index[left]->value > index[middle]->value)
            Peak_Finding_1D(index, left, middle-1);
        else if (index[right]->value > index[middle]->value)
            Peak_Finding_1D(index, middle+1, right);
        /* if you want to find all peak */
        // if (index[right]->value > index[middle]->value)
            // Peak_Finding_1D(index, middle+1, right);
        else
            store_peak[count++] = index[middle];
    }
}

int main (void) {
    Node *root;
    Node *index[N];
    Init_Store_Peak();
    Create_List(&root, index);
    Peak_Finding_1D(index, 0, N-1);
    Display(index);
    Free_List(root);
    return 0;
}

