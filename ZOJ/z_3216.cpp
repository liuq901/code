#include <cstdio>
#include <cstring>
typedef long long ll;
typedef int matrix[40][40];
const int mod=1000000007;
int K;
matrix zero,one,ans;
void mul(matrix a,matrix b,matrix c)
{
    matrix d={0};
    for (int i=1;i<=K;i++)
        for (int j=1;j<=K;j++)
            for (int k=1;k<=K;k++)
                d[i][j]=(d[i][j]+ll(a[i][k])*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
void power(int n)
{
    memcpy(ans,zero,sizeof(zero));
    for (;n;n>>=1)
    {
        if (n&1)
            mul(ans,one,ans);
        mul(one,one,one);
    }
}
int power2(int n)
{
    int ret=1,two=2;
    for (;n;n>>=1)
    {
        if (n&1)
            ret=ll(ret)*two%mod;
        two=ll(two)*two%mod;
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
        scanf("%d%d",&n,&K);
        if (K==1)
            printf("%d\n",power2(n-1));
        else if (n<K)
            printf("0\n");
        else
        {
            memset(zero,0,sizeof(zero));
            memset(one,0,sizeof(one));
            for (int i=1;i<=K;i++)
                zero[i][i]=1;
            for (int i=1;i<K;i++)
                one[i][i+1]=1;
            one[K][1]=one[K][K]=1;
            power(n-K);
            printf("%d\n",ans[K][K]);
        }
    }
    return(0);
}

