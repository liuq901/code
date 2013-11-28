#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <utility>
#include <map>
#include <vector>
using namespace std;
typedef pair <string,string> name;
typedef map <name,int>::iterator iter;
const name begin=make_pair("Kevin","Bacon");
const int Q=100000;
map <name,int> M;
vector <int> here;
vector <pair <int,int> > a[1200];
char buf[1000];
int l,N,inf;
int get_int()
{
    int ret=0;
    for (int i=l;;i++)
    {
        if (!isdigit(buf[i]))
        {
            l=i+1;
            return(ret);
        }
        ret=ret*10+buf[i]-'0';
    }
}
string get_string()
{
    string ret;
    for (int i=l;;i++)
    {
        if (buf[i]==',' || buf[i]==':')
        {
            l=i+2;
            return(ret);
        }
        ret+=buf[i];
    }
}
int hash(const name &p)
{
    iter k=M.find(p);
    if (k==M.end())
    {
        N++;
        a[N].clear();
        M[p]=N;
        return(N);
    }
    return(k->second);
}
int d[1200],q[Q+10];
bool in[1200];
void spfa()
{
    memset(d,63,sizeof(d));
    inf=d[0];
    iter k=M.find(begin);
    if (k==M.end())
        return;
    int l=0,r=1;
    q[1]=k->second;
    in[k->second]=true;
    d[k->second]=0;
    while (l!=r)
    {
        int x=q[l=l==Q?1:l+1];
        in[x]=false;
        for (int i=0;i<a[x].size();i++)
        {
            int y=a[x][i].first,dis=a[x][i].second;
            if (d[x]+dis<d[y])
            {
                d[y]=d[x]+dis;
                if (!in[y])
                {
                    in[y]=true;
                    q[r=r==Q?1:r+1]=y;
                }
            }
        }
    }
}
int main()
{
    while (1)
    {
        int p,n;
        scanf("%d%d",&p,&n);
        if (p==0 && n==0)
            break;
        gets(buf);
        M.clear();
        N=0;
        for (int T=1;T<=p;T++)
        {
            gets(buf);
            int len=strlen(buf),end;
            for (int i=0;i<len;i++)
                if (buf[i]==':')
                {
                    end=i;
                    break;
                }
            l=0;
            int value=get_int();
            here.clear();
            while (l<end)
            {
                string last=get_string(),first=get_string();
                here.push_back(hash(make_pair(last,first)));
            }
            for (int i=0;i<here.size();i++)
                for (int j=i+1;j<here.size();j++)
                {
                    int x=here[i],y=here[j];
                    a[x].push_back(make_pair(y,value));
                    a[y].push_back(make_pair(x,value));
                }
        }
        spfa();
        static int id=0;
        printf("Database %d\n",++id);
        for (int i=1;i<=n;i++)
        {
            gets(buf);
            l=0;
            int len=strlen(buf);
            buf[len]=':';
            buf[len+1]='\0';
            string last=get_string(),first=get_string();
            iter k=M.find(make_pair(last,first));
            printf("%s ",buf);
            if (k==M.end() || d[k->second]==inf)
                printf("infinity\n");
            else
                printf("%d\n",d[k->second]);
        }
        printf("\n");
    }
    return(0);
}

