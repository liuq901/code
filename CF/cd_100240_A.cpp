#include <cstdio>
#include <cstring>
struct trie
{
    bool end,flag;
    int a[10];
    void clear()
    {
        end=flag=false;
        memset(a,0,sizeof(a));
    }
};
trie a[100010];
char s[100010];
int m;
int next(int x,char ch)
{
    int p=ch-'0';
    if (!a[x].a[p])
    {
        a[++m].clear();
        a[x].a[p]=m;
        a[x].flag=true;
    }
    return(a[x].a[p]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        a[m=1].clear();
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            int len=strlen(s),now=1;
            for (int j=0;j<len;j++)
                now=next(now,s[j]);
            a[now].end=true;
        }
        bool flag=true;
        for (int i=1;i<=m;i++)
            if (a[i].end && a[i].flag)
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

