#include <cstdio>
#include <algorithm>
using namespace std;
struct trie
{
    int son[2];
};
trie a[1600000];
int m,s[50010];
void clear(int x)
{
    a[x].son[0]=a[x].son[1]=0;
}
void insert(int n)
{
    int b[40];
    for (int i=0;i<=30;i++)
    {
        b[i]=n&1;
        n>>=1;
    }
    int now=1;
    for (int i=30;i>=0;i--)
    {
        int x=b[i];
        if (!a[now].son[x])
        {
            clear(++m);
            a[now].son[x]=m;
        }
        now=a[now].son[x];
    }
}
int Min(int n)
{
    int b[40];
    for (int i=0;i<=30;i++)
    {
        b[i]=n&1;
        n>>=1;
    }
    int now=1,ret=0;
    for (int i=30;i>=0;i--)
    {
        int x=b[i];
        if (!a[now].son[x])
            x^=1;
        ret=ret<<1|x^b[i];
        now=a[now].son[x];
    }
    return(ret);
}
int Max(int n)
{
    int b[40];
    for (int i=0;i<=30;i++)
    {
        b[i]=n&1;
        n>>=1;
    }
    int now=1,ret=0;
    for (int i=30;i>=0;i--)
    {
        int x=b[i]^1;
        if (!a[now].son[x])
            x^=1;
        ret=ret<<1|x^b[i];
        now=a[now].son[x];
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s[i]=s[i-1]^x;
        }
        clear(m=1);
        insert(0);
        int mi=2147483647,ma=-1;
        for (int i=1;i<=n;i++)
        {
            mi=min(mi,Min(s[i]));
            ma=max(ma,Max(s[i]));
            insert(s[i]);
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,ma,mi);
    }
    return(0);
}

