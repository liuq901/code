#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        bool flag=false;
        if (a>b)
        {
            flag=true;
            swap(a,b);
        }
        int r,c;
        for (int i=1;;i++)
        {
            ll before=1;
            for (int j=1;j<=i;j++)
            {
                ll now=before*(i-j+1)/j;
                if (now>b || now<before)
                    break;
                if (before==a && now==b)
                {
                    r=i,c=j;
                    goto ans;
                }
                before=now;
            }
        }
ans:
        if (flag)
            c=r-c+1;
        printf("%d %d\n",r+1,c);
    }
    return(0);
}

