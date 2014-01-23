#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        m--;
        vector <int> a;
        for (int i=1;i<=n;i++)
            a.push_back(i);
        int now=0;
        while (a.size()>1)
        {
            now=(now+m)%a.size();
            a.erase(a.begin()+now);
        }
        printf("%d\n",a[0]);
    }
    return(0);
}

