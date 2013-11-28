#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int inf=2147483647;
vector <int> X,Y;
struct point
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
        X.push_back(x);
        Y.push_back(y);
    }
};
int q[1000010][2],d[1010][1010],a[1010][1010][4];
bool vis[1010][1010];
point S,T,u[510],v[510];
inline int get(const vector <int> &a,int b)
{
    return(lower_bound(a.begin(),a.end(),b)-a.begin());
}
void spfa()
{
    for (int i=0;i<X.size();i++)
        for (int j=0;j<Y.size();j++)
            d[i][j]=inf;
    int Sx=get(X,S.x),Sy=get(Y,S.y),Tx=get(X,T.x),Ty=get(Y,T.y);
    d[Sx][Sy]=0;
    vis[Sx][Sy]=true;
    int l=0,r=1;
    q[1][0]=Sx,q[1][1]=Sy;
    while (l!=r)
    {
        l=l==1000005?1:l+1;
        int x0=q[l][0],y0=q[l][1];
        vis[x0][y0]=false;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>=0 && x<X.size() && y>=0 && y<Y.size() && d[x0][y0]+a[x0][y0][i]<d[x][y])
            {
                d[x][y]=d[x0][y0]+a[x0][y0][i];
                if (!vis[x][y])
                {
                    vis[x][y]=true;
                    r=r==1000005?1:r+1;
                    q[r][0]=x;
                    q[r][1]=y;
                    int k=l==1000005?1:l+1;
                    if (d[q[r][0]][q[r][1]]<d[q[k][0]][q[k][1]])
                        swap(q[r][0],q[k][0]),swap(q[r][1],q[k][1]);
                }
            }
        }
    }
    static int id=0;
    printf("City %d\nPeter has to cross %d streets\n",++id,d[Tx][Ty]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        X.clear();
        Y.clear();
        X.push_back(-inf);
        X.push_back(inf);
        Y.push_back(-inf);
        Y.push_back(inf);
        for (int i=1;i<=n;i++)
        {
            u[i].in();
            v[i].in();
        }
        S.in();
        T.in();
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        for (int i=0;i<=X.size();i++)
            for (int j=0;j<Y.size();j++)
                for (int k=0;k<4;k++)
                    a[i][j][k]=0;
        for (int i=1;i<=n;i++)
            if (u[i].x==v[i].x)
            {
                int t=get(X,u[i].x),l=get(Y,u[i].y),r=get(Y,v[i].y);
                if (l>r)
                    swap(l,r);
                for (int j=l;j<r;j++)
                    a[t-1][j][1]=a[t][j][0]=1;
            }
            else
            {
                int t=get(Y,u[i].y),l=get(X,u[i].x),r=get(X,v[i].x);
                if (l>r)
                    swap(l,r);
                for (int j=l;j<r;j++)
                    a[j][t-1][3]=a[j][t][2]=1;
            }
        spfa();
    }
    return(0);
}

