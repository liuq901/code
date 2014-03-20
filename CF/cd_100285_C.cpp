#include <cstdio>
struct stack
{
    int knowledge;
    stack *next;
    stack(){}
    stack(int k,stack *n):knowledge(k),next(n){}
};
stack *a[500010],*b[500010];
int n=1;
void learn(int x,int y)
{
    a[x]=new(stack)(y,a[x]);
    b[x]=NULL;
}
void rollback(int x)
{
    b[x]=new(stack)(a[x]->knowledge,b[x]);
    a[x]=a[x]->next;
}
void relearn(int x)
{
    a[x]=new(stack)(b[x]->knowledge,a[x]);
    b[x]=b[x]->next;
}
void clone(int x)
{
    a[++n]=a[x];
    b[n]=b[x];
}
void check(int x)
{
    if (a[x]->knowledge==-1)
        printf("basic\n");
    else
        printf("%d\n",a[x]->knowledge);
}
int main()
{
    int Q;
    scanf("%d%*d",&Q);
    a[1]=new(stack)(-1,NULL);
    b[1]=NULL;
    while (Q--)
    {
        char op[10];
        int x;
        scanf("%s%d",op,&x);
        if (op[0]=='l')
        {
            int y;
            scanf("%d",&y);
            learn(x,y);
        }
        else if (op[1]=='o')
            rollback(x);
        else if (op[1]=='e')
            relearn(x);
        else if (op[1]=='l')
            clone(x);
        else
            check(x);
    }
    return(0);
}

