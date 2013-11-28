#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;
map <string,int> M;
vector <pair <string,int> > a;
char s[100];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%*s%s",&x,s);
        M[s]=x;
    }
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%*s%s",&x,s);
        a.push_back(make_pair(s,x));
    }
    int ans=0;
    while (!a.empty())
    {
        ans++;
        string s=a.begin()->first;
        int last=M[s],num=a.begin()->second;
        a.erase(a.begin());
        if (last==0)
            continue;
        if (last>=num)
        {
            M[s]-=num;
            continue;
        }
        num=last;
        if (!a.empty())
            a.insert(a.begin()+1,make_pair(s,num));
    }
    printf("%d\n",ans);
    return(0);
}

