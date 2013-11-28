#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int f[60][1200][60];
struct Distincter
{
    int disperse(vector <int> a,int K)
    {
        int n=a.size(),m=1100;
        sort(a.begin(),a.end());
        for (int i=0;i<n;i++)
            a[i]+=50;
        memset(f,63,sizeof(f));
        for (int i=0;i<=m;i++)
            f[0][i][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=n;k++)
                    f[i][j][k]=min(f[i][j-1][k],min(f[i-1][j-1][k-1],f[i-1][j][k])+abs(a[i-1]-j));
        int ans=1<<30;
        for (int i=1;i<=m;i++)
            for (int j=K;j<=n;j++)
               ans=min(ans,f[n][i][j]);
        return(ans);
    }
};
int main(){}

