#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[510],ans[510];
int f[510][510],F[510][510],pre[510][510];
int calc(int l,int r)
{
    if (f[l][r]!=-1)
        return(f[l][r]);
    if (l>=r)
        return(f[l][r]=0);
    return(f[l][r]=calc(l+1,r-1)+(s[l]!=s[r]));
}
void pali(int l,int r)
{
    int L=l,R=r;
    while (l<=r)
    {
        ans[l]=ans[r]=s[l];
        l++,r--;
    }
    for (int i=L;i<=R;i++)
        printf("%c",ans[i]);
}
void print(int m,int n)
{
    if (m!=1)
    {
        print(m-1,pre[m][n]);
        printf("+");
        pali(pre[m][n]+1,n);
    }
    else
        pali(0,n);
}
int main()
{
    int m;
    scanf("%s%d",s,&m);
    int n=strlen(s);
    memset(f,-1,sizeof(f));
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)
            calc(i,j);
    memset(F,63,sizeof(F));
    for (int i=0;i<n;i++)
        F[1][i]=f[0][i];
    for (int i=2;i<=m;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<j;k++)
                if (F[i-1][k]+f[k+1][j]<F[i][j])
                {
                    F[i][j]=F[i-1][k]+f[k+1][j];
                    pre[i][j]=k;
                }
    int ans=1<<30,k;
    for (int i=1;i<=m;i++)
        if (F[i][n-1]<ans)
        {
            ans=F[i][n-1];
            k=i;
        }
    printf("%d\n",ans);
    print(k,n-1);
    printf("\n");
    return(0);
}

