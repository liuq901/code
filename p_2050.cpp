#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int mod=100007,lq=1321;
int n;
char buf[100000];
bool f1[110],f2[110];
ull c[30];
vector <string> q,a[110];
vector <vector <string> > b[110];
vector <pair <int,int> > out,f[mod];
ull hash(const string &s)
{
    ull ret=0;
    for (int i=0;i<s.size();i++)
        ret=ret*lq+c[s[i]-'a'];
    return(ret);
}
inline bool get(const pair <int,int> &pos,const string &s)
{
    int x=pos.first,y=pos.second;
    for (int i=0;i<b[x][y].size();i++)
        if (b[x][y][i]==s)
            return(true);
    return(false);
}
void query()
{
    out.clear();
    if (q.size()==1)
    {
        int t=hash(q[0])%mod;
        for (int i=0;i<f[t].size();i++)
            if (get(f[t][i],q[0]))
                out.push_back(f[t][i]);
    }
    else if (q.size()==2)
    {
        memset(f1,0,sizeof(f1));
        int t=hash(q[1])%mod;
        for (int i=0;i<f[t].size();i++)
        {
            if (f1[f[t][i].first])
                continue;
            if (get(f[t][i],q[1]))
                f1[f[t][i].first]=true;
        }
        for (int i=1;i<=n;i++)
            if (!f1[i])
                for (int j=0;j<a[i].size();j++)
                    out.push_back(make_pair(i,j));
    }
    else if (q[1]=="OR")
    {
        int t=hash(q[0])%mod;
        for (int i=0;i<f[t].size();i++)
            if (get(f[t][i],q[0]))
                out.push_back(f[t][i]);
        t=hash(q[2])%mod;
        for (int i=0;i<f[t].size();i++)
            if (get(f[t][i],q[2]))
                out.push_back(f[t][i]);
    }
    else
    {
        vector <pair <int,int> > out1;
        memset(f1,0,sizeof(f1));
        int t=hash(q[0])%mod;
        for (int i=0;i<f[t].size();i++)
            if (get(f[t][i],q[0]))
            {
                f1[f[t][i].first]=true;
                out1.push_back(f[t][i]);
            }
        memset(f2,0,sizeof(f2));
        t=hash(q[2])%mod;
        for (int i=0;i<f[t].size();i++)
        {
            if (!f1[f[t][i].first])
                continue;
            if (get(f[t][i],q[2]))
            {
                f2[f[t][i].first]=true;
                out.push_back(f[t][i]);
            }
        }
        for (int i=0;i<out1.size();i++)
            if (f2[out1[i].first])
                out.push_back(out1[i]);
    }
}
void print()
{
    if (out.empty())
        printf("Sorry, I found nothing.\n");
    else
    {
        sort(out.begin(),out.end());
        out.erase(unique(out.begin(),out.end()),out.end());
        int now=0;
        for (int i=0;i<out.size();i++)
        {
            int x=out[i].first,y=out[i].second;
            if (x!=now && now!=0)
                printf("----------\n");
            printf("%s\n",a[x][y].c_str());
            now=x;
        }
    }
    printf("==========\n");
}
int main()
{
    c[0]=1;
    for (int i=1;i<26;i++)
        c[i]=c[i-1]*lq;
    scanf("%d",&n);
    gets(buf);
    for (int i=1;i<=n;i++)
        while (1)
        {
            gets(buf);
            string now=buf;
            if (now=="**********")
                break;
            a[i].push_back(now);
            string tmp;
            vector <string> qqqq;
            for (int j=0;j<now.size();j++)
            {
                if (!isalpha(now[j]))
                {
                    if (tmp!="")
                    {
                        for (int k=0;k<tmp.size();k++)
                            tmp[k]=tolower(tmp[k]);
                        ull x=hash(tmp);
                        qqqq.push_back(tmp);
                        f[x%mod].push_back(make_pair(i,a[i].size()-1));
                        tmp="";
                    }
                    continue;
                }
                tmp+=now[j];
            }
            if (tmp!="")
            {
                for (int j=0;j<tmp.size();j++)
                    tmp[j]=tolower(tmp[j]);
                ull x=hash(tmp);
                qqqq.push_back(tmp);
                f[x%mod].push_back(make_pair(i,a[i].size()-1));
            }
            b[i].push_back(qqqq);
        }
    int m;
    scanf("%d",&m);
    gets(buf);
    while (m--)
    {
        gets(buf);
        int len=strlen(buf);
        string tmp;
        q.clear();
        for (int i=0;i<len;i++)
        {
            if (!isalpha(buf[i]))
            {
                if (tmp!="")
                {
                    q.push_back(tmp);
                    tmp="";
                }
                continue;
            }
            tmp+=buf[i];
        }
        if (tmp!="");
            q.push_back(tmp);
        query();
        print();
    }
    return(0);
}

