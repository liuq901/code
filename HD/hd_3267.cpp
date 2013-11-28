#include <cstdio>
#include <cstring>
int f[10],a[10][10];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
void rebuild(int a[10][10],int &n)
{
    while (1)
    {
        bool flag=false;
        for (int i=0;i<n;i++)
            f[i]=i;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (a[i][j]>=2)
                {
                    f[find(i)]=find(j);
                    flag=true;
                }
        if (!flag)
            break;
        int m=0;
        int c[10],b[10][10]={0};
        for (int i=0;i<n;i++)
            if (i==find(i))
                c[i]=m++;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (a[i][j])
                    b[c[find(i)]][c[find(j)]]++;
        memcpy(a,b,sizeof(b));
        n=m;
    }
}
bool dfs(int a[10][10],int n,bool first)
{
    int c[10][10];
    memcpy(c,a,sizeof(c));
    rebuild(c,n);
    if (n==1)
        return(!first);
    bool flag=false;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
        {
            if (!c[i][j])
                continue;
            flag=true;
            if (first)
            {
                c[i][j]--;
                c[j][i]--;
                if (!dfs(c,n,false))
                    return(true);
                c[i][j]++;
                c[j][i]++;
            }
            else
            {
                c[i][j]++;
                c[j][i]++;
                if (!dfs(c,n,true))
                    return(true);
                c[i][j]--;
                c[j][i]--;
            }
        }
    if (!flag)
        return(first);
    return(false);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==-1 && m==-1)
            break;
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]++;
            a[y][x]++;
        }
        printf("%s\n",dfs(a,n,true)?"NO":"YES");
    }
    return(0);
}

