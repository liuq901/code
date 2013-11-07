#include <cstring>
#include <vector>
using namespace std;
const int mod=100;
struct RingImposition
{
    typedef int matrix[60][60];
    int n;
    matrix one,zero,a;
    vector <int> predict(vector <int> seq,int N)
    {
        n=seq.size();
        memset(zero,0,sizeof(zero));
        memset(one,0,sizeof(one));
        for (int i=1;i<=n;i++)
            zero[i][i]=1;
        for (int i=1;i<n;i++)
            one[i][i]=one[i][i+1]=1;
        one[n][1]=one[n][n]=1;
        power(N);
        vector <int> ans(n,0);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                ans[i-1]=(ans[i-1]+seq[j-1]*a[i][j])%mod;
        return(ans);
    }
    void power(int n)
    {
        memcpy(a,zero,sizeof(zero));
        for (;n;n>>=1)
        {
            if (n&1)
                mul(a,one,a);
            mul(one,one,one);
        }
    }
    void mul(matrix a,matrix b,matrix c)
    {
        matrix d={0};
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
        memcpy(c,d,sizeof(d));
    }
};
int main(){}

