#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,mi=1<<30,ma=-1;
        scanf("%d",&n);
        string s,t;
        for (int i=1;i<=n;i++)
        {
            char name[30];
            int x,y,z;
            scanf("%s%d%d%d",name,&x,&y,&z);
            x*=y*z;
            if (x>ma)
                ma=x,t=name;
            if (x<mi)
                mi=x,s=name;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (s==t)
            printf("no thief\n");
        else
            printf("%s took chocolate from %s\n",t.c_str(),s.c_str());
    }
    return(0);
}

