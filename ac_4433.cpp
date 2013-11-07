#include <cstdio>
#include <sstream>
#include <map>
using namespace std;
map <string,bool> a;
string to[30];
char buf[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        a.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            to[i]=buf;
            a[buf]=false;
        }
        int m;
        scanf("%d",&m);
        gets(buf);
        for (int i=1;i<=m;i++)
        {
            gets(buf);
            stringstream sin(buf);
            string tmp;
            while (sin>>tmp)
                if (a.count(tmp))
                    a[tmp]=true;
        }
        static int id=0;
        printf("Test set %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%s is %s\n",to[i].c_str(),a[to[i]]?"present":"absent");
        printf("\n");
    }
    return(0);
}

