#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int s[40],f[40][1300],c[1300][1300];
struct LISNumber
{
    int calc(const vector <int> &a,int n)
    {
        for (int i=0;i<a.size();i++)
        {
            s[i]=a[i];
            if (i>0)
                s[i]+=s[i-1];
            if (a[i]>n)
                return(0);
        }
        memset(f,0,sizeof(f));
        f[0][s[0]]=1;
        for (int i=0;i<a.size()-1;i++)
            for (int j=0;j<=s[i];j++)
            {
                if (f[i][j]==0)
                    continue;
                for (int k=min(a[i+1],j);k>=0;k--)
                {
                    int x=a[i+1]-k;
                    if (j+x>n)
                        break;
                    f[i+1][j+x]=(f[i+1][j+x]+ll(f[i][j])*c[j][k]%mod*c[s[i]-j+k+x][s[i]-j+k])%mod;
                }
            }
        return(f[a.size()-1][n]);
    }
    int count(vector <int> cardsnum,int K)
    {
        for (int i=0;i<=1296;i++)
        {
            c[i][0]=c[i][i]=1;
            for (int j=1;j<i;j++)
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
        int ans=calc(cardsnum,K);
        return(ans);
    }
};
int main(){}

