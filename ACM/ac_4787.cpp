#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=2010,c[2][2]={{-1,0},{0,-1}};
int wallX[N][2],wallY[N][2];
vector <int> X,Y;
queue <pair <int,int> > Q;
bool mark[N][N];
ll a[N][N];
int main()
{
    while (1)
    {
        int n,m,W;
        scanf("%d%d%d",&m,&n,&W);
        if (m==0 && n==0 && W==0)
            break;
        X.clear();
        Y.clear();
        ll ans=ll(n)*m;
        for (int i=1;i<=W;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            X.push_back(x1-1);
            X.push_back(x2);
            Y.push_back(y1-1);
            Y.push_back(y2);
            wallX[i][0]=x1-1;
            wallX[i][1]=x2;
            wallY[i][0]=y1-1;
            wallY[i][1]=y2;
            ans-=ll(x2-x1+1)*(y2-y1+1);
        }
        X.push_back(-1);
        X.push_back(n-1);
        Y.push_back(-1);
        Y.push_back(m-1);
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        for (int i=1;i<X.size();i++)
            for (int j=1;j<Y.size();j++)
                a[i][j]=ll(X[i]-X[i-1])*(Y[j]-Y[j-1]);
        memset(mark,0,sizeof(mark));
        for (int i=1;i<=W;i++)
        {
            int x0=lower_bound(X.begin(),X.end(),wallX[i][0])-X.begin();
            int x1=lower_bound(X.begin(),X.end(),wallX[i][1])-X.begin();
            int y0=lower_bound(Y.begin(),Y.end(),wallY[i][0])-Y.begin();
            int y1=lower_bound(Y.begin(),Y.end(),wallY[i][1])-Y.begin();
            for (int j=x0+1;j<=x1;j++)
                for (int k=y0+1;k<=y1;k++)
                    mark[j][k]=true;
        }
        if (!mark[X.size()-1][Y.size()-1])
        {
            mark[X.size()-1][Y.size()-1]=true;
            Q.push(make_pair(X.size()-1,Y.size()-1));
            ans-=a[X.size()-1][Y.size()-1];
        }
        while (!Q.empty())
        {
            int x0=Q.front().first,y0=Q.front().second;
            Q.pop();
            for (int i=0;i<2;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x>0 && y>0 && !mark[x][y])
                {
                    mark[x][y]=true;
                    ans-=a[x][y];
                    Q.push(make_pair(x,y));
                }
            }
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

