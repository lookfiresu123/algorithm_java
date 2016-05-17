/*
 * =====================================================================================
 *
 *       Filename:  peak_finding_2D.c
 *
 *    Description:  find a peak in 2D array
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

#define M 9
#define N 9

typedef struct NODE {
    int value;
    struct NODE *next;
} Node;

static Node *store_peak[M * N];
static int count = 0;

void Init_Store_Peak (void) {
    int i;
    for (i = 0 ; i < M*N; i++)
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

void Display (Node *(*index)[N]) {
    int i, j;
    for (i = 0 ; i < M ; i++) {
    	for (j = 0 ; j < N ; j++) {
    		if (Exist(index[i][j], store_peak))
    			printf(">%d< ", index[i][j]->value);
    		else
    			printf(" %d  ", index[i][j]->value);
    	}
    	printf("\n");
    }
}

void Create_List (Node **current, Node *(*index)[N]) {
    int i, j;
    for (i = 0 ; i < M ; i++) {
    	for (j = 0 ; j < N ; j++) {
        	*current = malloc(sizeof(**current));
        	(*current)->value = random() % 100;
        	index[i][j] = *current;
        	current = &(*current)->next;
    	}
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

int Max_Find_1D (Node **column_data) {
	int max_index = 0;
	int i;
	for (i = 1 ; i < M ; i++)
		if (column_data[i]->value > column_data[max_index]->value)
			max_index = i;
	return max_index;
}

void Peak_Finding_2D (Node *(*index)[N], int left, int right) {
	if (left <= right) {
		/* find the index of the node whose value is the max in the middle column */
		Node *column_data[M];
		int middle = (left + right) / 2;
		int i;
		for (i = 0 ; i < M ; i++)
			column_data[i] = index[i][middle];
		int max_index = Max_Find_1D(column_data);

		/* compare along middle, middle-1, middle+1 */
		if (index[max_index][middle-1] > index[max_index][middle])
			Peak_Finding_2D(index, left, middle-1);
		else if (index[max_index][middle+1] > index[max_index][middle])
			Peak_Finding_2D(index, middle+1, right);
		else
			store_peak[count++] = index[max_index][middle];
	}
}

int main (void) {
    Node *root;
    Node *index[M][N];
    Init_Store_Peak();
    Create_List(&root, index);
    Peak_Finding_2D(index, 0, N-1);
    Display(index);
    Free_List(root);
    return 0;
}