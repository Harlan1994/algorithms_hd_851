#include <malloc.h>
#include <iostream>


/**
 * 杭州电子科技大学数据结构851 2016年第一题
 * <p>
 * 编写带头节点的点链表L中删除最小值节点的高效算法（假设最小值节点是唯一的）
 * Created by Harlan1994 on 2017/11/3.
 */
typedef int DataType;

typedef struct Node {
    DataType value;
    struct Node *next;
} Node, LinkedList;

LinkedList *create_list(DataType list[], int length) {
    Node *head = (Node *) malloc(sizeof(Node));
    Node *tmp = head;
    if (!head)return NULL;
    head->value = length; // 保存不能超越的最大值
    head->next = NULL;
    for (int i = 0; i < length; ++i) {
        Node *s = (Node *) malloc(sizeof(Node));
        if (!s)return NULL;
        s->value = list[i];
        s->next = NULL;
        tmp->next = s;
        tmp = s;
    }

    return head;
}

DataType findMinimum(LinkedList *linkedList) {
    Node *p = linkedList->next; // 保存当前最小值，即第一个节点
    Node *q = linkedList; // 指向当前最小值的前驱
    while (p->next) {
        if (p->next->value < q->next->value) { // 每次都和当前最小值比较，小于当前最小值则更新最小值节点的前驱
            q = p;
        }
        p = p->next;
    }

    std::cout << "最小值：" << q->next->value << std::endl;

    // 删除
    Node *toDelete = q->next;
    q->next = q->next->next;
    free(toDelete);
    toDelete = NULL;
}

int main() {
    DataType list[10] = {1, 3, 4, 6, 8, -2, -4, 5, 6, 0};
    LinkedList *linkedList = create_list(list, 10);
    findMinimum(linkedList);
    return 0;
}