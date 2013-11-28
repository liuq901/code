#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct PieSharing
{
    int share(vector <int> pieces)
    {
        int ans=0,n=pieces.size();
        for (int i=0;i<n;i++)
        {
            vector <int> a;
            for (int j=0;j<n;j++)
                a.push_back(pieces[(i+j)%n]);
            ans=max(ans,dp(a));
        }
        return(ans);
    }
    int dp(vector <int> a)
    {
        int n=a.size(),f[50][20];
        memset(f,-63,sizeof(f));
        f[0][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=n/3;j++)
            {
                f[i][j]=f[i-1][j];
                if (i>=2 && j>=1)
                    f[i][j]=max(f[i][j],f[i-2][j-1]+a[i-1]);
            }
        return(f[n][n/3]);
    }
};
int main(){}

