#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector <pair <int,int> > ans;
int main()
{
    int x,y,a,b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    for (int i=a;i<=x;i++)
        for (int j=b;j<=y;j++)
            if (i>j)
                ans.push_back(make_pair(i,j));
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return(0);
}

