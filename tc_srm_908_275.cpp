#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int tot,d[50010],b[50010],a[100010][2];
bool in[50010];
struct TheTree
{
    int m;
    void add(int x,int y)
    {
        a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
        a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
    }
    int maximumDiameter(vector <int> cnt)
    {
        tot=0;
        vector <int> now;
        now.push_back(1);
        m=1;
        for (int i=0;i<cnt.size();i++)
        {
            vector <int> tmp;
            for (int j=0;j<cnt[i];j++)
            {
                add(now[j%now.size()],++m);
                tmp.push_back(m);
            }
            now=tmp;
        }
        return(calc());
    }
    void bfs(int S)
    {
        queue <int> Q;
        memset(in,0,sizeof(in));
        in[S]=true;
        Q.push(S);
        d[S]=0;
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (!in[y])
                {
                    in[y]=true;
                    d[y]=d[x]+1;
                    Q.push(y);
                }
            }
        }
    }
    int calc()
    {
        bfs(1);
        int k=max_element(d+1,d+m+1)-d;
        bfs(k);
        return(*max_element(d+1,d+m+1));
    }
};
int main(){}

