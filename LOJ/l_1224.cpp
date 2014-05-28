#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct trie
{
    int dep,sum,son[4];
};
trie a[2500010];
int m;
void clear(int x)
{
    a[x].dep=a[x].sum=0;
    memset(a[x].son,0,sizeof(a[x].son));
}
int get(char ch)
{
    if (ch=='A')
        return(0);
    else if (ch=='G')
        return(1);
    else if (ch=='C')
        return(2);
    else
        return(3);
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
            char s[60];
            scanf("%s",s);
            int len=strlen(s),now=1;
            for (int j=0;j<len;j++)
            {
                int x=get(s[j]);
                if (!a[now].son[x])
                {
                    clear(++m);
                    a[now].son[x]=m;
                }
                now=a[now].son[x];
                a[now].sum++;
                a[now].dep=j+1;
            }
        }
        int ans=0;
        for (int i=2;i<=m;i++)
            ans=max(ans,a[i].dep*a[i].sum);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

