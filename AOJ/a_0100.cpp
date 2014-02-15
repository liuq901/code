#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
char s[1000000];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <string> name;
        map <string,ll> M;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if (!M.count(s))
                name.push_back(s);
            M[s]+=ll(x)*y;
        }
        bool flag=false;
        for (int i=0;i<name.size();i++)
            if (M[name[i]]>=1000000)
            {
                flag=true;
                printf("%s\n",name[i].c_str());
            }
        if (!flag)
            printf("NA\n");
    }
    return(0);
}

