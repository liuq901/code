#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <bool> a[10];
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (x==1)
            {
                int t=0;
                for (int j=z;j<=z+y-1;j++)
                    t=max(t,int(a[j].size()));
                for (int j=z;j<=z+y-1;j++)
                {
                    a[j].insert(a[j].end(),t-a[j].size(),false);
                    a[j].push_back(true);
                }
            }
            else
                a[z].insert(a[z].end(),y,true);
            int t=1<<30;
            for (int j=1;j<=5;j++)
                t=min(t,int(a[j].size()));
            vector <int> del;
            for (int j=0;j<t;j++)
            {
                bool flag=true;
                for (int k=1;k<=5;k++)
                    if (!a[k][j])
                    {
                        flag=false;
                        break;
                    }
                if (flag)
                    del.push_back(j);
            }
            reverse(del.begin(),del.end());
            for (int j=0;j<del.size();j++)
                for (int k=1;k<=5;k++)
                    a[k].erase(a[k].begin()+del[j]);
            for (int j=1;j<=5;j++)
                while (!a[j].empty() && !a[j].back())
                    a[j].pop_back();
        }
        int ans=0;
        for (int i=1;i<=5;i++)
            ans+=count(a[i].begin(),a[i].end(),true);
        printf("%d\n",ans);
    }
    return(0);
}

