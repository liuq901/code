#include <cstdio>
#include <cstring>
#include <cctype>
const int N=100010;
const char C[]="CDHS";
int m,a[N],value[N],son[N],next[N];
inline void clear(int x)
{
    son[x]=next[x]=0;
}
int get(char *s)
{
    int n=strlen(s),value;
    char suit;
    if (n==3)
    {
        suit=s[2];
        value=10;
    }
    else
    {
        suit=s[1];
        if (isdigit(s[0]))
            value=s[0]-'0';
        else if (s[0]=='A')
            value=1;
        else if (s[0]=='J')
            value=11;
        else if (s[0]=='Q')
            value=12;
        else if (s[0]=='K')
            value=13;
    }
    for (int i=0;i<4;i++)
        if (suit==C[i])
            return(i*100+value);
}
int insert(int x,int v)
{
    for (int i=son[x];i;i=next[i])
        if (value[i]==v)
            return(i);
    clear(++m);
    value[m]=v;
    if (!son[x])
        son[x]=m;
    else
    {
        int p=son[x];
        while (next[p])
            p=next[p];
        next[p]=m;
    }
    return(m);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        clear(m=1);
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=1;j<=K;j++)
            {
                char buf[10];
                scanf("%s",buf);
                a[K-j+1]=get(buf);
            }
            int x=1;
            for (int j=1;j<=K;j++)
                x=insert(x,a[j]);
        }
        printf("%d\n",m-1);
    }
    return(0);
}

