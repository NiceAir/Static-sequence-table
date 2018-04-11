#define _CRT_SECURE_NO_WARNINGS
#include "index.h"   



//˳���ĳ�ʼ��
void SeqListInit(PSeqList ps)
{
    ps->_size = 0;
}

//˳����β��
void SeqListPushBack(PSeqList ps, DataType data)
{
    if (ps->_size >= MAX_SIZE)
    {
        printf("Push failed, the SeqList is already full\n");
        return;
    }
    ps->_arry[ps->_size] = data;
    ps->_size++;
}

//˳����βɾ
void SeqListPopBack(PSeqList ps)
{
    if (ps->_size <= 0)
    {
        printf("Pop failed, the SeqList is empty, so can not pop_back\n");
        return;
    }
    --(ps->_size);
}

//˳����ͷ��
void SeqListPushFront(PSeqList ps, DataType data)
{
    int i = 0;
    if (ps->_size >= MAX_SIZE)
    {
        printf("Push failed, the SeqList is already full\n");
        return;
    }
    for (i = ps->_size-1; i>=0; i--)
    {
        ps->_arry[i+1] = ps->_arry[i];
    }
    ps->_arry[0] = data;
    ps->_size++;
}

//˳����ͷɾ 
void SeqListPopFront(PSeqList ps)
{
    int i = 0;
    if (ps->_size <= 0)
    {
        printf("Pop failed, the SeqList is empty, so can not pop_back\n");
        return;
    }
    for (i = 0; i < ps->_size-1; i++)
    {
        ps->_arry[i] = ps->_arry[i+1];
    }
    --(ps->_size);
}

//˳���posλ�ò���Ԫ��data��pos�ķ�ΧΪ0��_size
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
    int i = 0;
    if (ps->_size >= MAX_SIZE)
    {
        printf("Insert failed, the SeqList is already full\n");
        return;
    }
    if (pos<0 || pos > ps->_size)
    {
        printf("Insert failed, the position of inserting is illegal\n");
        return;
    }
    for (i = ps->_size-1; i>=pos; i--)
    {
        ps->_arry[i+1] = ps->_arry[i];
    }
    ps->_arry[pos] = data;
    ps->_size++;

}

//ɾ��˳���posλ�õ�Ԫ��
void SeqListErase(PSeqList ps, int pos)
{
    int i = 0;
    if (ps->_size <=0)
    {
        printf("Erase failed, the SeqList is empty\n");
        return;
    }
    if (pos<0 || pos >= ps->_size)
    {
        printf("Erase failed, the position of erasing is illegal\n");
        return;
    }
    for (i = pos; i < ps->_size-1; i++)
    {
        ps->_arry[i] = ps->_arry[i+1];
    }
    --(ps->_size);
}

//�Ƴ�˳����е�һ��ֵΪdata��Ԫ��
void Remove(PSeqList ps, DataType data)
{
    int postion = 0;
    int sign = 0;
    if(ps->_size <=0)
    {
        printf("Remove failed, the SeqList is empty\n");
        return;
    }
    for (postion = 0; postion<ps->_size; postion++)
    {
        if (ps->_arry[postion] == data)
        {
            sign = 1;
            break;
        }
    }
    if (sign != 1)
    {
        printf("Sorry, can not find the data\n");
        return;
    }
    SeqListErase(ps, postion);
}

//�Ƴ�˳��������ֵΪdata��Ԫ��
void RemoveAll(PSeqList ps, DataType data)
{
    SeqList p;
    int i = 0;
    p._size = 0;
    if(ps->_size <=0)
    {
        printf("Remove failed, the SeqList is empty\n");
        return;
    }
    for (i = 0; i < ps->_size; i++)
    {
        if (ps->_arry[i] != data)
        {
            p._arry[p._size] = ps->_arry[i];
            p._size++;
        }
    }
    if (p._size == ps->_size)
    {
        printf("Sorry, can not find the data\n");
        return;
    }
    for(i = 0; i < p._size; i++)
    {
        ps->_arry[i] = p._arry[i];
    }
    ps->_size = p._size;
}

//��˳����в���ֵΪdata��Ԫ�أ��ҵ��򷵻ظ�Ԫ����˳����е�λ�ã����򷵻�-1
int SeqListFind(PSeqList ps, DataType data)
{
    int position = 0;
    for(position = 0; position < ps->_size; position++)
    {
        if (ps->_arry[position] == data)
        {
            return position;
        }
    }
    return -1;
}

//��ȡ˳�����Ԫ�صĸ���
int SeqListSize(PSeqList ps)
{
    return ps->_size;
}

//��ӡ˳���
void PrintSeqList(PSeqList ps)
{
    int i = 0;
    for (i = 0; i < ps->_size; i++)
    {
        printf("%d--->%d\n", i+1, ps->_arry[i]);
    }
}

//ʹ��ð�������˳����е�Ԫ������
void BubbleSort(PSeqList ps)
{
    int i = 0; 
    int j = 0;
    for(i = 0; i < ps->_size-1; i++)
    {
        int sign = 0;
        for (j = 0; j< ps->_size-i-1; j++)
        {
            if (ps->_arry[j] > ps->_arry[j+1])
            {
                sign = 1;
                ps->_arry[j] ^= ps->_arry[j+1];
                ps->_arry[j+1] ^= ps->_arry[j];
                ps->_arry[j] ^= ps->_arry[j+1];
            }
        }
        if (sign == 0)
        {
            break;
        }
    }
}

//ʹ��ѡ�������˳����е�Ԫ������
void SelectSort(PSeqList ps)
{
    int i = 0;
    int j = 0;
    int max_data = 0;
    for (i = 0; i < ps->_size-1; i++)
    {
        max_data = 0;
        for (j = 0; j < ps->_size-i-1; j++)
        {
            if (ps->_arry[j] > ps->_arry[max_data])
            {
                max_data = j;
            }
        }
        ps->_arry[max_data] ^= ps->_arry[ps->_size-i-1];
        ps->_arry[ps->_size-i-1] ^= ps->_arry[max_data];
        ps->_arry[max_data] ^= ps->_arry[ps->_size-i-1];
    }
}