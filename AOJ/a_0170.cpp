#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int a[20],ans[20],s[20],w[20];
string name[20];
char buf[100000];
double calc(int n)
{
    int sum=0,tot=0;
    for (int i=n;i;i--)
    {
        int x=a[i];
        if (sum>s[x])
            return(1e100);
        sum+=w[x];
        tot+=i*w[x];
    }
    return(double(tot)/sum);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%s%d%d",buf,&w[i],&s[i]);
            name[i]=buf;
            a[i]=i;
        }
        double best=1e100;
        while (1)
        {
            double now=calc(n);
            if (now<best)
            {
                best=now;
                memcpy(ans,a,sizeof(a));
            }
            if (!next_permutation(a+1,a+n+1))
                break;
        }
        for (int i=1;i<=n;i++)
            printf("%s\n",name[ans[i]].c_str());
    }
    return(0);
}

