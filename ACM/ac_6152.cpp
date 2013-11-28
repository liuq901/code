#include <cstdio>
#include <cstring>
char a[110],b[110];
int F[110][210];
inline int &f(int x,int y)
{
    return(F[x][y+100]);
}
inline void update(int &x,int y)
{
    if (x==-1 || y<x)
        x=y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),ans=-1;
        if (n==strlen(b+1))
        {
            memset(F,-1,sizeof(F));
            f(0,0)=0;
            for (int i=1;i<=n;i++)
                for (int j=-i;j<=i;j++)
                {
                    if (f(i-1,j)==-1)
                        continue;
                    update(f(i,j-(b[i]=='0')),f(i-1,j)+(a[i]!='1'));
                    if (a[i]!='1')
                        update(f(i,j+(b[i]=='1')),f(i-1,j)+(a[i]!='0')+(b[i]=='1'));
                }
            ans=f(n,0);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

