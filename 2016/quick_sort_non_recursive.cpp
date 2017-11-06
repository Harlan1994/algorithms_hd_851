/**
 * Created by Harlan1994 on 2017/11/3.
 * 非递归编写快速排序
 */
#include <iostream>

int partition(int array[], int left, int right) {
    int pivotkey = array[left];
    while (left < right) {
        while (array[right] >= pivotkey && right > left)right--;
        array[left] = array[right];
        while (array[left] <= pivotkey && right > left)left++;
        array[right] = array[left];
    }
    array[left] = pivotkey;

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return left;
}

// recursive
int quick_sort_recursive(int array[], int left, int right) {
    if (left < right) {
        int partial = partition(array, left, right);
        quick_sort_recursive(array, left, partial - 1);
        quick_sort_recursive(array, partial + 1, right);
    }
}

typedef struct {
    int left;
    int right;
} Rec;

// non_recursive
int quick_sort_non_recursive(int array[], int left, int right) {

    // stack
    Rec *stack[right + left + 1];
    int top = -1;

    if (left < right) {
        Rec *rec0 = (Rec *) malloc(sizeof(rec));
        rec0->left = left;
        rec0->right = right;
        stack[++top] = rec0; // push into stack

        while (top != -1) { // while stack is not empty

            // std::cout << "top = " << top << std::endl;

            Rec *rec1 = stack[top--]; // pop
            int partitial = partition(array, rec1->left, rec1->right);

            // if left part are recursive
            if (rec1->left < partitial - 1) {
                Rec *rec2 = (Rec *) malloc(sizeof(rec));
                rec2->left = left;
                rec2->right = partitial - 1;
                stack[++top] = rec2; // push into stack
            }

            // if right part are recursive
            if (rec1->right > partitial + 1) {
                Rec *rec3 = (Rec *) malloc(sizeof(rec));
                rec3->left = partitial + 1;
                rec3->right = right;
                stack[++top] = rec3; // push into stack
            }
        }
    }
}

int main() {
    int array[] = {1, 3, 4, 6, 0, -8, 5, 2, 8, -2};
    quick_sort_recursive(array, 0, 9);
    std::cout << "recursive:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nnon-recursive:" << std::endl;
    quick_sort_non_recursive(array, 0, 9);
    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}