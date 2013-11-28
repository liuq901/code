#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int f[60][60];
struct GUMIAndSongsDiv1
{
    int maxSongs(vector <int> duration,vector <int> tone,int T)
    {
        vector <pair <int,int> > a;
        int n=duration.size();
        for (int i=0;i<n;i++)
            a.push_back(make_pair(tone[i],duration[i]));
        sort(a.begin(),a.end());
        memset(f,63,sizeof(f));
        for (int i=0;i<n;i++)
            f[1][i]=a[i].second;
        for (int i=2;i<=n;i++)
            for (int j=0;j<n;j++)
                for (int k=j+1;k<n;k++)
                    f[i][k]=min(f[i][k],f[i-1][j]+a[k].first-a[j].first+a[k].second);
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<n;j++)
                if (f[i][j]<=T)
                    ans=max(ans,i);
        return(ans);
    }
};
int main(){}

