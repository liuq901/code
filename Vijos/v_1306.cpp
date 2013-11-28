#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[100][100],pre[100][100];
char a[100];
bool check(int l1,int r1,int l2,int r2)
{
    int len=max(r1-l1,r2-l2);
    for (int i=len;i>=0;i--)
    {
        int u=r1-i>=l1?a[r1-i]-'0':0,v=r2-i>=l2?a[r2-i]-'0':0;
        if (u!=v)
            return(u<v);
    }
    return(false);
}
void print(int l,int r)
{
    if (l!=1)
    {
        print(pre[l][r],l-1);
        printf(",");
    }
    for (int i=l;i<=r;i++)
        printf("%c",a[i]);
}
int main()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    memset(f,-63,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        f[1][i]=1;
        for (int j=2;j<=i;j++)
            for (int k=1;k<j;k++)
                if (check(k,j-1,j,i) && f[k][j-1]+1>=f[j][i])
                {
                    f[j][i]=f[k][j-1]+1;
                    pre[j][i]=k;
                }
    }
    int ans=0,k;
    for (int i=1;i<=n;i++)
        if (f[i][n]>=ans)
        {
            ans=f[i][n];
            k=i;
        }
    print(k,n);
    printf("\n");
    return(0);
}

