#include <cstdio>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
int l[100000],t[100000];
char buf[100000];
int main()
{
    while (1)
    {
        scanf("%s",buf);
        if (buf[0]=='-')
            break;
        int n=0;
        M.clear();
        while (buf[0]!='$')
        {
            M[buf]=++n;
            scanf("%d%d%s",&l[n],&t[n],buf);
        }
        int S,T,hour,min;
        scanf("%s",buf);
        S=M[buf];
        scanf("%s",buf);
        T=M[buf];
        scanf("%d:%d%*s",&hour,&min);
        int now=hour*60+min,ans=0,tot=0,len=0,time=0;
        for (int i=S;i<=T;i++)
        {
            for (int j=1;j<=l[i];j++)
            {
                int cost;
                tot++;
                if (tot<=10)
                    cost=1000;
                else if (tot<=30)
                    cost=250;
                else
                    cost=100;
                int tmp=now;
                now+=t[i];
                if (now>1440 || tmp<360 || now<=360)
                    cost+=cost/5;
                ans+=cost;
                now%=1440;
            }
            len+=l[i];
            time+=l[i]*t[i];
        }
        if (2*len<time)
            ans+=ans/10;
        printf("%d\n",ans);
    }
    return(0);
}

