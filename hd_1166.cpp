#include <cstdio>
#include <cstring>
int n,c[50010];
void add(int x,int y)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=y;
}
int find(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            add(i,x);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        while (1)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='E')
                break;
            int x,y;
            scanf("%d%d",&x,&y);
            if (op[0]=='A')
                add(x,y);
            else if (op[0]=='S')
                add(x,-y);
            else
                printf("%d\n",find(y)-find(x-1));
        }
    }
    return(0);
}

