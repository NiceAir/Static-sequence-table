#define _CRT_SECURE_NO_WARNINGS
#include "index.h"
int main()
{
    SeqList sq;
    SeqListInit(&sq);
    SeqListPushBack(&sq, 3);
    SeqListPushBack(&sq, 2);
    SeqListPushBack(&sq, 5);
    SeqListPushBack(&sq, 1);
//    SeqListPopBack(&sq);
    SeqListPushFront(&sq, 7);
    SeqListPushFront(&sq, 6);
//    SeqListPopFront(&sq);
    SeqListPushBack(&sq, 2);
    SeqListInsert(&sq, 3, 10);
//    SeqListErase(&sq, 3);
//    Remove(&sq, 7);
//   RemoveAll(&sq, 2);
//    BubbleSort(&sq);

    SelectSort(&sq);
    PrintSeqList(&sq);
    printf("The number of data is %d\n", SeqListSize(&sq));
    printf("Finding result is %d\n", SeqListFind(&sq, 10));
    return 0;
}