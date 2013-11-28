#include <cstdio>
#include <cstring>
struct trie
{
    int value,father,suffix,son[10];
    bool danger;
};
trie a[110];
void clear(int x)
{
    a[x].suffix=0;
    a[x].danger=false;
    memset(a[x].son,0,sizeof(a[x].son));
}
int m;
void insert(char *s)
{
    int len=strlen(s),now=1;
    for (int i=0;i<len;i++)
    {
        int x=s[i]-'0';
        if (a[now].son[x]==0)
        {
            clear(++m);
            a[now].son[x]=m;
            a[m].value=x;
            a[m].father=now;
        }
        now=a[now].son[x];
    }
    a[now].danger=true;
}
int child(int x,int value)
{
    if (!a[x].son[value])
    {
        if (x==1)
            return(1);
        a[x].son[value]=child(a[x].suffix,value);
    }
    return(a[x].son[value]);
}
int q[110];
void build()
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=0;i<10;i++)
            if (a[x].son[i])
                q[++r]=a[x].son[i];
    }
    for (int i=1;i<=m;i++)
    {
        int x=q[i];
        if (x==1 || a[x].father==1)
            a[x].suffix=1;
        else
            a[x].suffix=child(a[a[x].father].suffix,a[x].value);
        a[x].danger|=a[a[x].suffix].danger;
    }
}
int f[110][20];
int dp(int x,int m)
{
    if (f[x][m]!=-1)
        return(f[x][m]);
    int &ret=f[x][m];
    if (a[x].danger)
        return(ret=0);
    if (m==0)
        return(ret=1);
    ret=0;
    for (int i=0;i<10;i++)
        ret+=dp(child(x,i),m-1);
    return(ret);
}
int print(int x,int m,int limit,int ans)
{
    if (m==0)
        return(ans);
    for (int i=0;i<10;i++)
    {
        int now=dp(child(x,i),m-1);
        if (now<limit)
            limit-=now;
        else
            return(print(child(x,i),m-1,limit,ans*10+i));
    }
}
int ans(int x)
{
    for (int i=0;;i++)
    {
        memset(f,-1,sizeof(f));
        for (int j=1;j<=9;j++)
        {
            int now=dp(child(1,j),i);
            if (now<x)
                x-=now;
            else
                return(print(child(1,j),i,x,j));
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        clear(m=1);
        for (int i=1;i<=n;i++)
        {
            char buf[20];
            scanf("%s",buf);
            insert(buf);
        }
        build();
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            printf("%d%c",ans(x),i==n?'\n':' ');
        }
    }
    return(0);
}

