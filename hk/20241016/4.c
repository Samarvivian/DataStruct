//	问题描述：
//设停车场是一个可停放n 辆汽车的狭长通道，且只有一个大门可供汽车进出。
//汽车在停车场内按车辆达到时间的先后顺序，依次由北向南排列
//（大门在最南端，最先达到的第一辆车停放在车场的最北端），若车场内已停满n辆汽车，
//则后来的汽车只能在门外的便道上等候，一旦有车开走，则排在便道上的第一辆车即可开入；
//当停车场内某辆车要离开时，在它之后进入的车辆必须先退车车场为它让路，
//待赶辆车开出大门外，其它车辆在按原次序进入车场，
//每辆停放在车场的车在它离开停车场时必须按它停留的时间长短叫纳费用。
//试为停车场编制按上述要求进行管理的模拟程序。
//	基本要求
//（1）以栈模拟停车场，以队列模拟车场外的便道，按照从终端读入的输入数据序列进行模拟管理。
//每一组输入数据包括三个数据项：汽车“达到”或“离去”信息、汽车牌照号码以及达到或离去的时刻。
//对每一组输入数据进行操作后的输出信息为：
//若是车辆达到，则输出汽车在停车场内或便道上停车位置；
//若是车辆离去，则输出汽车在停车场内停留的时间和应交纳的费用（在便道上停留的时间不收费）。
//栈以顺序结构实现，队列以链表结构实现。
//2）最好有操作菜单。
//	测试数据
/*设n=2，输入数据为(“A”,1,5), (“A”,2,10), (“A”,3,11), (“D”,1,15), (“D”,2,35), 
(“E”,0,0)。
其中：“A”表示达到（Arrival）;“D”表示离去(Departure); “E”表示输入结束(End)。
3 实现提示：
需另设一个栈，临时停放为给要离去的汽车让路而从停车场退出来的汽车，
也用顺序存储结构实现。输入数据按达到或离去的时刻有序。
栈中每个元素表示一辆汽车，包括两个数据项：汽车的牌照号码和进入停车场的时刻。
4 实验要求：
（1）写出全部源程序；
请写出对应的c程序*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#include<time.h>

#define ok 1
#define n 2
#define error -1
#define unit 5//定义每小时5元

typedef int Status;
typedef struct Car
{
    int carnum;
    int arrivetime;
    
}Car;


typedef struct Stack//定义栈
{
    Car car[n];//定义一个静态顺序栈
    int top;//指向栈顶，栈空时为0
    
}Stack;

typedef struct QNode//定义链表
{
    Car car;
    struct QNode *next;
}QNode;
typedef struct Queue//定义队列
{
    QNode *front;
    QNode *rear;
}Queue;

Status CarInit(Car *car)
{
    car->arrivetime=0;
    car->carnum=0;
}

Status StackInit(Stack *s)
{
    assert(s);
    s->top=0;
    
    
    return ok;
}

Status StackIsEmpty(Stack s)//判断停车场是否空，空就返回1
{
    return s.top==0;
}

Status StackIsFull(Stack s)//判断停车场是否为满，满返回1
{
    return s.top==n;
}

Status StackPush(Stack *s,Car newcar)//有车要进入停车场
{
    assert(s);
    // if(StackIsFull(s))
    // {
    //     printf("停车场已满，无法进入\n");
    //     return error;
    // }
    // else
    // {
        
    // }
    // newcar.arrivetime=time;
    // newcar.carnum=num;
    s->car[s->top]=newcar;
    s->top++;
    return ok;

}

Car StackPop(Stack *s)//有车要离开停车场
{
    assert(s);
    // if(StackIsEmpty(s))
    // {
    //     //printf("停车场已空\n");
    //     Car car;//定义一个无效车
    //     car.carnum=-1;
    //     return car;
    // }
    // else
    // {
    //     return s->car[s->top--];
    // }
    return (s->car[s->top--]);
   
}

Car StackGetTail(Stack *s)//获取停车场中停在最后的一辆车的位置
{
    int i=s->top-1;
    return (s->car[i]);
}

int StackGetsize(Stack s)//获取新车在停车场上的位置
{
    return s.top;
}

Status QueueInit(Queue *q)
{
    assert(q);
    q->front=q->rear=NULL;
    return ok;
}

// Status QueuePush(Queue *q,Car newcar,int num,int time)//有新车要进入便道
// {
//     assert(q);
//     newcar.arrivetime=time;
//     newcar.carnum=num;
//     QNode *newnode=(QNode*)malloc(sizeof(QNode));
//     if(!newnode)
//     {
//         exit(-1);
//     }
//     newnode->car=newcar;
//     newnode->next=NULL;

//     if(!q->front)
//     {
//         q->front=q->rear=newnode;
//     }
//     else
//     {
//         q->rear->next=newnode;
//         q->rear=newnode;
//     }
//     return ok;
// }

Status QueuePush(Queue *q,Car newcar)//有新车要进入便道
{
    assert(q);
    
    QNode *newnode=(QNode*)malloc(sizeof(QNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->car=newcar;
    newnode->next=NULL;

    if(!q->front)
    {
        q->front=q->rear=newnode;
    }
    else
    {
        q->rear->next=newnode;
        q->rear=newnode;
    }
    return ok;
}

Status QueueIsEmpty(Queue q)//判断便道是否为空，为空返回1
{
    return q.front==NULL;
}

Car QueuePop(Queue *q)//有车要从便道进入停车场
{
    assert(q);
    // if(QueueIsEmpty(q))
    // {
    //     printf("便道为空\n");
    //     Car car;
    //     car.carnum=-1;
    //     return car;
    // }
    // else
    // {
    //     QNode *newnode=q->front;
    //     q->front=newnode->next;
    //     if(!q->front)//删完队列最后一个元素
    //     {
    //         q->front=q->rear=NULL;
    //     }
    //     Car car=newnode->car;
    //     free(newnode);
    //     return car;
    // }
    QNode *newnode=q->front;
    q->front=newnode->next;
    if(!q->front)//删完队列最后一个元素
    {
        q->front=q->rear=NULL;
    }
    Car car=(newnode->car);
    free(newnode);
    return car;
}

int QueueGetsize(Queue q)//获取新车在便道上的位置
{
    return q.rear-q.front+1;
}

void menu()
{
    printf("-----------------请选择--------------\n");
    printf("----A.Arrival----D.Departure----E.End\n");

}

void game()
{
    char choice=0;
    Car newcar;
    Stack parkinglot,temp;
    Queue waitingline;
    int carnum=0;
    int arrivetime=0;
    int leavetime=0;
    //float fee=0;//在停车场应缴纳的费用

    StackInit(&parkinglot);
    StackInit(&temp);
    QueueInit(&waitingline);
    CarInit(&newcar);

    

    while(1)
    {
        menu();
        scanf("%c",&choice);
        
        if(choice=='E')
        {
            break;
        }
        if(choice=='A')
        {
            printf("请输入车牌号:");
            scanf("%d",&carnum);
            newcar.carnum=carnum;
            printf("请输入此刻时间:");
            scanf("%d",&arrivetime);
            

            if(StackIsFull(parkinglot))
            {
                newcar.arrivetime=0;
                printf("停车场已满，请到便道等待\n");
                QueuePush(&waitingline,newcar);
                printf("车%d在便道上第%d个位置\n",carnum,QueueGetsize(waitingline));
            }
            else
            {
                newcar.arrivetime=arrivetime;
                StackPush(&parkinglot,newcar);
                printf("车%d在停车场上第%d个位置\n",carnum,StackGetsize(parkinglot));
                
            }
            
        }
        else if(choice=='D')
        {
            printf("请输入车牌号:");
            scanf("%d",&carnum);
            newcar.carnum=carnum;
            printf("请输入离去时间:");
            scanf("%d",&leavetime);
            

            // while(((StackGetTail(&parkinglot)).carnum)!=(newcar.carnum))
            // {
                
            //     Car carafter=StackPop(&parkinglot);
            //     StackPush(&temp,carafter);
            // }
            // time_t rawtime;
            // struct tm * timeinfo;

            // time (&rawtime);
            // timeinfo = localtime (&rawtime);//显示现在时间
            //newcar=parkinglot.car[parkinglot.top];

            //int found = 0; // 标记是否找到要离开的车辆
            // while (!StackIsEmpty(parkinglot)) 
            // {
            //     Car car = StackGetTail(&parkinglot);
            //     if (car.carnum == newcar.carnum) 
            //     {
            //         //found = 1; // 找到要离开的车辆
            //         break;
            //     } 
            //     else 
            //     {
                    
            //         StackPush(&temp, StackPop(&parkinglot)); // 将车辆移动到临时栈中
            //     }
            // }

            Car carToLeave; // 要离开的车辆信息
            CarInit(&carToLeave);
           
            while (!StackIsEmpty(parkinglot)) 
            {
                Car car = StackPop(&parkinglot); // 弹出栈顶车辆
                if (car.carnum == newcar.carnum)
                {
                    carToLeave = car; // 保存要离开的车辆信息
                    break;
                } 
                else 
                {
                    StackPush(&temp, car); // 将车辆移动到临时栈中
                }
            }

                
            printf("车%d已经离开停车场，费用为%d\n",carnum,(leavetime-carToLeave.arrivetime)*unit);
            //StackPop(&parkinglot);
            
            //把原来的车放回去
            while(!(StackIsEmpty(temp)))
            {
                StackPush(&parkinglot,(StackPop(&temp)));
            }
            //判断过道上是否有车，有的话放进去
            if(!(QueueIsEmpty(waitingline)))
            {
                Car carin=QueuePop(&waitingline);
                carin.arrivetime=leavetime;
                StackPush(&parkinglot,carin);
            }
        }
        getchar();
    }
}

int main()
{
    game();
    return 0;
}
