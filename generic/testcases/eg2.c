#include<tm_sll.h>
#include<stdio.h>
#include<string.h>
typedef struct student{	
char name[21];
int rollNo;
char gender[10];
}std;
int main(){
bool success;
SinglyLinkedList *list ;
std s1,s2,s3,*s;
SinglyLinkedListIterator iter;
list = createSinglyLinkedList(&success);
strcpy(s1.name,"Vikas");
s1.rollNo=101;
strcpy(s1.gender,"Male");
addToSinglyLinkedList(list,(void *)&s1,&success);
if(success==false)
{
printf("Unable to add\n");
}
strcpy(s2.name,"Tanish");
s2.rollNo=102;
strcpy(s2.gender,"Male");
addToSinglyLinkedList(list,(void *)&s2,&success);
strcpy(s3.name,"Benny");
s3.rollNo=103;
strcpy(s3.gender,"Female");
addToSinglyLinkedList(list,(void *)&s3,&success);
printf("Traversing technique one\n");
for(int i=0;i<getSizeOfSinglyLinkedList(list);i++)
{
s=(std *)getFromSinglyLinkedList(list,i,&success);
printf("%s,%s,%d\n",s->name,s->gender,s->rollNo);
}
printf("Traversing technique two\n");
iter=getSinglyLinkedListIterator(list,&success);
if(success)
{
while(hasNextInSinglyLinkedList(&iter))
{
s=(std *)getNextElementFromSinglyLinkedList(&iter,&success);
printf("%s,%s,%d\n",s->name,s->gender,s->rollNo);
}
}
printf("Size of singly linked list is %d\n",getSizeOfSinglyLinkedList(list));
clearSinglyLinkedList(list);
destroySinglyLinkedList(list);
return 0;
}