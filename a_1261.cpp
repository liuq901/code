#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct state
{
    int w;
    double l[2];
    state(int w,double x,double y):w(w)
    {
        l[0]=x,l[1]=y;
    }
};
double len,ans;
void dfs(const vector <state> &a)
{
    if (a.size()==1)
    {
        double x=a.begin()->l[0],y=a.begin()->l[1];
        if (x+y<len)
            ans=max(ans,x+y);
        return;
    }
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            vector <state> b(a);
            b.erase(b.begin()+j);
            b.erase(b.begin()+i);
            double x=double(a[j].w)/(a[i].w+a[j].w),y=double(a[i].w)/(a[i].w+a[j].w);
            b.push_back(state(a[i].w+a[j].w,0,0));
            for (int k=0;k<2;k++)
                for (int p=0;p<2;p++)
                {
                    b.back().l[0]=max(a[i].l[k]+x,a[j].l[p^1]-y);
                    b.back().l[1]=max(a[j].l[p]+y,a[i].l[k^1]-x);
                    dfs(b);
                }
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%lf%d",&len,&n);
        vector <state> a;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(state(x,0,0));
        }
        ans=-1;
        dfs(a);
        if (ans<0)
            printf("-1\n");
        else
            printf("%.15f\n",ans);
    }
    return(0);
}

