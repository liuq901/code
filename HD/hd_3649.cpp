#include <cstdio>
int a[10],b[10];
int win(int first)
{
    if (a[1]+1==b[1])
        return(first);
    int sg=(b[1]-a[1])%2^b[2]-a[2]-1^b[3]-a[3]-1;
    return(sg?first:first^1);
}
int main()
{
    int first;
    while (scanf("%d",&first)==1)
    {
        for (int i=1;i<=4;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=4;i++)
            scanf("%d",&b[i]);
        printf("%s\n",win(first)?"Black":"Red");
    }
    return(0);
}

