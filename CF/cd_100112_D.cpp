#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char buf[110];
int a[110],F[110][110][210];
inline int &f(int x,int y,int z)
{
    return(F[x][y][z+105]);
}
int main()
{
    int m;
    scanf("%d%s",&m,buf);
    int n=strlen(buf);
    for (int i=1;i<=n;i++)
        a[i]=buf[i-1]=='M'?1:-1;
    memset(F,-63,sizeof(F));
    f(1,0,0)=0;
    int ans=0;
    for (int i=1;i<=n+1;i++)
        for (int j=i;j>=0;j--)
            for (int k=-m;k<=m;k++)
            {
                ans=max(ans,f(i,j,k));
                f(i+1,j,k+a[i])=max(f(i+1,j,k+a[i]),f(i,j,k)+1);
                if (j)
                    f(i,0,k+a[j])=max(f(i,0,k+a[j]),f(i,j,k)+1);
                else
                    f(i+1,i,k)=max(f(i+1,i,k),f(i,j,k));
            }
    printf("%d\n",ans);
    return(0);
}

