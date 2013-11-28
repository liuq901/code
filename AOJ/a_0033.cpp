#include <cstdio>
#include <vector>
using namespace std;
int a[20];
bool check(const vector <int> &a)
{
    for (int i=1;i<a.size();i++)
        if (a[i-1]>a[i])
            return(false);
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n=10;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        bool flag=false;
        for (int i=0;i<1<<n;i++)
        {
            vector <int> u,v;
            for (int j=1;j<=n;j++)
                (i>>j-1&1?u:v).push_back(a[j]);
            if (check(u) && check(v))
            {
                flag=true;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

