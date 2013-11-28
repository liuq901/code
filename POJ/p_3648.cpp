#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tot,top,id,c[4010],dfn[4010],low[4010],st[4010],b[4010],a[1000000][2];
bool in[4010];
inline void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++id;
    st[++top]=x;
    in[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (st[top]!=x)
        {
            c[st[top]]=c[0];
            in[st[top--]]=false;
        }
        c[x]=c[0],in[x]=false;
        top--;
    }
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            char ch1,ch2;
            scanf("%d%c%d%c",&x,&ch1,&y,&ch2);
            x++,y++;
            if (ch1=='w')
                x+=2*n;
            if (ch2=='w')
                y+=2*n;
            add(x+n,y);
            add(y+n,x);
        }
        for (int i=1;i<=n;i++)
        {
            add(i,3*n+i);
            add(2*n+i,n+i);
            add(3*n+i,i);
            add(n+i,2*n+i);
        }
        add(1,2*n+1);
        add(3*n+1,n+1);
        memset(dfn,0,sizeof(dfn));
        top=id=c[0]=0;
        for (int i=1;i<=4*n;i++)
            if (!dfn[i])
                tarjan(i);
        bool flag=true;
        for (int i=1;i<=n;i++)
            if (c[i]==c[i+n])
            {
                flag=false;
                break;
            }
        for (int i=2*n+1;i<=3*n;i++)
            if (c[i]==c[i+n])
            {
                flag=false;
                break;
            }
        if (!flag)
            printf("bad luck\n");
        else
        {
            bool first=true;
            if (c[2*n+1]<c[3*n+1])
            {
                for (int i=1;i<=n;i++)
                    swap(c[i],c[i+n]);
                for (int i=2*n+1;i<=3*n;i++)
                    swap(c[i],c[i+n]);
            }
            for (int i=1;i<=n;i++)
                if (c[i]>c[i+n])
                {
                    if (!first)
                        printf(" ");
                    first=false;
                    printf("%dh",i-1);
                }
            for (int i=2*n+2;i<=3*n;i++)
                if (c[i]>c[i+n])
                {
                    if (!first)
                        printf(" ");
                    first=false;
                    printf("%dw",i-2*n-1);
                }
            printf("\n");
        }
    }
    return(0);
}

