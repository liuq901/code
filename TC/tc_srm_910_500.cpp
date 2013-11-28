typedef long long ll;
const int mod=1000000007;
int f[60][60][2510];
struct LittleElephantAndPermutationDiv1
{
    int getNumber(int n,int K)
    {
        f[0][0][0]=1;
        int m=n*n;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=i;j++)
                for (int k=0;k<=m;k++)
                {
                    if (j>=1)
                        f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
                    if (k>=i)
                        f[i][j][k]=(f[i][j][k]+ll(j*2+1)*f[i-1][j][k-i])%mod;
                    if (k>=2*i)
                        f[i][j][k]=(f[i][j][k]+ll(j+1)*(j+1)*f[i-1][j+1][k-2*i])%mod;
                }
        int ans=0;
        for (int i=K;i<=m;i++)
            ans=(ans+f[n][0][i])%mod;
        for (int i=1;i<=n;i++)
            ans=ll(ans)*i%mod;
        return(ans);
    }
};
int main(){}

