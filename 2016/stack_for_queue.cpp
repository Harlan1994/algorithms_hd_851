//
// Created by Harlan on 2017/1/7.
//

// http://blog.csdn.net/zdp072/article/details/19755675
#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    int pop() {
        // write your code here
        int e;
        if (!stack2.empty()) {
            e = stack2.top();
            stack2.pop();
        } else {
            while (stack1.size() > 1) {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            e = stack1.top();
            stack1.pop();
        }
        return e;
    }

    int top() {
        // write your code here
        int e;
        if (!stack2.empty()) {
            e = stack2.top();
        } else {
            while (!stack1.empty()) {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            e = stack2.top();
        }
        return e;
    }
};

int main() {
    /*Queue q;
    q.push(1);
    cout << q.pop() << " ";
    q.push(2);
    q.push(3);
    cout << q.top() << " ";
    cout << q.pop() << endl;*/
    int a;
    while (scanf("%d", &a) != EOF) {
        int count = 0;
        //unsigned int b = (unsigned int) a;
        while (a) {
            a = a & (a - 1);
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}