#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
string s;
char buf[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        gets(buf);
        gets(buf);
        s=buf;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            gets(buf);
            stringstream sin(buf);
            string tmp;
            while (sin>>tmp)
                if (s==tmp)
                {
                    ans++;
                    break;
                }
        }
        if (ans==0)
            printf("Do not find\n\n");
        else
            printf("%d\n\n",ans);
    }
    return(0);
}

