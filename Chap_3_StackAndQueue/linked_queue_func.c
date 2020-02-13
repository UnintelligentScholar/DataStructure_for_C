/************单链队列（带头结点）************/
#include "stdio.h"
#include "stdlib.h"         //为了使用exit
#include "malloc.h"         //为了使用malloc、realloc、free等
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define endMark -731
typedef int Status;
typedef int elemType;

typedef struct QNode{
    elemType data;          //数据域
    struct QNode* next;     //指针域
} QNode, *queuePtr;         //队列中的任意一个结点
typedef struct {
    queuePtr head;          //队列头指针
    queuePtr tail;          //队列尾指针
} linkedQueue;              //单链队列

/**
 * 在终端打印输出
 * @param e
 */
void visit(elemType e){
    printf("%d ", e);
}//visit

/*****************1.1、初始化队列*******************/
Status initLinkedQueue(linkedQueue *Q){
    Q->head = Q->tail = (QNode*)malloc(sizeof(QNode));      //初始化得到一个头结点
    if(Q->head == NULL) exit(OVERFLOW);         //exit()函数在stdlib.h库中
    Q->head->next = NULL;
    return OK;
}//initLinkedQueue
/*****************1.2、求队列长*******************/
int lengthLinkedQueue(linkedQueue Q){
    int length;
    queuePtr p;
    for(length=0, p=Q.head->next; p!=NULL; length++, p=p->next);
        //判断条件不可以写p<=Q.tail，因为这是链队列，各结点地址不连续
    return length;
}//lengthLinkedQueue
/*****************1.3、销毁队列*******************/
Status destroyLinkedQueue(linkedQueue *Q){
    for(queuePtr p=Q->head; p!=NULL; p=p->next) free(p);        //销毁和清空的区别在于，前者将头结点也free掉
    Q->head = Q->tail = NULL;
    return OK;
}//destroyLinkedQueue
/*****************1.4、清空队列*******************/
Status clearLinkedQueue(linkedQueue *Q){
    for(queuePtr p=Q->head->next; p!=NULL; p=p->next) free(p);
    Q->head->next = NULL;
    Q->tail = Q->head;
    return OK;
}//clearLinkedQueue
/*****************1.5、查队列空*******************/
Status isEmptyLinkedQueue(linkedQueue Q){
    if(Q.head == Q.tail) return TRUE;       //若队列的头指针、尾指针指向同一个结点，则队列空
    else return FALSE;
}//isEmptyLinkedQueue
/*****************1.6、队头数据*******************/
Status getHeadLinkedQueue(linkedQueue Q, elemType* e){
    if(isEmptyLinkedQueue(Q)) return ERROR;
    *e = Q.head->next->data;
    return OK;
}//getHeadLinkedQueue
/*****************1.7、数据入队列********S***********/
Status enterLinkedQueue(linkedQueue *Q, elemType e){
    queuePtr s = (QNode*)malloc(sizeof(QNode));
    if(s == NULL) exit(OVERFLOW);
    s->data = e;
    s->next = Q->tail->next;
    Q->tail->next = s;
    Q->tail = s;
    return OK;
}//enterLinkedQueue
/*****************1.8、数据出队列*******************/
Status deleteLinkedQueue(linkedQueue *Q, elemType *e){
    if(isEmptyLinkedQueue(*Q)) return ERROR;

}//deleteLinkedQueue
/*****************1.9、遍历队列*******************/

int main(){

}