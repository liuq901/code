#include <cstdio>
#include <cstring>
int dep,len[60],g[60][110],a[60][110],sg[60][110][110];
int calc(int x,int l,int r)
{
    if (l>r)
        return(0);
    if (sg[x][l][r]!=-1)
        return(sg[x][l][r]);
    int tmp=++dep,f[110];
    for (int i=l;i<=r;i++)
    {
        int now=0,last=l;
        for (int j=l;j<=r;j++)
            if (a[x][j]<=a[x][i])
            {
                now^=calc(x,last,j-1);
                last=j+1;
            }
        now^=calc(x,last,r);
        if (l==1 && r==len[x])
            g[x][i]=now;
        f[now]=tmp;
    }
    int &ans=sg[x][l][r];
    ans=0;
    while (f[ans]==tmp)
        ans++;
    return(ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&len[i]);
        for (int j=1;j<=len[i];j++)
            scanf("%d",&a[i][j]);
    }
    memset(sg,-1,sizeof(sg));
    int ans=0;
    for (int i=1;i<=n;i++)
        ans^=calc(i,1,len[i]);
    if (ans==0)
        printf("S\n");
    else
    {
        printf("G\n");
        for (int i=1;i<=n;i++)
        {
            int now=ans^sg[i][1][len[i]];
            for (int j=1;j<=len[i];j++)
                if ((now^g[i][j])==0)
                {
                    printf("%d %d\n",i,j);
                    goto out;
                }
        }
    }
out:
    return(0);
}

