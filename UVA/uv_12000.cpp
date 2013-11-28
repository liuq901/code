#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=120,mod=73405;
typedef int matrix[N+10][N+10];
matrix a,one;
int ans[N+10];
int get(int a,int b,int c)
{
    return((a+2)*20+(b+1)*4+c+1);
}
void init(int K)
{
    memset(one,0,sizeof(one));
    for (int a=-2;a<=3;a++)
    {
        if (abs(a)>K)
            continue;
        for (int b=-1;b<=3;b++)
        {
            if (abs(b)>K)
                continue;
            for (int c=0;c<=3;c++)
            {
                if (abs(c)>K)
                    continue;
                if (K>=0)
                    one[get(b,c,0)][get(a,b,c)]++;
                if (K>=1 && abs(c+1)<=K)
                    one[get(b,-1,c+1)][get(a,b,c)]++;
                if (K>=2 && abs(b+1)<=K && abs(c+1)<=K)
                    one[get(-2,b+1,c+1)][get(a,b,c)]++;
                if (K>=3 && abs(a+1)<=K && abs(b+1)<=K && abs(c+1)<=K)
                    one[get(a+1,b+1,c+1)][get(a,b,c)]++;
            }
        }
    }
}
void mul(matrix c,matrix a,matrix b)
{
    matrix d={0};
    for (int k=1;k<=N;k++)
        for (int i=1;i<=N;i++)
        {
            if (!a[i][k])
                continue;
            for (int j=1;j<=N;j++)
                d[i][j]=(d[i][j]+ll(a[i][k])*b[k][j])%mod;
        }
    memcpy(c,d,sizeof(d));
}
void power(int x)
{
    memset(a,0,sizeof(a));
    for (int i=1;i<=N;i++)
        a[i][i]=1;
    for (;x;x>>=1)
    {
        if (x&1)
            mul(a,a,one);
        mul(one,one,one);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        static int id=0;
        printf("Case %d: ",++id);
        if (n<3)
        {
            if (n==1)
                printf("1\n");
            else
                printf("%d\n",K==0?1:2);
            continue;
        }
        int c[10]={0,1,2,3};
        memset(ans,0,sizeof(ans));
        while (1)
        {
            int x=1-c[1],y=2-c[2],z=3-c[3];
            if (abs(x)<=K && abs(y)<=K && abs(z)<=K)
                ans[get(x,y,z)]++;
            if (!next_permutation(c+1,c+4))
                break;
        }
        init(K);
        power(n-3);
        int sum=0;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                sum=(sum+ll(a[i][j])*ans[j])%mod;
        printf("%d\n",sum);
    }
    return(0);
}

