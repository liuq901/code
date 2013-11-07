#include <cstdio>
#include <string>
using namespace std;
char s1[110],s2[110];
string a,b;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        scanf("%s%s",s1,s2);
        if (n<m)
        {
            printf("NO\n");
            continue;
        }
        a=s1,b=s2;
        a=a+a;
        bool flag=false;
        for (int i=0;i<a.size();i++)
            if (a.substr(i,m)==b)
            {
                flag=true;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

