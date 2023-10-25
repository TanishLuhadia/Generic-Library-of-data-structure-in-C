#ifndef __TM_SORT__H
#define __TM_SORT__H 123
struct LBUB
{
int lb,ub;
};
void bubbleSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
void linearSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
void selectionSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
void insertionSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
void quickSort(void *x,int lowerBound,int upperBound,int es,int(*p2f)(void *,void *));
void mergeSort(void *x,int lowerBound,int upperBound,int es,int(*p2f)(void *,void *));
#endif