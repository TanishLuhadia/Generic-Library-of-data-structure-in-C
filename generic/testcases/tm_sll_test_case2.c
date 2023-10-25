#include<tm_sll.h>
#include<stdio.h>
int main()
{
bool succ;
SinglyLinkedList *list1;
list1=createSinglyLinkedList(&succ);
if(succ==false)
{
printf("unable to create list");
return 0;
}
printf("List created\n");
printf("Clearing List \n");
clearSinglyLinkedList(list1);
printf("Destroying list\n");
destroySinglyLinkedList(list1);
return 0;
}