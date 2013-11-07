#include <cstdio>
int a[80010],b[80010];
char op[10];
int main()
{
    int n;
    scanf("%d",&n);
    a[0]=-1;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",op);
        int K;
        if (op[0]!='s')
            scanf("%d",&K);
        if (op[0]=='a')
        {
            a[i]=K;
            b[i]=i-1;
        }
        else if (op[0]=='s')
        {
            a[i]=a[b[i-1]];
            b[i]=b[b[i-1]];
        }
        else
        {
            a[i]=a[K-1];
            b[i]=b[K-1];
        }
        printf("%d\n",a[i]);
    }
    return(0);
}

