#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int X[110],Y[110],s[110],a[110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <int> v;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&X[i],&Y[i]);
            v.push_back(X[i]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for (int i=1;i<=n;i++)
            X[i]=lower_bound(v.begin(),v.end(),X[i])-v.begin()+1;
        int ans=1,m=v.size();
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                memset(s,0,sizeof(s));
                memset(a,0,sizeof(a));
                for (int k=1;k<=n;k++)
                {
                    if (Y[i]==Y[k])
                        s[X[k]]++;
                    if (Y[j]==Y[k] && Y[i]!=Y[j])
                        s[X[k]]++;
                    if (Y[k]>min(Y[i],Y[j]) && Y[k]<max(Y[i],Y[j]))
                        a[X[k]]++;
                }
                for (int k=1;k<=m+1;k++)
                    s[k]+=s[k-1];
                int ma=s[m+1];
                for (int k=m;k;k--)
                {
                    ans=max(ans,ma+a[k]-s[k-1]);
                    ma=max(ma,s[k]+a[k]);
                }
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

