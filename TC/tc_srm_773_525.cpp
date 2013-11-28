#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Rumor
{
    bool f[20],g[20];
    int state,n;
    vector <string> a;
    string p;
    int getMinimum(string knowledge,vector <string> graph)
    {
        n=knowledge.size();
        int limit=1<<n,ans=1<<30;
        a=graph;
        p=knowledge;
        for (int i=0;i<limit;i++)
        {
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            state=i;
            ans=min(ans,calc());
        }
        if (ans==1<<30)
            ans=-1;
        return(ans);
    }
    int calc()
    {
        vector <int> s[20],t[20];
        for (int i=0;i<n;i++)
            if (p[i]=='Y')
            {
                s[i].push_back(0);
                s[i].push_back(1);
                if (state>>i&1)
                    swap(s[i][0],s[i][1]);
                f[i]=g[i]=true;
            }
        for (int T=0;;T++)
        {
            bool flag=true;
            for (int i=0;i<n;i++)
                if (!f[i] || !g[i])
                {
                    flag=false;
                    break;
                }
            if (flag)
                return(T);
            for (int i=0;i<n;i++)
                if (!s[i].empty())
                {
                    flag=true;
                    int x=s[i][0];
                    for (int j=0;j<n;j++)
                        if (a[i][j]=='Y')
                        {
                            if (x==0 && !f[j])
                            {
                                f[j]=true;
                                t[j].push_back(0);
                            }
                            if (x==1 && !g[j])
                            {
                                g[j]=true;
                                t[j].push_back(1);
                            }
                        }
                    s[i].erase(s[i].begin());
                }
            if (!flag)
                return(1<<30);
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<t[i].size();j++)
                    s[i].push_back(t[i][j]);
                t[i].clear();
            }
            for (int i=0;i<n;i++)
                if (s[i].size()==2)
                {
                    s[i][0]=0,s[i][1]=1;
                    if (state>>i&1)
                        swap(s[i][0],s[i][1]);
                }
        }
    }
};
int main(){}

