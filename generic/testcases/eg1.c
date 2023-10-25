#include<tm_sll.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int req;
SinglyLinkedList *list;
bool success;
char *s;
char *g;
list=createSinglyLinkedList(&success);
printf("Enter your requirement : ");
scanf("%d",&req);
fflush(stdin);
for(int i=0;i<req;i++)
{
printf("Enter character to add to list : ");
g=(char *)malloc(sizeof(char));
scanf("%c",&g);
fflush(stdin);
addToSinglyLinkedList(list,(void *)g,&success);
}


for(int i=0;i<getSizeOfSinglyLinkedList(list);i++)
{
s=(char *)getFromSinglyLinkedList(list,i,&success);
printf("%c\n",s);
}
return 0;
}