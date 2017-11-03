#include <malloc.h>
#include <iostream>


/**
 * ���ݵ��ӿƼ���ѧ���ݽṹ851 2016���һ��
 * <p>
 * ��д��ͷ�ڵ�ĵ�����L��ɾ����Сֵ�ڵ�ĸ�Ч�㷨��������Сֵ�ڵ���Ψһ�ģ�
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
    head->value = length; // ���治�ܳ�Խ�����ֵ
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
    Node *p = linkedList->next; // ���浱ǰ��Сֵ������һ���ڵ�
    Node *q = linkedList; // ָ��ǰ��Сֵ��ǰ��
    while (p->next) {
        if (p->next->value < q->next->value) { // ÿ�ζ��͵�ǰ��Сֵ�Ƚϣ�С�ڵ�ǰ��Сֵ�������Сֵ�ڵ��ǰ��
            q = p;
        }
        p = p->next;
    }

    std::cout << "��Сֵ��" << q->next->value << std::endl;

    // ɾ��
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