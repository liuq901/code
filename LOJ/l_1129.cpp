#include <cstdio>
#include <cstring>
struct trie
{
    bool danger;
    int son[10];
};
trie a[100010];
int m;
void clear(int x)
{
    a[x].danger=false;
    memset(a[x].son,0,sizeof(a[x].son));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        clear(m=1);
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            char s[20];
            scanf("%s",s);
            int len=strlen(s),now=1;
            for (int j=0;j<len;j++)
            {
                int x=s[j]-'0';
                if (!a[now].son[x])
                {
                    clear(++m);
                    a[now].son[x]=m;
                }
                now=a[now].son[x];
            }
            a[now].danger=true;
        }
        bool flag=true;
        for (int i=1;i<=m;i++)
        {
            if (!a[i].danger)
                continue;
            for (int j=0;j<10;j++)
                if (a[i].son[j])
                {
                    flag=false;
                    break;
                }
            if (!flag)
                break;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,flag?"YES":"NO");
    }
    return(0);
}

