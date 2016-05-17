/*
 * =====================================================================================
 *
 *       Filename:  example_1.c
 *
 *    Description:  realize the dijkstra algorithm on graph 24-6 on page 384
 *
 *        Version:  1.0
 *        Created:  2015年10月16日 14时47分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <limits.h>
#include "example_1.h"

Graph *Graph_Init (int num_vertex, int num_line, int (*array)[5]) {
    Graph *G = malloc(sizeof(*G));
    G->v_set = malloc(num_vertex * sizeof(Vertex));     // create set of vertex
    G->l_set = malloc(num_line * sizeof(Line));         // create set of line

    int i, j;
    G->num_vertex = num_vertex;
    G->num_line = num_line;
    // initialize vertexs
    for (i = 0 ; i < num_vertex ; i++) {
        (G->v_set)[i].ID = i;
        (G->v_set)[i].shortest_distance = INT_MAX;
        (G->v_set)[i].succeed_node = NULL;
        (G->v_set)[i].best_prev = NULL;

        Succeed_node *new, *current;
        for (j = 0 ; j < num_vertex ; j++) {
            if (array[i][j] != 0 && array[i][j] != INT_MAX) {
                new = malloc(sizeof(Succeed_node));         // add a succeed_node
                new->v = &(G->v_set)[j];
                new->length = array[i][j];
                new->next = NULL;
                if ((G->v_set)[i].succeed_node == NULL) {
                    (G->v_set)[i].succeed_node = new;
                    current = new;
                }
                else {
                    current->next = new;
                    current = current->next;
                }

            }
        }
    }
    // initialize lines
    int k = 0;
    for (i = 0 ; i < num_vertex ; i++) {
        for (j = 0 ; j < num_vertex ; j++) {
            if (array[i][j] != 0 && array[i][j] != INT_MAX) {
                (G->l_set)[k].start = &(G->v_set)[i];
                (G->l_set)[k].end = &(G->v_set)[j];
                (G->l_set)[k].length = array[i][j];
                k++;
            }
        }
    }

    return G;
}

// return the min shortest_distance of the vertexs
Vertex *Extract_Min (Vertex_List **Q_ptr) {
    Vertex *min_vertex;
    Vertex_List *min_list;
    Vertex_List *p = *Q_ptr;
    int min_distance = INT_MAX;
    while (p) {
        if (p->v->shortest_distance < min_distance) {
            min_list = p;
            min_vertex = p->v;
            min_distance = p->v->shortest_distance;
        }
        p = p->next;
    }
    if (min_distance == INT_MAX)
        return NULL;

    // delete min_list
    if (min_list->prev == NULL && min_list->next != NULL) {
        // min_list is the head
        *Q_ptr = min_list->next;
        (*Q_ptr)->prev = NULL;
    }
    else if (min_list->prev != NULL && min_list->next == NULL) {
        // min_list is the tail
        min_list->prev->next = NULL;
    }
    else if (min_list->prev == NULL && min_list->next == NULL) {
        // min_list is also head and tail
        *Q_ptr = NULL;
    }
    else {
        // min_list is the mid
        min_list->prev->next = min_list->next;
        min_list->next->prev = min_list->prev;
    }

    free(min_list);
    return min_vertex;
}

void Insert (Vertex_List **S, Vertex *u) {
    Vertex_List *new = malloc(sizeof(*new));
    new->v = u;
    new->prev = NULL;
    new->next = NULL;

    Vertex_List *current;
    // if *S is NULL
    if (!*S) {
        *S = new;
        current = *S;
    }
    else {
        while (current->next)
            current = current->next;
        current->next = new;
        new->prev = current;
    }
}

void Relax (Vertex *u, Succeed_node *p) {
    while (p) {
        int temp = u->shortest_distance + p->length;
        if (p->v->shortest_distance > temp) {
            p->v->shortest_distance = temp;
            p->v->best_prev = u;
        }
        p = p->next;
    }
}


void Dijkstra_Algorithm (Graph *G, Vertex *s) {
    // initialize S and Q
    Vertex_List *S = NULL;
    Vertex_List *Q = NULL;
    int i;
    Vertex_List *current, *new;
    for (i = 0 ; i < G->num_vertex ; i++) {
        new = malloc(sizeof(*new));
        new->v = &(G->v_set)[i];
        new->prev = NULL;
        new->next = NULL;
        if (i == 0) {
            Q = new;
            current = Q;
        }
        else {
            current->next = new;
            new->prev = current;
            current = current->next;
        }
    }

    s->shortest_distance = 0;
    Vertex *u;
    while (Q) {
        u = Extract_Min(&Q);
        Insert(&S, u);
        Succeed_node *p = u->succeed_node;
        while (p) {
            Relax(u, p);
            p = p->next;
        }
    }
}

int main (void) {
    Graph *G;
    int num_vertex = 5;
    int num_line = 10;
    int array[5][5] = {
                        { 0, 10, INT_MAX, 5, INT_MAX },
                        { INT_MAX, 0, 1, 2, INT_MAX },
                        { INT_MAX, INT_MAX, 0, INT_MAX, 4 },
                        { INT_MAX, 3, 9, 0, 2 },
                        { 7, INT_MAX, 6, INT_MAX, 0 }
                      };
    G = Graph_Init(num_vertex, num_line, array);
    Vertex *s = &(G->v_set)[0];
    Dijkstra_Algorithm(G, s);
    return 0;
}

