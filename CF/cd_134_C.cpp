#include <cstdio>
#include <vector>
#include <map>
#include <utility>
using namespace std;
multimap <int,int> a,b;
vector <pair <int,int> > ans;
int main()
{
    int n;
    scanf("%d%*d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x!=0)
            a.insert(make_pair(-x,i));
    }
    bool flag=true;
    while (!a.empty())
    {
        int y=-a.begin()->first,x=a.begin()->second;
        a.erase(a.begin());
        if (a.size()<y)
        {
            flag=false;
            break;
        }
        for (int i=1;i<=y;i++)
        {
            ans.push_back(make_pair(x,a.begin()->second));
            if (a.begin()->first!=-1)
                b.insert(make_pair(a.begin()->first+1,a.begin()->second));
            a.erase(a.begin());
        }
        a.insert(b.begin(),b.end());
        b.clear();
    }
    if (!flag)
        printf("No\n");
    else
    {
        printf("Yes\n%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return(0);
}

