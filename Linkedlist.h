#ifndef LISKEDLIST_H_INCLUDED
#define LISKEDLIST_H_INCLUDED

/**
   * 代码实现功能：链表
   * 时间：2021.11.25
   * 作者：MW
   */

//头结点的位置数据存放的是链表长度
typedef struct List{
    int Position;   //结点位置
    int data;        //结点数据
    struct List* next;
}List;

#define dataNotVal -1   //data数据不正确的一个赋值

List* CreateList(int number);//创建一个长度为number的链表（不含头结点）
void PrintList(List* head);//打印所有链表的数据部分
void ClearList(List* head);//清除链表
int ListLength(List* head);//获得链表长度
int FindNodePosition(List* head,int aimPosition);//查找某个位置的节点
void HeadAddNode(List* head,int number);//头插法插入number个结点
void TailAddNode(List* head,int number);//尾插法插入number个结点
void deleteNode(List* head,int aimPosition);//删除某个位置上的结点
void insertNode(List* head,int aimPosition);//在某个结点位置上插入一个结点

#endif // LISKED_LIST_H_INCLUDED
