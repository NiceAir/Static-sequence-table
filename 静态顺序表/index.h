#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma once

#define MAX_SIZE 10
typedef int DataType;
typedef struct SeqList
{
    int _size;
    DataType _arry[MAX_SIZE];
}; 
typedef struct SeqList SeqList;
typedef struct SeqList *PSeqList;


void SeqListInit(PSeqList ps);  //˳���ĳ�ʼ��
void SeqListPushBack(PSeqList ps, DataType data);   //˳����β��
void SeqListPopBack(PSeqList ps);   //˳����βɾ
void SeqListPushFront(PSeqList ps, DataType data);  //˳����ͷ��
void SeqListPopFront(PSeqList ps);  //˳����ͷɾ
void SeqListInsert(PSeqList ps, int pos, DataType data);    //˳���posλ�ò���Ԫ��data
void SeqListErase(PSeqList ps, int pos);    //ɾ��˳���posλ�õ�Ԫ��
void Remove(PSeqList ps, DataType data);    //�Ƴ�˳����е�һ��ֵΪdata��Ԫ��
void RemoveAll(PSeqList ps, DataType data); //�Ƴ�˳��������ֵΪdata��Ԫ��
int SeqListFind(PSeqList ps, DataType data);    //��˳����в���ֵΪdata��Ԫ�أ��ҵ��򷵻ظ�Ԫ����˳����е�λ�ã����򷵻�-1
int SeqListSize(PSeqList ps);   //��ȡ˳�����Ԫ�صĸ���
void PrintSeqList(PSeqList ps); //��ӡ˳���
void BubbleSort(PSeqList ps);   //ʹ��ð�������˳����е�Ԫ������
void SelectSort(PSeqList ps);   //ʹ��ѡ�������˳����е�Ԫ������