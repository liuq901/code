#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int tmp[1010];
int calc(int a[],int n)
{
    int s=0;
    for (int i=1;i<=n;i++)
        s+=a[i];
    if (s%n!=0)
        return(-1);
    int ret=1<<30;
    s/=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            tmp[j]=a[j];
        int now=0;
        for (int j=1;j<=n;j++)
        {
            if (tmp[j]==s)
                continue;
            now+=abs(s-tmp[j]);
            tmp[j+1]+=tmp[j]-s;
        }
        ret=min(ret,now);
        rotate(a+1,a+2,a+n+1);
    }
    return(ret);
}
char a[1010][1010];
int row[1010],col[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                row[i]+=a[i][j]=='1';
                col[j]+=a[i][j]=='1';
            }
        static int id=0;
        printf("Case %d: ",++id);
        int u=calc(row,n),v=calc(col,m);
        if (u!=-1 && v!=-1)
            printf("both %d\n",u+v);
        else if (u!=-1)
            printf("row %d\n",u);
        else if (v!=-1)
            printf("column %d\n",v);
        else
            printf("impossible\n");
    }
    return(0);
}

