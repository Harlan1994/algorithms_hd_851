//
// Created by Harlan1994 on 2017/11/15.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define MAX_SIZE 100

typedef struct ArcNode {
    int adj_vex;
    struct ArcNode *next;
    int info;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode *first;
} VNode;

typedef struct {
    VNode adj_list[MAX_SIZE];
    int n, e;
} AGraph;

// create graph according to matrix and size n.
AGraph *create_graph(int matrix[][5], int n) {
    AGraph *graph = (AGraph *) malloc(sizeof(AGraph));
    graph->n = n;
    graph->e = 0;

    for (int i = 0; i < n; i++) {
        graph->adj_list[i].first = NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                graph->e++;
                ArcNode *newNode = (ArcNode *) malloc(sizeof(ArcNode));
                newNode->adj_vex = j;
                newNode->next = graph->adj_list[i].first;
                graph->adj_list[i].first = newNode;
            }
        }
    }

    cout << "totally " << graph->e << " edges." << endl;

    // check if it is created correctly
//    for (int i = 0; i < n; i++) {
//        cout << "i = " << i << endl;
//        ArcNode *first = graph->adj_list[i].first;
//        while (first != NULL) {
//            cout << first->adj_vex << " ";
//            first = first->next;
//        }
//        cout << endl;
//    }

    return graph;
}


// find all nodes that is len step to v node
// v [0, 4]
// n refers to the node number
void bfs(AGraph *graph, int v, int len, int n) {
    queue<int> queue;
    set<int> myset;
    queue.push(v);
    int dist = 0;
    while (!queue.empty()) {
        int size = queue.size();
        while (size-- > 0) {
            int out = queue.front();
            queue.pop();
            ArcNode *p = graph->adj_list[out].first;
            while (p) {
                queue.push(p->adj_vex);
                p = p->next;
            }
        }
        // every time dist++ if nodes of a certain level was pushed into queue.
        dist++;
        // and if dist == len, meaning that current nodes in queue are len far from v
        // just print it
        if (dist == len) {
            while (!queue.empty()) {
                if (queue.front() != v) { // in case that a circle contains v, and v is the len th one.
                    myset.insert((int) queue.front());
                }
                queue.pop();
            }

            // elements maybe duplicated, so use set instead.
            set<int>::iterator it;
            for (it = myset.begin(); it != myset.end(); ++it)
                cout << (*it) << " ";
            return;
        }
    }

}


int main() {
    int matrix[5][5] = {
            {0, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
    };

    AGraph *graph = create_graph(matrix, 5);

    bfs(graph, 0, 2, 5);
    return 0;
}