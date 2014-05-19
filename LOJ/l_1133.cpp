#include <cstdio>
#include <valarray>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        valarray <int> a(n);
        for (int i=0;i<a.size();i++)
            scanf("%d",&a[i]);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='S')
            {
                int x;
                scanf("%d",&x);
                a+=x;
            }
            else if (op[0]=='M')
            {
                int x;
                scanf("%d",&x);
                a*=x;
            }
            else if (op[0]=='D')
            {
                int x;
                scanf("%d",&x);
                a/=x;
            }
            else if (op[0]=='R')
                for (int i=0;i<a.size()/2;i++)
                    swap(a[i],a[a.size()-i-1]);
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                swap(a[x],a[y]);
            }
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=0;i<a.size();i++)
            printf("%d%c",a[i],i+1==a.size()?'\n':' ');
    }
    return(0);
}

