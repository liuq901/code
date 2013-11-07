#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int K,a[66000];
vector <int> ans;
vector <pair <int,int> > calc(const vector <pair <int,int> > &b,int winner)
{
    vector <pair <int,int> > ret;
    for (int i=0;i<b.size();i+=2)
    {
        pair <int,int> x,y;
        if (b[i].first>b[i+1].first || b[i].first==b[i+1].first && b[i].second<b[i+1].second)
            x=b[i],y=b[i+1];
        else
            x=b[i+1],y=b[i];
        if (x.second==winner)
            ans.push_back(y.second);
        x.first=min(a[x.second],x.first-y.first+K);
        ret.push_back(x);
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%d",&n,&K);
        n=1<<n;
        vector <pair <int,int> > b;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b.push_back(make_pair(a[i],i));
        }
        while (b.size()>1)
            b=calc(b,-1);
        int winner=b[0].second;
        b.clear();
        for (int i=1;i<=n;i++)
            b.push_back(make_pair(a[i],i));
        ans.clear();
        while (b.size()>1)
            b=calc(b,winner);
        printf("%d\n",winner);
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return(0);
}

