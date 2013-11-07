#include <cstdio>
#include <vector>
#include <string>
#include <set>
using namespace std;
string s[1010];
char buf[10000];
vector <int> ans;
set <string> S;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        s[i]=buf;
    }
    for (int i=1;i<=n;i++)
    {
        if (n%i!=0)
            continue;
        bool flag=true;
        S.clear();
        int p=n/i;
        for (int j=1;j<=n;j+=p)
        {
            string here;
            for (int k=j;k<j+p;k++)
                if (s[k]!="unknown")
                {
                    here=s[k];
                    break;
                }
            if (here=="")
                continue;
            if (S.count(here))
            {
                flag=false;
                goto out;
            }
            S.insert(here);
            for (int k=j;k<j+p;k++)
                if (s[k]!="unknown" && s[k]!=here)
                {
                    flag=false;
                    goto out;
                }
        }
out:
        if (flag)
            ans.push_back(i);
    }
    if (ans.empty())
        printf("Igor is wrong.\n");
    else
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return(0);
}

