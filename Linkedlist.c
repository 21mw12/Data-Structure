#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

/**
    *����Ϊ�ļ��ڵ��õĹ����ļ��������ⲿ����ʹ��
    */
List*  creatNewNode();

//�½�һ����㣬�������ֵ
List*  creatNewNode(){
    List* tempNode;
    tempNode = (List*)malloc(sizeof(List));
    tempNode->Position = -1;
    tempNode->data = dataNotVal;
    tempNode->next = NULL;
    return tempNode;
}

//��û�����ݵĽ��¼������
void inputListData(List* head){
    int i;
    List* workP = head;    //����ָ��
    while(workP->next != NULL){
        workP = workP->next;
        if(workP->data == dataNotVal){//�������Ϊ�ղ�¼������
            printf("�������%dλ�����ݣ�",workP->Position);
            scanf("%d",&workP->data);
        }
    }
}

//��ӡ����������Ϣ
//modelΪ0ʱ��ӡ������Ϣ��Ϊ1ʱֵ��ӡ���ݲ���û�н��λ����Ϣ
void PrintNode(List* Node,int model){
    if(model == 0){
        printf("Postion:%d\n",Node->Position);
    }
    printf("data:%d\n",Node->data);
}

/**
    *����������Ĺ������ļ��������ⲿ����
    */

//����һ������Ϊnumber����������ͷ��㣩
List* CreateList(int number){
    if(number <= 0){    //��֤���ݵ���ȷ
        printf("������Ϊ��");
        return 0;
    }
    List* head = (List*)malloc(sizeof(List));        //����ͷ���
    List* firstNode = creatNewNode();  //������һ�����
    int i;
    head->Position = number;//��������д��ͷ����������
    head->next = NULL;
    for(i = 1;i < number;i++){
        if(head->next == NULL){//��ͷ�������������
            firstNode->Position = i;
            firstNode->next = NULL;
            head->next = firstNode;
        }
        List* tempNode = creatNewNode();//ÿ�δ����Ľ��
        tempNode->Position = i+1;
        tempNode->next = NULL;
        firstNode->next = tempNode;//���½������������
        firstNode = firstNode->next;//����ָ�����
    }
    inputListData(head);//¼���½�������
    return head;//����ͷ���
}

//��ӡ������������ݲ���
void PrintList(List* head){
    List* workP;        //����һ������ָ��
    workP = head;    //������ָ�����ͷ���
   while(workP->next != NULL){     //�����һ���ڵ������һ���ڵ�
        workP = workP->next;            //����ָ�����
        PrintNode(workP,0);               //��������Ϣ
    }
    printf("\n");
}

//ͷ�巨����number�����
void HeadAddNode(List* head,int number){
    if(number <= 0){    //��֤���ݵ���ȷ
        printf("������Ϊ��");
        return 0;
    }
    int i;
    List*workP;           //����ָ��
    workP = head;      //������ָ��ָ���һ�����
    for(i = 1;i <= number;i++){//���½��Ľ���������ͷ
        List* tempNode = creatNewNode();
        tempNode->Position = i;
        tempNode->next = head->next;
        head->next = tempNode;
    }
    head->Position += number;//�����ȸ���
    List* tempNode;
    tempNode = head;
    for(i = 1;i <= head->Position;i++){
        tempNode = tempNode->next;
        tempNode->Position = i;
    }
    inputListData(head);//¼���½�������
}

//β�巨����number�����
void TailAddNode(List* head,int number){
    if(number <= 0){    //��֤���ݵ���ȷ
        printf("������Ϊ��");
        return 0;
    }
    int i;
    List* workP;         //����ָ��
    workP = head;     //������ָ��ָ���һ�����
    for(i = 0;i <= head->Position-1;i++){//������ָ���ƶ������һ�����λ��
        workP = workP->next;
    }
    for(i = 1;i <= number;i++){//�����µĽڵ�������β
        List* tempNode = creatNewNode();
        tempNode->Position = head->Position+i;
        tempNode->next = NULL;
        workP->next = tempNode;
        workP = workP->next;
    }
    head->Position += number;//�����ȸ���
    inputListData(head);//¼���½�������
}

//����ĳ��λ�õĽڵ�
int FindNodePosition(List* head,int aimPosition){
    if(aimPosition <= 0){    //��֤���ݵ���ȷ
        printf("����λ�ò�Ϊ��");
        return 0;
    }
    int i;
    List* workP;
    workP = head;
    for(i = 0;i < head->Position;i++){//��������
        workP = workP->next;//����ָ�����
        if(workP->Position == aimPosition){//�ҵ���
            PrintNode(workP,1);//��ӡ�����Ϣ
        }
    }

}

//ɾ��ĳ��λ���ϵĽ��
void deleteNode(List* head,int aimPosition){
    if(aimPosition <= 0 || aimPosition > head->Position){    //��֤���ݵ���ȷ
        if(aimPosition <= 0){
            printf("������λ�ò���Ϊ����\n");
        }else{
            printf("������λ�ò��ܳ��������ܳ�\n");
        }
        return 0;
    }
    int i;
    List* connectHeadP = head;//����ͷָ��
    List* connectTailP = head;//����βָ��
    while(connectTailP->next != NULL){//ѭ����������
        connectTailP = connectTailP->next;
        if(connectTailP->Position == aimPosition){//����β������Ŀ��λ��
            List* deleteNodeP = connectTailP;   //ɾ�����
            connectTailP = connectTailP->next;//����һλ
            connectHeadP->next = connectTailP;//��������
            deleteNodeP->next = NULL;   //�ͷ��ڴ�
            free(deleteNodeP);
        }
        connectHeadP = connectHeadP->next;//����ָ�����
        if(connectTailP->Position > aimPosition){//��Ŀ������λ����Ϣ����
            connectTailP->Position--;
        }
    }
    head->Position++;//�������峤����Ϣ����
}

//��ĳ�����λ���ϲ���һ�����
void insertNode(List* head,int aimPosition){
    if(aimPosition <= 0 || aimPosition > head->Position){    //��֤���ݵ���ȷ
        if(aimPosition <= 0){
            printf("������λ�ò���Ϊ����\n");
        }else{
            printf("������λ�ò��ܳ��������ܳ�\n");
        }
        return 0;
    }
    int i;
    List* connectHeadP = head;//����ͷָ��
    List* connectTailP = head;//����βָ��
    while(connectTailP->next != NULL){//ѭ����������
        connectTailP = connectTailP->next;
        if(connectTailP->Position == aimPosition){//����β������Ŀ��λ��
            List* addNodeP = creatNewNode();   //��ӽ��
            addNodeP->Position = aimPosition;
            addNodeP->next = connectTailP;
            connectHeadP->next = addNodeP;//��������
        }
        connectHeadP = connectHeadP->next;//����ָ�����
        if(connectTailP->Position >= aimPosition){//��Ŀ������λ����Ϣ����
            connectTailP->Position++;
        }
    }
    head->Position++;
    inputListData(head);
}

//�������
void ClearList(List* head){
    head->next = NULL;
}

//���������
int ListLength(List* head){
    return head->Position;
}





