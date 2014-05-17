#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
struct trie
{
    int cnt,son[52];
};
trie a[100010];
char buf[1000000];
int m;
void clear(int x)
{
    a[x].cnt=0;
    memset(a[x].son,0,sizeof(a[x].son));
}
int get(char ch)
{
    if (isupper(ch))
        return(ch-'A');
    return(ch-'a'+26);
}
int calc(int n,char buf[])
{
    int now=1;
    for (int i=0;i<n;i++)
        now=a[now].son[get(buf[i])];
    return(a[now].cnt);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        clear(m=1);
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            int len=strlen(buf),now=1;
            if (len>2)
                sort(buf+1,buf+len-1);
            for (int j=0;j<len;j++)
            {
                int x=get(buf[j]);
                if (a[now].son[x]==0)
                {
                    clear(++m);
                    a[now].son[x]=m;
                }
                now=a[now].son[x];
            }
            a[now].cnt++;
        }
        int Q;
        scanf("%d",&Q);
        gets(buf);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            gets(buf);
            stringstream sin(buf);
            int ans=1;
            while (sin>>buf)
            {
                int len=strlen(buf);
                if (len>2)
                    sort(buf+1,buf+len-1);
                ans*=calc(len,buf);
            }
            printf("%d\n",ans);
        }
    }
    return(0);
}

