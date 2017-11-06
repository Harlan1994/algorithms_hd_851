//
// Created by Harlan1994 on 2017/11/6.
//

#define MAX_SIZE 100

typedef int DataType;

typedef struct {
    int adj_vex;
    struct ArcNode *next;
} ArcNode;

typedef struct {
    DataType data;
    ArcNode *first_arc;
} VNode;

typedef struct {
    VNode adj_list[MAX_SIZE];
    int n, e;
};

int main(void) {
    return 0;
}