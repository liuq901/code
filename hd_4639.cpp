#include <cstdio>
#include <string>
using namespace std;
const int mod=10007;
char buf[100000];
int f[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        string s=buf;
        f[s.size()]=1;
        for (int i=s.size()-1;i>=0;i--)
        {
            f[i]=f[i+1];
            if (s.substr(i,4)=="hehe")
                f[i]=(f[i]+f[i+4])%mod;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[0]);
    }
    return(0);
}

