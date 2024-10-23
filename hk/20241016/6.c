#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define OK 1
#define N 2
#define ERROR -1
#define UNIT 5 // 定义每小时5元

typedef int Status;
typedef struct Car {
    int carnum;
    int arrivetime;
} Car;

typedef struct Stack {
    Car car[N]; // 定义一个静态顺序栈
    int top; // 指向栈顶，栈空时为0
} Stack;

typedef struct QNode {
    Car car;
    struct QNode *next;
} QNode;

typedef struct Queue {
    QNode *front;
    QNode *rear;
} Queue;

Status StackInit(Stack *s) {
    assert(s);
    s->top = 0;
    return OK;
}

Status StackIsEmpty(Stack s) {
    return s.top == 0;
}

Status StackIsFull(Stack s) {
    return s.top == N;
}

Status StackPush(Stack *s, Car newcar) {
    assert(s);
    if (StackIsFull(*s)) {
        return ERROR;
    } else {
        s->car[s->top] = newcar;
        s->top++;
        return OK;
    }
}

Car StackPop(Stack *s) {
    assert(s);
    if (StackIsEmpty(*s)) {
        Car car = {-1, 0}; // 定义一个无效车
        return car;
    } else {
        return s->car[s->top--];
    }
}

Car StackGetTop(Stack *s) {
    assert(s);
    if (StackIsEmpty(*s)) {
        Car car = {-1, 0}; // 定义一个无效车
        return car;
    } else {
        return s->car[s->top - 1];
    }
}

Status QueueInit(Queue *q) {
    assert(q);
    q->front = q->rear = NULL;
    return OK;
}

Status QueueIsEmpty(Queue q) {
    return q.front == NULL;
}

Status QueuePush(Queue *q, Car newcar) {
    assert(q);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (!newnode) {
        exit(-1);
    }
    newnode->car = newcar;
    newnode->next = NULL;
    if (!q->front) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    return OK;
}

Car QueuePop(Queue *q) {
    assert(q);
    if (QueueIsEmpty(*q)) {
        Car car = {-1, 0}; // 定义一个无效车
        return car;
    } else {
        QNode *node = q->front;
        q->front = node->next;
        if (!q->front) {
            q->rear = NULL;
        }
        Car car = node->car;
        free(node);
        return car;
    }
}

int QueueGetSize(Queue q) {
    int count = 0;
    QNode *current = q.front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void Menu() {
    printf("-----------------请选择--------------\n");
    printf("----A.Arrival----D.Departure----E.End\n");
}

void Game() {
    char choice = 0;
    Car newcar, carToLeave;
    Stack parkinglot, temp;
    Queue waitingline;
    int carnum = 0, arrivetime = 0, leavetime = 0;

    StackInit(&parkinglot);
    StackInit(&temp);
    QueueInit(&waitingline);
    CarInit(&newcar);

    while (1) {
        Menu();
        scanf(" %c", &choice);
        
        if (choice == 'E') {
            break;
        }

        if (choice == 'A') {
            printf("请输入车牌号: ");
            scanf("%d", &carnum);
            newcar.carnum = carnum;
            printf("请输入此刻时间: ");
            scanf("%d", &arrivetime);

            if (StackIsFull(parkinglot)) {
                newcar.arrivetime = 0;
                printf("停车场已满，请到便道等待\n");
                QueuePush(&waitingline, newcar);
                printf("车%d在便道上第%d个位置\n", carnum, QueueGetSize(waitingline));
            } else {
                newcar.arrivetime = arrivetime;
                StackPush(&parkinglot, newcar);
                printf("车%d在停车场上第%d个位置\n", carnum, StackGetsize(parkinglot));
            }
        } else if (choice == 'D') {
            printf("请输入车牌号: ");
            scanf("%d", &carnum);
            newcar.carnum = carnum;
            printf("请输入离去时间: ");
            scanf("%d", &leavetime);

            int found = 0;
            while (!StackIsEmpty(parkinglot)) {
                carToLeave = StackPop(&parkinglot);
                if (carToLeave.carnum == newcar.carnum) {
                    found = 1;
                    break;
                } else {
                    StackPush(&temp, carToLeave);
                }
            }

            if (found) {
                int fee = (leavetime - carToLeave.arrivetime) * UNIT;
                printf("车%d已经离开停车场，停车费用为%d元\n", carToLeave.carnum, fee);
            } else {
                printf("车%d不在停车场内\n", carnum);
            }

            while (!StackIsEmpty(&temp)) {
                StackPush(&parkinglot, StackPop(&temp));
            }

            if (!QueueIsEmpty(&waitingline)) {
                newcar = QueuePop(&waitingline);
                newcar.arrivetime = leavetime;
                StackPush(&parkinglot, newcar);
            }
        }
        getchar();
    }
}

int main() {
    Game();
    return 0;
}