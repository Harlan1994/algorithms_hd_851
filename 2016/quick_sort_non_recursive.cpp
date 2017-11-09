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

typedef struct rec {
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
                rec2->left = rec1->left;
                rec2->right = partitial - 1;
                stack[++top] = rec2; // push into stack
            }

            // if right part are recursive
            if (rec1->right > partitial + 1) {
                Rec *rec3 = (Rec *) malloc(sizeof(rec));
                rec3->left = partitial + 1;
                rec3->right = rec1->right;
                stack[++top] = rec3; // push into stack
            }
        }
    }
}

int main() {
    int array1[] = {9, 8, 7, -6, 5, 4, 3, 2, 1, 0,
                    10, 12, 234, 234, 234, 456, 5672, -1, -345, -3245345,
                    -92340, -34, -99, 34, 324, 567, 347, 1234, -239, -9234};
    quick_sort_recursive(array1, 0, 29);
    std::cout << "recursive:" << std::endl;
    for (int i = 0; i < 29; i++) {
        std::cout << array1[i] << " ";
    }

    int array2[] = {9, 8, 7, -6, 5, 4, 3, 2, 1, 0,
                    10, 12, 234, 234, 234, 456, 5672, -1, -345, -3245345,
                    -92340, -34, -99, 34, 324, 567, 347, 1234, -239, -9234};
    std::cout << "\nnon-recursive:" << std::endl;
    quick_sort_non_recursive(array2, 0, 29);
    for (int i = 0; i < 29; i++) {
        std::cout << array2[i] << " ";
    }
    return 0;
}