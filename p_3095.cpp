#include <cstdio>
#include <cstring>
char a[100];
bool vis[100][2],f[100][2];
int n;
bool calc(int x,int p)
{
    if (x==-1 || x==n)
        return(true);
    int u=p==-1?0:1;
    if (vis[x][u])
        return(f[x][u]);
    vis[x][u]=true;
    bool &ret=f[x][u];
    if (a[x]=='.')
        ret=true;
    else if (a[x]=='_')
        ret=calc(x+p,p);
    else
        ret=false;
    return(ret);
}
int main()
{
    while (1)
    {
        scanf("%s",a);
        if (a[0]=='#')
            break;
        n=strlen(a);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]=='.')
                ans+=100;
            else if (a[i]=='/')
                ans+=calc(i-1,-1)*100;
            else if (a[i]=='\\')
                ans+=calc(i+1,1)*100;
            else if (a[i]=='|')
                ans+=calc(i-1,-1)*50+calc(i+1,1)*50;
        }
        printf("%d\n",int(double(ans)/n+1e-8));
    }
    return(0);
}

