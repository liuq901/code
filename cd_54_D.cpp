#include <cstdio>
#include <cstring>
struct trie
{
    bool danger;
    int suffix,father;
    char ch,son;
};
trie a[110];
char s[110],t[110];
bool vis[110][110],f[110][110];
int m,n,K,pre[110][110],p[110][110];
int child(int x,char ch)
{
    if (a[x].son==ch)
        return(x+1);
    if (x==0)
        return(0);
    return(child(a[x].suffix,ch));
}
bool solve(int x,int y)
{
    if (vis[x][y])
        return(f[x][y]);
    vis[x][y]=true;
    bool &ret=f[x][y];
    if (y>=m && (t[y-m]=='0' && a[x].danger || t[y-m]=='1' && !a[x].danger))
        return(ret=false);
    if (y==n)
        return(ret=true);
    ret=false;
    for (int i=0;i<K;i++)
    {
        int u=child(x,i+'a');
        if (solve(u,y+1))
        {
            ret=true;
            pre[x][y]=u;
            p[x][y]=i;
            break;
        }
    }
    return(ret);
}
int main()
{
    scanf("%d%d%s%s",&n,&K,s,t);
    m=strlen(s);
    for (int i=0;i<m;i++)
    {
        a[i].son=s[i];
        a[i+1].ch=s[i];
        a[i+1].father=i;
    }
    a[m].son=' ';
    a[m].danger=true;
    a[0].danger=false;
    for (int i=1;i<=m;i++)
        if (a[i].father==0)
            a[i].suffix=0;
        else
            a[i].suffix=child(a[a[i].father].suffix,a[i].ch);
    if (!solve(0,0))
        printf("No solution\n");
    else
    {
        int x=0;
        for (int i=0;i<n;i++)
        {
            printf("%c",p[x][i]+'a');
            x=pre[x][i];
        }
        printf("\n");
    }
    return(0);
}

