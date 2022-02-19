#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define SIZEQ 5
//#define stack
#define queue 

using namespace std;

struct Stack {
    float element[100];
    int top;
};

struct Queue {
    int items[SIZEQ];
    int front;
    int rear;
};

void init(struct Stack* stk);
void push(struct Stack* stk, float f);
float pop(struct Stack* stk);
int isempty(struct Stack* stk);
void PrintS(struct Stack* stk);

/////////////////////////////////////////

bool isFull(struct Queue* qu);
bool isEmpty(struct Queue* qu);
void enQueue(struct Queue* qu, int elem);
int deQueue(struct Queue* qu);
void Printq(struct Queue* qu);

int main() {
#ifdef stack
    struct Stack* stk;
    int i, n;
    float elem;
    stk = (struct Stack*)malloc(sizeof(struct Stack));

    init(stk);

    cout << "Enter number of elements: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << endl << "Enter element " << i << ": ";
        cin >> elem;
        cout << endl;
        push(stk, elem);
    }

    PrintS(stk);

    do {
        cout << endl << "Take out element " << pop(stk) << endl;
    } while (isempty(stk) == 0);
#endif // stack

#ifdef queue
    struct Queue* qu;
    qu = (struct Queue*)malloc(sizeof(struct Queue));
    qu->front = -1;
    qu->rear = -1;

    enQueue(qu, 4);
    enQueue(qu, 5);
    enQueue(qu, 1);
    enQueue(qu, 15);
    enQueue(qu, 33);
    enQueue(qu, 44);
    deQueue(qu);
    Printq(qu);
#endif // queue

    return 0;
}

void init(struct Stack* stk) {
    stk->top = 0;
}

void push(struct Stack* stk, float f) {
    if (stk->top < 100) {
        stk->element[stk->top] = f;
        stk->top++;
    }
    else {
        cout << "Stack is full. Amount of elements: " << stk->top;
    }
}

float pop(struct Stack* stk) {
    float elem;
    if ((stk->top) > 0)
    {
        stk->top--;
        elem = stk->element[stk->top];
        return elem;
    }
    else
    {
        cout << "There aren't any elements";
        return 0;
    }
}

int isempty(struct Stack* stk) {
    if (stk->top == 0) return 1;
    else return 0;
}

void PrintS(struct Stack* stk) {
    int i;
    int cc = 0;
    i = stk->top;
    if (isempty(stk) == 1) return;
    do {
        i--;
        cout << "Element " << cc << ": " << stk->element[i];
        cc++;
    } while (i > 0);
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////

bool isFull(struct Queue* qu) {
    if (qu->front == 0 && qu->rear == SIZEQ - 1) {
        return true;
    }
    return false;
}

bool isEmpty(struct Queue* qu) {
    if (qu->front == -1)
        return true;
    else
        return false;
}

void enQueue(struct Queue* qu, int elem) {
    if (isFull(qu)) {
        cout << endl << "Queue is full" << endl;
    }
    else {
        if (qu->front == -1) qu->front = 0;
        qu->rear++;
        qu->items[qu->rear] = elem;
        cout << endl << "Element added: " << elem << endl;
    }
}

int deQueue(struct Queue* qu) {
    int element;
    if (isEmpty(qu)) {
        cout << "Empty queue" << endl;
        return (-1);
    }
    else {
        element = qu->items[qu->front];
        if (qu->front >= qu->rear) {
            qu->front = -1;
            qu->rear = -1;
        }
        else {
            qu->front++;
        }
        cout << endl << "Deleted element: " << element << endl;
        return (element);
    }
}
void Printq(struct Queue* qu) {
    int i;
    if (isEmpty(qu)) {
        cout << endl << "Empty Queue" << endl;
    }
    else {
        cout << endl << "Index FRONT -> " << qu->front << endl;
        cout << endl << "Elements -> ";
        for (i = qu->front; i <= qu->rear; i++)
            cout << qu->items[i] << "  ";
        cout << endl << endl << "Index REAR-> " << qu->rear << endl;
    }
}