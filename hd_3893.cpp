#include <cstdio>
#include <cstring>
typedef long long ll;
typedef int matrix[66][66];
const int mod=112233;
matrix one,zero,now,ret;
int a[66],ans[66],num[6][11];
void init()
{
    int t=0;
    for (int i=0;i<6;i++)
        for (int j=0;j<11;j++)
            num[i][j]=t++;
    for (int i=0;i<66;i++)
        zero[i][i]=1;
    for (int i=0;i<6;i++)
        for (int j=0;j<11;j++)
            for (int x=0;x<6;x++)
            {
                if (j==5 && x==5 || j==6 && x==0 || i==x)
                    continue;
                int y;
                if (j<=5 && x==j)
                    y=j+1;
                else if (j>5 && x+6==j)
                    y=j-1;
                else if (x==5)
                    y=10;
                else if (x==0)
                    y=1;
                else
                    y=0;
                one[num[i][j]][num[x][y]]=1;
            }
    for (int i=0;i<6;i++)
    {
        int j;
        j=0;
        if (i==0)
            j=1;
        if (i==5)
            j=10;
        a[num[i][j]]=1;
    }
}
ll c[66][66];
void multi(matrix a,matrix b,matrix ret)
{
    memset(c,0,sizeof(c));
    for (int k=0;k<66;k++)
        for (int i=0;i<66;i++)
        {
            if (!a[i][k])
                continue;
            for (int j=0;j<66;j++)
                c[i][j]+=ll(a[i][k])*b[k][j];
        }
    for (int i=0;i<66;i++)
        for (int j=0;j<66;j++)
            ret[i][j]=c[i][j]%mod;
}
void power(int n)
{
    memcpy(ret,zero,sizeof(zero));
    memcpy(now,one,sizeof(one));
    for (;n;n>>=1)
    {
        if (n&1)
            multi(now,ret,ret);
        multi(now,now,now);
    }
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n%2==0)
        {
            printf("0\n");
            continue;
        }
        n=n+1>>1;
        power(n-1);
        memset(ans,0,sizeof(ans));
        for (int i=0;i<66;i++)
            for (int j=0;j<66;j++)
                ans[j]=(ans[j]+ll(a[i])*ret[i][j])%mod;
        int sum=0;
        for (int i=0;i<66;i++)
            sum=(sum+ans[i])%mod;
        printf("%d\n",sum);
    }
    return(0);
}

