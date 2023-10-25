#include<tm_sll.h>
#include<stdio.h>
int main()
{
int i1,i2,i3,i4,i5,i6,y,i11,i22,i33,i44,i55,i66;
int *x;
bool succ;
SinglyLinkedList *list1,*list2;
list1=createSinglyLinkedList(&succ);
list2=createSinglyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
addToSinglyLinkedList(list1,(void *)&i2,&succ);
addToSinglyLinkedList(list1,(void *)&i3,&succ);
addToSinglyLinkedList(list1,(void *)&i4,&succ);
addToSinglyLinkedList(list1,(void *)&i5,&succ);
addToSinglyLinkedList(list1,(void *)&i6,&succ);
printf("Contents of list1\n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int*) getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}

i11=700;
i22=800;
i33=900;
i44=1000;
i55=1100;
i66=1200;
addToSinglyLinkedList(list2,(void *)&i11,&succ);
addToSinglyLinkedList(list2,(void *)&i22,&succ);
addToSinglyLinkedList(list2,(void *)&i33,&succ);
addToSinglyLinkedList(list2,(void *)&i44,&succ);
addToSinglyLinkedList(list2,(void *)&i55,&succ);
addToSinglyLinkedList(list2,(void *)&i66,&succ);
printf("Contents of list2\n");
for(y=0;y<getSizeOfSinglyLinkedList(list2);y++)
{
x=(int*) getFromSinglyLinkedList(list2,y,&succ);
printf("%d\n",*x);
}
appendToSinglyLinkedList(list1,list2,&succ);
if(succ) printf("Appended\n");
else printf("Unable to append\n");
printf("Contents of list after append\n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int*) getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
printf("Clearing list\n");
clearSinglyLinkedList(list1);
clearSinglyLinkedList(list2);
printf("Destroying list \n");
destroySinglyLinkedList(list1);
destroySinglyLinkedList(list2);
return 0;
}