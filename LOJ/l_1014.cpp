#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int P,L;
        scanf("%d%d",&P,&L);
        int n=P-L;
        vector <int> ans;
        for (int i=1;i<=n/i;i++)
        {
            if (n%i!=0)
                continue;
            if (i>L)
                ans.push_back(i);
            if (n/i>L)
                ans.push_back(n/i);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        static int id=0;
        printf("Case %d:",++id);
        if (ans.empty())
            printf(" impossible\n");
        else
        {
            for (int i=0;i<ans.size();i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
    }
    return(0);
}

