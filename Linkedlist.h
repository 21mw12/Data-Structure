#ifndef LISKEDLIST_H_INCLUDED
#define LISKEDLIST_H_INCLUDED

/**
   * ����ʵ�ֹ��ܣ�����
   * ʱ�䣺2021.11.25
   * ���ߣ�MW
   */

//ͷ����λ�����ݴ�ŵ���������
typedef struct List{
    int Position;   //���λ��
    int data;        //�������
    struct List* next;
}List;

#define dataNotVal -1   //data���ݲ���ȷ��һ����ֵ

List* CreateList(int number);//����һ������Ϊnumber����������ͷ��㣩
void PrintList(List* head);//��ӡ������������ݲ���
void ClearList(List* head);//�������
int ListLength(List* head);//���������
int FindNodePosition(List* head,int aimPosition);//����ĳ��λ�õĽڵ�
void HeadAddNode(List* head,int number);//ͷ�巨����number�����
void TailAddNode(List* head,int number);//β�巨����number�����
void deleteNode(List* head,int aimPosition);//ɾ��ĳ��λ���ϵĽ��
void insertNode(List* head,int aimPosition);//��ĳ�����λ���ϲ���һ�����

#endif // LISKED_LIST_H_INCLUDED
