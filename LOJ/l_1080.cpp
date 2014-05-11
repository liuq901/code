#include <cstdio>
#include <cstring>
int n,c[100010];
void modify(int x)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]^=1;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret^=c[i];
    return(ret);
}
char s[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        memset(c,0,sizeof(c));
        n=strlen(s+1);
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='I')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                modify(x);
                modify(y+1);
            }
            else
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",query(x)^s[x]-'0');
            }
        }
    }
    return(0);
}

