#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    map <string,int> M;
    for (int i=1;i<=n;i++)
    {
        char tmp[20];
        scanf("%s",tmp);
        M[tmp]++;
    }
    string ans;
    int ma=0;
    for (map <string,int>::iterator k=M.begin();k!=M.end();k++)
        if (k->second>ma)
        {
            ma=k->second;
            ans=k->first;
        }
    printf("%s\n",ans.c_str());
    return(0);
}

