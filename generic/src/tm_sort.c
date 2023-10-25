#ifndef __TM_SORT_C
#define _TM_SORT_C123
#include <stdlib.h>
#include<string.h>
#include<tm_stack.h>
#include<tm_sort.h>
void bubbleSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}
void linearSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int e,f,oep,w,iep;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}
void selectionSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int e,f,oep,w,iep,si;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);
if(w<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
}
void insertionSort(void *x,int cs,int es,int(*p2f)(void *,void *))
{
int y,z,ep;
void *block;
ep=cs-1;
block=(void *)malloc(es);
y=1;
while(y<=ep)
{
memcpy(block,(const void *)(x+(y*es)),es);
z=y-1;
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}
int findPartitionPoint(void *x,int lb,int ub,int es, int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,(const void *)(x+(e*es)),es);
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
else
{
memcpy(g,(const void *)(x+(lb*es)),es);
memcpy(x+(lb*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
}
free(g);
return f;
}
void quickSort(void *x,int lowerBound,int upperBound,int es,int(*p2f)(void *,void *))
{
struct LBUB lbub;
bool success;
int lb,ub,pp;
Stack *stk=createStack(&success);
struct LBUB *l;
struct LBUB *p;
lbub.lb=lowerBound;
lbub.ub=upperBound;
pushOnStack(stk,(void *)&lbub,&success);
while(!isStackEmpty(stk))
{
l=(struct LBUB *)popFromStack(stk,&success);
lb=l->lb;
ub=l->ub;
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub)
{
p=(struct LBUB *)malloc(sizeof(struct LBUB));
p->lb=pp+1;
p->ub=ub;
pushOnStack(stk,(void *)p,&success);
}
if(lb<pp-1)
{
p=(struct LBUB *)malloc(sizeof(struct LBUB));
p->lb=lb;
p->ub=pp-1;
pushOnStack(stk,(void *)p,&success);
}
}
}
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3;
void *tmp;
int i1,i2,i3;
if(x==NULL || p2f==NULL) return;
if(es<=0) return;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(void *)malloc(es*size3);
if(tmp==NULL) return;
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(x+(i1*es),x+(i2*es))<0)
{
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
}
void mergeSort(void *x,int lowerBound,int upperBound,int es,int(*p2f)(void *,void *))
{
struct LBUB lbub;
int a,b;
bool success;
Stack *stack1,*stack2;
stack1=createStack(&success);
stack2=createStack(&success);
struct LBUB *s,*p;
int mid;
lbub.lb=lowerBound;
lbub.ub=upperBound;
pushOnStack(stack1,(void *)&lbub,&success);
while(!isStackEmpty(stack1))
{
s=(struct LBUB *)popFromStack(stack1,&success);
pushOnStack(stack2,(void *)s,&success);
a=s->lb;
b=s->ub;
mid=(a+b)/2;
if(a<mid)
{
p=(struct LBUB *)malloc(sizeof(struct LBUB));
p->lb=a;
p->ub=mid;
pushOnStack(stack1,(void *)p,&success);
}
if(mid+1<b)
{
p=(struct LBUB *)malloc(sizeof(struct LBUB));
p->lb=mid+1;
p->ub=b;
pushOnStack(stack1,(void *)p,&success);
}
}
while(!isStackEmpty(stack2))
{
s=(struct LBUB *)popFromStack(stack2,&success);
a=s->lb;
b=s->ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b);
}
}
#endif