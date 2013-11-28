#include <cstdio>
#include <set>
using namespace std;
multiset <int> a;
char s[100];
int main()
{
    int n,K;
    while (scanf("%d%d",&n,&K)==2)
    {
        a.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if (s[0]=='I')
            {
                int x;
                scanf("%d",&x);
                a.insert(x);
            }
            else
            {
                while (a.size()>K)
                    a.erase(a.begin());
                printf("%d\n",*a.begin());
            }
        }
    }
    return(0);
}

