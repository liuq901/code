#include <cstdio>
#include <string>
#include <vector>
#include <utility>
using namespace std;
char a[100][100];
int n,m;
string ans,tmp;
vector <pair <int,int> > b;
void dfs(int cD,int cR,int dep)
{
    for (int i=0;i<b.size();i++)
    {
        int x=b[i].first,y=b[i].second;
        if (x<=n && y<=m && a[x][y]=='X')
            return;
    }
    if (!cD && !cR)
    {
        if (ans=="" || tmp<ans)
            ans=tmp;
        return;
    }
    if (cD)
    {
        tmp[dep]='D';
        for (int i=0;i<b.size();i++)
            b[i].first++;
        dfs(cD-1,cR,dep+1);
        for (int i=0;i<b.size();i++)
            b[i].first--;
    }
    if (cR)
    {
        tmp[dep]='R';
        for (int i=0;i<b.size();i++)
            b[i].second++;
        dfs(cD,cR-1,dep+1);
        for (int i=0;i<b.size();i++)
            b[i].second--;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int mi,ma;
        scanf("%d%d%d%d",&n,&m,&mi,&ma);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        ans="";
        for (int len=mi;len<=ma;len++)
        {
            tmp.resize(len);
            for (int i=0;i<=len;i++)
            {
                int j=len-i;
                b.clear();
                int x=1,y=1;
                while (1)
                {
                    b.push_back(make_pair(x,y));
                    x+=i,y+=j;
                    if (x>n || y>m)
                        break;
                }
                dfs(i,j,0);
            }
            if (ans!="")
                break;
        }
        printf("%s\n",ans.c_str());
    }
    return(0);
}

