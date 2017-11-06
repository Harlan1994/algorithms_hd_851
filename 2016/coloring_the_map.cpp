//
// Created by Harlan1994 on 2017/11/6.
//

#define MAX_SIZE 100

typedef struct {
    int no;
    char *info;
} VertexType;

typedef struct {
    int edges[MAX_SIZE][MAX_SIZE];
    int n, e;
    VertexType vertex[MAX_SIZE];
} MGraph;

int color[MAX_SIZE + 1]; // 保存每个节点的颜色，1，2，3，4表示

bool ok(MGraph *G, int step) { // step表示当前步数，也代表当前的节点编号
    // 遍历邻接矩阵相邻节点是否有相同颜色
    for (int i = 1; i <= G->n && i != step; i++) {
        if (color[i] == color[step])return false;
    }
    return true;
}

// 深度优先的思想
/**
 * 首先递归需要一个出口，就是所有的都递归完了，即step==节点个数时，返回
 * 每次进入下一个节点的时候，试探四种颜色，然后判断是否可以行
 * @param G
 * @param step
 * @param color_num
 * @return
 */
bool dfs(MGraph *G, int step, int color_num) {
    if (step == G->n)return true;
    else {
        for (int i = 1; i <= color_num; i++) {
            color[step] = i;
            if (ok(G, step)) { // 如果当前可行则继续递归下去
                if (dfs(G, step + 1, color_num)){
                    return true;
                }
            }
            color[step] = 0;
        }
    }
    return false;
}

int main(void) {

    // 这题不好测试，就不测试了
    return 0;
}

