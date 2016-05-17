/*
 * =====================================================================================
 *
 *       Filename:  example_1.h
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
/* data structure */
typedef struct VERTEX Vertex;

typedef struct SUCCEED_NODE {
    Vertex *v;                             // the vertex ID
    int length;
    struct SUCCEED_NODE *next;
} Succeed_node;

typedef struct VERTEX {
    int ID;                             // the identity of vertex
    int shortest_distance;              // the shortest_distance from the single source to this vector
    Succeed_node *succeed_node;         //the list which collect all the succeed vertexs
    struct VERTEX *best_prev;                  // the previous vertex of the shortest_distance
} Vertex;

typedef struct LINE {
    Vertex *start;
    Vertex *end;
    int length;
} Line;

typedef struct GRAPH {
    Vertex *v_set;
    Line *l_set;
    int num_vertex;
    int num_line;
} Graph;

typedef struct VERTEX_LIST {
    Vertex *v;
    struct VERTEX_LIST *prev;
    struct VERTEX_LIST *next;
} Vertex_List;

