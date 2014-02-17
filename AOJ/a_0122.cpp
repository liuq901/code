#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int c[12][2]={{-2,-1},{-2,0},{-2,1},{2,-1},{2,0},{2,1},{-1,-2},{0,-2},{1,-2},{-1,2},{0,2},{1,2}};
int main()
{
    while (1)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==0 && y==0)
            break;
        vector <pair <int,int> > a[20];
        a[0].push_back(make_pair(x,y));
        int n,X[20],Y[20];
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<a[i-1].size();j++)
            {
                int x0=a[i-1][j].first,y0=a[i-1][j].second;
                for (int k=0;k<12;k++)
                {
                    int x=x0+c[k][0],y=y0+c[k][1];
                    if (x>=0 && x<10 && y>=0 && y<10 && abs(x-X[i])<=1 && abs(y-Y[i])<=1)
                        a[i].push_back(make_pair(x,y));
                }
            }
            sort(a[i].begin(),a[i].end());
            a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
        }
        printf("%s\n",a[n].empty()?"NA":"OK");
    }
    return(0);
}

