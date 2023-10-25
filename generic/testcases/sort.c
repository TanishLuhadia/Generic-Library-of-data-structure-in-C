#include<stdio.h>
#include<tm_sort.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student 
{
int rollNumber;
char name[21];
}std;
int StudentComparator(void *left,void *right)
{
std*s1,*s2;
s1=(std*)left;
s2=(std *)right;
return s1->rollNumber-s2->rollNumber;
}
int main()
{
int req;
std *s,*j;
int y;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
s=(std *)malloc(sizeof(std)*req);
j=s;
for(y=0;y<req;y++)
{
printf("Enter roll number : ");
scanf("%d",&(j->rollNumber));
printf("Enter name : ");
scanf("%s",j->name);
j++;
}
printf("Before sorting records are arranged as following\n");
for(y=0;y<req;y++)
{
printf("Roll number %d , Name %s\n",s[y].rollNumber,s[y].name);
}
// bubbleSort(s,req,sizeof(std),StudentComparator);
// linearSort(s,req,sizeof(std),StudentComparator);
// selectionSort(s,req,sizeof(std),StudentComparator);
// insertionSort(s,req,sizeof(std),StudentComparator);
// mergeSort(s,0,req-1,,sizeof(std),StudentComparator);
quickSort(s,0,req-1,sizeof(std),StudentComparator);
printf("After sorting records are arranged as following\n");
for(y=0;y<req;y++)
{
printf("Roll number %d , Name %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}