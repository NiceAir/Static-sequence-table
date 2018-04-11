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


void SeqListInit(PSeqList ps);  //顺序表的初始化
void SeqListPushBack(PSeqList ps, DataType data);   //顺序表的尾插
void SeqListPopBack(PSeqList ps);   //顺序表的尾删
void SeqListPushFront(PSeqList ps, DataType data);  //顺序表的头插
void SeqListPopFront(PSeqList ps);  //顺序表的头删
void SeqListInsert(PSeqList ps, int pos, DataType data);    //顺序表pos位置插入元素data
void SeqListErase(PSeqList ps, int pos);    //删除顺序表pos位置的元素
void Remove(PSeqList ps, DataType data);    //移除顺序表中第一个值为data的元素
void RemoveAll(PSeqList ps, DataType data); //移除顺序中所有值为data的元素
int SeqListFind(PSeqList ps, DataType data);    //在顺序表中查找值为data的元素，找到则返回该元素在顺序表中的位置，否则返回-1
int SeqListSize(PSeqList ps);   //获取顺序表中元素的个数
void PrintSeqList(PSeqList ps); //打印顺序表
void BubbleSort(PSeqList ps);   //使用冒泡排序对顺序表中的元素排序
void SelectSort(PSeqList ps);   //使用选择排序对顺序表中的元素排序