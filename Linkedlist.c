#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

/**
    *以下为文件内调用的功能文件，不做外部引用使用
    */
List*  creatNewNode();

//新建一个结点，并赋予初值
List*  creatNewNode(){
    List* tempNode;
    tempNode = (List*)malloc(sizeof(List));
    tempNode->Position = -1;
    tempNode->data = dataNotVal;
    tempNode->next = NULL;
    return tempNode;
}

//将没有数据的结点录入数据
void inputListData(List* head){
    int i;
    List* workP = head;    //工作指针
    while(workP->next != NULL){
        workP = workP->next;
        if(workP->data == dataNotVal){//如果数据为空才录入数据
            printf("请输入第%d位的数据：",workP->Position);
            scanf("%d",&workP->data);
        }
    }
}

//打印结点的所有信息
//model为0时打印所有信息，为1时值打印数据部分没有结点位置信息
void PrintNode(List* Node,int model){
    if(model == 0){
        printf("Postion:%d\n",Node->Position);
    }
    printf("data:%d\n",Node->data);
}

/**
    *以下是链表的功能性文件，用于外部调用
    */

//创建一个长度为number的链表（不含头结点）
List* CreateList(int number){
    if(number <= 0){    //保证数据的正确
        printf("链表不能为空");
        return 0;
    }
    List* head = (List*)malloc(sizeof(List));        //创建头结点
    List* firstNode = creatNewNode();  //创建第一个结点
    int i;
    head->Position = number;//将链表长度写入头结点的数据中
    head->next = NULL;
    for(i = 1;i < number;i++){
        if(head->next == NULL){//将头结点与链表连接
            firstNode->Position = i;
            firstNode->next = NULL;
            head->next = firstNode;
        }
        List* tempNode = creatNewNode();//每次创建的结点
        tempNode->Position = i+1;
        tempNode->next = NULL;
        firstNode->next = tempNode;//将新结点与链表连接
        firstNode = firstNode->next;//工作指针后移
    }
    inputListData(head);//录入新结点的数据
    return head;//返回头结点
}

//打印所有链表的数据部分
void PrintList(List* head){
    List* workP;        //创建一个工作指针
    workP = head;    //将工作指针归至头结点
   while(workP->next != NULL){     //如果下一个节点是最后一个节点
        workP = workP->next;            //工作指针后移
        PrintNode(workP,0);               //输出结点信息
    }
    printf("\n");
}

//头插法插入number个结点
void HeadAddNode(List* head,int number){
    if(number <= 0){    //保证数据的正确
        printf("链表不能为空");
        return 0;
    }
    int i;
    List*workP;           //工作指针
    workP = head;      //将工作指针指向第一个结点
    for(i = 1;i <= number;i++){//将新建的结点插入链表头
        List* tempNode = creatNewNode();
        tempNode->Position = i;
        tempNode->next = head->next;
        head->next = tempNode;
    }
    head->Position += number;//链表长度更新
    List* tempNode;
    tempNode = head;
    for(i = 1;i <= head->Position;i++){
        tempNode = tempNode->next;
        tempNode->Position = i;
    }
    inputListData(head);//录入新结点的数据
}

//尾插法插入number个结点
void TailAddNode(List* head,int number){
    if(number <= 0){    //保证数据的正确
        printf("链表不能为空");
        return 0;
    }
    int i;
    List* workP;         //工作指针
    workP = head;     //将工作指针指向第一个结点
    for(i = 0;i <= head->Position-1;i++){//将工作指针移动到最后一个结点位置
        workP = workP->next;
    }
    for(i = 1;i <= number;i++){//建立新的节点在链表尾
        List* tempNode = creatNewNode();
        tempNode->Position = head->Position+i;
        tempNode->next = NULL;
        workP->next = tempNode;
        workP = workP->next;
    }
    head->Position += number;//链表长度更新
    inputListData(head);//录入新结点的数据
}

//查找某个位置的节点
int FindNodePosition(List* head,int aimPosition){
    if(aimPosition <= 0){    //保证数据的正确
        printf("链表位置不为空");
        return 0;
    }
    int i;
    List* workP;
    workP = head;
    for(i = 0;i < head->Position;i++){//遍历链表
        workP = workP->next;//工作指针后移
        if(workP->Position == aimPosition){//找到了
            PrintNode(workP,1);//打印结点信息
        }
    }

}

//删除某个位置上的结点
void deleteNode(List* head,int aimPosition){
    if(aimPosition <= 0 || aimPosition > head->Position){    //保证数据的正确
        if(aimPosition <= 0){
            printf("插入结点位置不能为负数\n");
        }else{
            printf("插入结点位置不能超过链表总长\n");
        }
        return 0;
    }
    int i;
    List* connectHeadP = head;//连接头指针
    List* connectTailP = head;//连接尾指针
    while(connectTailP->next != NULL){//循环遍历链表
        connectTailP = connectTailP->next;
        if(connectTailP->Position == aimPosition){//连接尾链表到达目标位置
            List* deleteNodeP = connectTailP;   //删除结点
            connectTailP = connectTailP->next;//后移一位
            connectHeadP->next = connectTailP;//连接链表
            deleteNodeP->next = NULL;   //释放内存
            free(deleteNodeP);
        }
        connectHeadP = connectHeadP->next;//工作指针后移
        if(connectTailP->Position > aimPosition){//将目标结点后的位置信息更新
            connectTailP->Position--;
        }
    }
    head->Position++;//遍历总体长度信息更新
}

//在某个结点位置上插入一个结点
void insertNode(List* head,int aimPosition){
    if(aimPosition <= 0 || aimPosition > head->Position){    //保证数据的正确
        if(aimPosition <= 0){
            printf("插入结点位置不能为负数\n");
        }else{
            printf("插入结点位置不能超过链表总长\n");
        }
        return 0;
    }
    int i;
    List* connectHeadP = head;//连接头指针
    List* connectTailP = head;//连接尾指针
    while(connectTailP->next != NULL){//循环遍历链表
        connectTailP = connectTailP->next;
        if(connectTailP->Position == aimPosition){//连接尾链表到达目标位置
            List* addNodeP = creatNewNode();   //添加结点
            addNodeP->Position = aimPosition;
            addNodeP->next = connectTailP;
            connectHeadP->next = addNodeP;//连接链表
        }
        connectHeadP = connectHeadP->next;//工作指针后移
        if(connectTailP->Position >= aimPosition){//将目标结点后的位置信息更新
            connectTailP->Position++;
        }
    }
    head->Position++;
    inputListData(head);
}

//清除链表
void ClearList(List* head){
    head->next = NULL;
}

//获得链表长度
int ListLength(List* head){
    return head->Position;
}





