#include <cstdio>
#include <cstring>
struct trie
{
    int danger,son[10];
};
trie a[18010];
int idx,m,len,ans;
char s[100000];
void clear(int x)
{
    a[x].danger=0;
    memset(a[x].son,0,sizeof(a[x].son));
}
int vis[1510],f[18010][11][4];
void dfs(int x,int l,int cnt)
{
    if (f[x][l][cnt]==idx)
        return;
    f[x][l][cnt]=idx;
    if (a[x].danger && l==len && vis[a[x].danger]!=idx)
    {
        ans++;
        vis[a[x].danger]=idx;
    }
    if (l==len && cnt==0)
        return;
    for (int i=0;i<10;i++)
    {
        if (!a[x].son[i])
            continue;
        if (l!=len)
        {
            if (i==s[l]-'0')
                dfs(a[x].son[i],l+1,cnt);
            if (cnt && i!=s[l]-'0')
                dfs(a[x].son[i],l+1,cnt-1);
        }
        if (cnt)
            dfs(a[x].son[i],l,cnt-1);
    }
    if (cnt && l!=len)
        dfs(x,l+1,cnt-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        clear(m=1);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            len=strlen(s);
            if (len>12)
            {
                n--,i--;
                continue;
            }
            int now=1;
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
            a[now].danger=i;
        }
        static int id=0;
        printf("Case #%d:\n",++id);
        while (Q--)
        {
            int x;
            scanf("%s%d",s,&x);
            len=strlen(s);
            idx++;
            ans=0;
            dfs(1,0,x);
            printf("%d\n",ans);
        }
    }
    return(0);
}

