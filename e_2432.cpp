#include <cstdio>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[1010];
char buf[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        gets(buf);
        double ans=-1e100;
        int k;
        for (int i=1;i<=n;i++)
        {
            gets(buf);
            stringstream sin(buf);
            a[i].clear();
            int x;
            while (sin>>x)
                a[i].push_back(x);
            double sum=0;
            for (int j=0;j<a[i].size();j++)
                sum+=log(double(a[i][j]));
            if (sum>ans)
                ans=sum,k=i;
        }
        sort(a[k].begin(),a[k].end());
        for (int i=0;i<a[k].size();i++)
            printf("%d%c",a[k][i],i==a[k].size()-1?'\n':' ');
        printf("\n");
    }
    return(0);
}

