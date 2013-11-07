#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector <string> ans;
char buf[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    int ma=-1;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%s%d",buf,&x);
        if (x>ma)
        {
            ma=x;
            ans.clear();
        }
        if (x==ma)
            ans.push_back(buf);
    }
    for (int i=0;i<ans.size();i++)
        printf("%s\n",ans[i].c_str());
    return(0);
}

