#include<tm_stack.h>
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
Stack *stack;
stack=createStack(&succ);
if(stack==false)
{
printf("unable to create stack \n"); return 0;
}
pushOnStack(stack,&X1,&succ);
if(succ) printf("%d pushed to stack \n", X1);
else printf("unable to push %d to stack \n" ,X1);

pushOnStack(stack,&X2,&succ);
if(succ) printf("%d pushed to stack \n", X2);
else printf("unable to push %d to stack \n" ,X2);

pushOnStack(stack,&X3,&succ);
if(succ) printf("%d pushed to stack \n", X3);
else printf("unable to push %d to stack \n" ,X3);

pushOnStack(stack,&X4,&succ);
if(succ) printf("%d pushed to stack \n", X4);
else printf("unable to push %d to stack \n" ,X4);

printf("size of stack %d \n ",getSizeOfStack(stack));
if(isStackEmpty(stack)) printf("Stack is empty \n");
else printf("Stack is not empty \n");
x=(int *)elementAtTopOfStack(stack,&succ);
printf("Element at top of stack is %d \n", *x);
printf("Now removing all element from stack \n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d popped from stack \n ",*x);
}
destroyStack(stack);
return 0;
}