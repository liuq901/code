#include <cstdio>
#include <cstring>
int b[1010],a[2010][3];
int sg(int x,int father)
{
    int ret=0;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        int tmp=sg(y,x);
        if (a[i][1]==1)
            ret^=tmp+1;
        else if (a[i][1]&1)
            ret^=tmp^1;
        else
            ret^=tmp;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,sg(1,0)?"Emily":"Jolly");
    }
    return(0);
}

