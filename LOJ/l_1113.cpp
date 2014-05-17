#include <cstdio>
#include <string>
using namespace std;
string a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int now,top;
        a[now=top=1]="http://www.lightoj.com/";
        static int id=0;
        printf("Case %d:\n",++id);
        while (1)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='V')
            {
                char buf[1000];
                scanf("%s",buf);
                a[++now]=buf;
                top=now;
            }
            else if (op[0]=='B')
            {
                if (now==1)
                {
                    printf("Ignored\n");
                    continue;
                }
                now--;
            }
            else if (op[0]=='F')
            {
                if (now==top)
                {
                    printf("Ignored\n");
                    continue;
                }
                now++;
            }
            else
                break;
            printf("%s\n",a[now].c_str());
        }
    }
    return(0);
}

