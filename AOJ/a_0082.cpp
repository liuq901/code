#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10]={0,1,2,1,2,1,4,1,4};
int main()
{
    int p[10];
    while (scanf("%d",&p[1])==1)
    {
        for (int i=2;i<=8;i++)
            scanf("%d",&p[i]);
        int ans[10];
        ans[0]=1<<30;
        for (int i=1;i<=8;i++)
        {
            int sum=0;
            for (int j=1;j<=8;j++)
                sum+=max(0,p[j]-a[j]);
            if (sum<ans[0] || sum==ans[0] && vector <int>(a+1,a+9)<vector <int>(ans+1,ans+9))
            {
                ans[0]=sum;
                copy(a+1,a+9,ans+1);
            }
            rotate(a+1,a+2,a+9);
        }
        for (int i=1;i<=8;i++)
            printf("%d%c",ans[i],i==8?'\n':' ');
    }
    return(0);
}

