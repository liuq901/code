#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#define N 200010
using namespace std;
typedef unsigned long long ull;
const int lq=2353,LQ=6131,mod=100007;
char buf[N];
ull a[30],b[30],f1[N],f2[N];
int now[30],c[N],d[mod+10],g[N][30];
int main()
{
    a[0]=lq;
    b[0]=LQ;
    for (int i=1;i<26;i++)
    {
        a[i]=a[i-1]*lq;
        b[i]=b[i-1]*LQ;
    }
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        gets(buf);
        gets(buf);
        int len=strlen(buf),l=1,r=len,ans=0,tot=0;
        ull x=0,y=0;
        string s;
        memset(now,0,sizeof(now));
        memset(d,0,sizeof(d));
        for (int i=0;i<len;i++)
        {
            if (!isalpha(buf[i]))
            {
                ans++;
                continue;
            }
            s+=tolower(buf[i]);
            int p=s[s.size()-1]-'a';
            now[p]++;
            x+=a[p];
            y+=b[p];
            if (s.size()>=n)
            {
                if (s.size()>n)
                {
                    int q=s[s.size()-n-1]-'a';
                    x-=a[q];
                    y-=b[q];
                    now[q]--;
                    int t=x%mod;
                    for (int j=d[t];j;j=c[j])
                        if (f1[j]==x && f2[j]==y)
                        {
                            bool flag=true;
                            for (int k=0;k<26;k++)
                                if (g[j][k]!=now[k])
                                {
                                    flag=false;
                                    break;
                                }
                            if (flag)
                                goto last;
                        }
                }
                int t=x%mod;
                c[++tot]=d[t];
                f1[tot]=x;
                f2[tot]=y;
                for (int j=0;j<26;j++)
                    g[tot][j]=now[j];
                d[t]=tot;
            }
            ans++;
        }
last:
        printf("%d\n",ans);
    }
    return(0);
}

