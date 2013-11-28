#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
struct PickAndDelete
{
    vector <int> a;
    ll f[210][210],c[210][210];
    int count(vector <string> S)
    {
        string s;
        for (int i=0;i<S.size();i++)
            s+=S[i];
        stringstream sin(s);
        int x;
        while (sin>>x)
            a.push_back(x);
        a.push_back(0);
        sort(a.begin(),a.end());
        int n=a.size()-1;
        for (int i=0;i<=n;i++)
        {
            c[i][0]=c[i][i]=1;
            for (int j=1;j<n;j++)
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
        f[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
            {
                f[i][j]=f[i][j-1];
                for (int k=1;k<=min(n-j+1,i);k++)
                    f[i][j]=(f[i][j]+power(a[j]-a[j-1],k)*c[i][k]%mod*f[i-k][j-1]%mod)%mod;
            }
        return(f[n][n]);
    }
    ll power(int x,int k)
    {
        if (!k)
            return(1);
        ll ret=power(x,k>>1);
        ret=(ret*ret)%mod;
        if (k&1)
            ret=(ret*x)%mod;
        return(ret);
    }
};
int main(){}

