#include<tm_queue.h>
#include<stdio.h>
int main()
{
int succ;
int X1,X2,X3,X4;
int *x;
X1=10;
X2=20;
X3=30;
X4=40;
Queue *queue;
queue=createQueue(&succ);
if(queue==false)
{
printf("unable to create queue \n"); return 0;
}
addToQueue(queue,&X1,&succ);
if(succ) printf("%d added to queue \n", X1);
else printf("unable to add %d to queue \n" ,X1);

addToQueue(queue,&X2,&succ);
if(succ) printf("%d added to queue \n", X2);
else printf("unable to add %d to queue \n" ,X2);

addToQueue(queue,&X3,&succ);
if(succ) printf("%d added to queue \n", X3);
else printf("unable to add %d to queue \n" ,X3);

addToQueue(queue,&X4,&succ);
if(succ) printf("%d added to queue \n", X4);
else printf("unable to add %d to queue \n" ,X4);

printf("size of queue %d \n ",getSizeOfQueue(queue));
if(isQueueEmpty(queue)) printf("Queue is empty \n");
else printf("Queue is not empty \n");
x=(int *)elementAtFrontOfQueue(queue,&succ);
printf("Element at front of queue is %d \n", *x);
printf("Now removing all element from queue \n");
while(!isQueueEmpty(queue))
{
x=(int*)removeFromQueue(queue,&succ);
printf("%d removed from queue \n ",*x);
}
destroyQueue(queue);
return 0;
}