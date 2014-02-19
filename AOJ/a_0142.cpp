#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[5010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <int> b;
        for (int i=1;i<n;i++)
            b.push_back(i*i%n);
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        memset(a,0,sizeof(a));
        int m=(n-1)/2;
        for (int i=0;i<b.size();i++)
            for (int j=i+1;j<b.size();j++)
            {
                int t=b[i]-b[j];
                if (t<0)
                    t+=n;
                if (t>m)
                    t=n-t;
                a[t]++;
            }
        for (int i=1;i<=m;i++)
            printf("%d\n",a[i]<<1);
    }
    return(0);
}

