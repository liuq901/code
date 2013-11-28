#include <cstdio>
#include <vector>
using namespace std;
int a[1010];
vector <vector <int> > ans;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int sum=0;
        vector <int> tmp;
        for (int j=1;j<=n;j++)
        {
            if (a[j]==i+1)
            {
                sum=-1;
                break;
            }
            if (a[j]<=i)
            {
                sum++;
                tmp.push_back(j);
            }
        }
        if (sum==i)
            ans.push_back(tmp);
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
    {
        printf("%d",ans[i].size());
        for (int j=0;j<ans[i].size();j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
    return(0);
}

