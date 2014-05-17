#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct NarrowPassage
{
    int n,c[60],d[60];
    static vector <int> tmp;
    int minDist(int L,vector <int> a,vector <int> b)
    {
        n=a.size();
        get(n,c,a);
        get(n,d,b);
        int ans=1<<30;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n-i;j++)
            {
                if (!check(i,n-j-1))
                    continue;
                int now=0,l=i,r=n-j-1;
                for (int k=0;k<l;k++)
                    now+=a[c[k]]+b[d[k]];
                for (int k=l;k<=r;k++)
                    now+=abs(a[c[k]]-b[d[k]]);
                for (int k=r+1;k<n;k++)
                    now+=2*L-a[c[k]]-b[d[k]];
                ans=min(ans,now);
            }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
            {
                bool left[60]={0};
                int sum=0;
                for (int k=0;k<i;k++)
                {
                    left[c[k]]=true;
                    sum+=a[c[k]];
                }
                for (int k=i;k<n;k++)
                    sum+=L-a[c[k]];
                for (int k=0;k<j;k++)
                {
                    sum+=b[d[k]];
                    if (!left[d[k]])
                        sum+=L;
                }
                for (int k=j;k<n;k++)
                {
                    sum+=L-b[d[k]];
                    if (left[d[k]])
                        sum+=L;
                }
                ans=min(ans,sum);
            }
        return(ans);
    }
    bool check(int l,int r)
    {
        for (int i=l;i<=r;i++)
            if (c[i]!=d[i])
                return(false);
        bool left[60]={0},right[60]={0};
        for (int i=0;i<l;i++)
            left[c[i]]=true;
        for (int i=0;i<l;i++)
            if (!left[d[i]])
                return(false);
        for (int i=r+1;i<n;i++)
            right[c[i]]=true;
        for (int i=r+1;i<n;i++)
            if (!right[d[i]])
                return(false);
        return(true);
    }
    void get(int n,int c[],const vector <int> a)
    {
        tmp=a;
        for (int i=0;i<n;i++)
            c[i]=i;
        sort(c,c+n,cmp);
    }
    static bool cmp(int x,int y)
    {
        return(tmp[x]<tmp[y]);
    }
};
vector <int> NarrowPassage::tmp;
int main(){}

