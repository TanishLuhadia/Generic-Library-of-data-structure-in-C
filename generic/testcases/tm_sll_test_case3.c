#include<tm_sll.h>
#include<stdio.h>
int main()
{
int i1,i2,i3,i4,i5,i6,y;
int *x;
bool succ;
SinglyLinkedList *list1;
list1=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("Unable to create list");
return 0;
}
printf("List created \n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
if(succ) printf("%d added to list1\n",i1);
else printf("unable to add %d to list1\n",i1);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
addToSinglyLinkedList(list1,(void *)&i2,&succ);
if(succ) printf("%d added to list1\n",i2);
else printf("unable to add %d to list1\n",i2);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
addToSinglyLinkedList(list1,(void *)&i3,&succ);
if(succ) printf("%d added to list1\n",i3);
else printf("unable to add %d to list1\n",i3);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
addToSinglyLinkedList(list1,(void *)&i4,&succ);
if(succ) printf("%d added to list1\n",i4);
else printf("unable to add %d to list1\n",i4);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
addToSinglyLinkedList(list1,(void *)&i5,&succ);
if(succ) printf("%d added to list1\n",i5);
else printf("unable to add %d to list1\n",i5);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
addToSinglyLinkedList(list1,(void *)&i6,&succ);
if(succ) printf("%d added to list1\n",i6);
else printf("unable to add %d to list1\n",i6);
printf("size of list1 is %d\n",getSizeOfSinglyLinkedList(list1));
printf("Contents of list1\n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int*) getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
insertIntoSinglyLinkedList(list1,0,(void *)&i4,&succ);
if(succ) printf("%d inserted inlist1 at index 0\n",i4);
insertIntoSinglyLinkedList(list1,2,(void *)&i5,&succ);
if(succ) printf("%d inserted inlist1 at index 2\n",i5);
printf("Contente of list1 after insertion\n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int*) getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
x=(void *)removeFromSinglyLinkedList(list1,3,&succ);
printf("%d removed from list1 \n",*x);
printf("Content of list1 after remove \n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int*) getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
printf("Clearing list\n");
clearSinglyLinkedList(list1);
printf("Destroying list \n");
destroySinglyLinkedList(list1);
return 0;
}