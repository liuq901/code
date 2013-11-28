#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int c[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
struct state
{
    int x,y,z;
    state(){}
    state(int x,int y,int z):x(x),y(y),z(z){}
};
vector <int> X,Y,Z;
char f[110][110][110];
state a[60],b[60];
queue <state> q;
int getV(int x,int y,int z)
{
    return((X[x+1]-X[x])*(Y[y+1]-Y[y])*(Z[z+1]-Z[z]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        X.clear();
        Y.clear();
        Z.clear();
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x1,y1,z1,x2,y2,z2;
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            x2+=x1,y2+=y1,z2+=z1;
            a[i]=state(x1,y1,z1);
            b[i]=state(x2,y2,z2);
            X.push_back(x1),X.push_back(x2);
            Y.push_back(y1),Y.push_back(y2);
            Z.push_back(z1),Z.push_back(z2);
        }
        X.push_back(0),Y.push_back(0),Z.push_back(0);
        X.push_back(1010),Y.push_back(1010),Z.push_back(1010);
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        sort(Z.begin(),Z.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        Z.erase(unique(Z.begin(),Z.end()),Z.end());
        memset(f,0,sizeof(f));
        int V=0;
        for (int i=0;i<X.size()-1;i++)
            for (int j=0;j<Y.size()-1;j++)
                for (int k=0;k<Z.size()-1;k++)
                    V+=getV(i,j,k);
        for (int i=1;i<=n;i++)
        {
            a[i].x=lower_bound(X.begin(),X.end(),a[i].x)-X.begin();
            a[i].y=lower_bound(Y.begin(),Y.end(),a[i].y)-Y.begin();
            a[i].z=lower_bound(Z.begin(),Z.end(),a[i].z)-Z.begin();
            b[i].x=lower_bound(X.begin(),X.end(),b[i].x)-X.begin();
            b[i].y=lower_bound(Y.begin(),Y.end(),b[i].y)-Y.begin();
            b[i].z=lower_bound(Z.begin(),Z.end(),b[i].z)-Z.begin();
            for (int j=a[i].x;j<b[i].x;j++)
                for (int k=a[i].y;k<b[i].y;k++)
                    for (int p=a[i].z;p<b[i].z;p++)
                        f[j][k][p]=1;
        }
        f[0][0][0]=2;
        q.push(state(0,0,0));
        while (!q.empty())
        {
            int x0=q.front().x,y0=q.front().y,z0=q.front().z;
            V-=getV(x0,y0,z0);
            q.pop();
            for (int i=0;i<6;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1],z=z0+c[i][2];
                if (x>=0 && x<X.size()-1 && y>=0 && y<Y.size()-1 && z>=0 && z<Z.size()-1 && f[x][y][z]==0)
                {
                    f[x][y][z]=2;
                    q.push(state(x,y,z));
                }
            }
        }
        int S=0;
        for (int i=0;i<X.size()-1;i++)
            for (int j=0;j<Y.size()-1;j++)
                for (int k=0;k<Z.size()-1;k++)
                {
                    if (f[i][j][k]!=1)
                        continue;
                    for (int p=0;p<6;p++)
                    {
                        int x=i+c[p][0],y=j+c[p][1],z=k+c[p][2];
                        if (f[x][y][z]==2)
                        {
                            int t=getV(i,j,k);
                            if (x!=i)
                                t/=X[i+1]-X[i];
                            else if (y!=j)
                                t/=Y[j+1]-Y[j];
                            else
                                t/=Z[k+1]-Z[k];
                            S+=t;
                        }
                    }
                }
        printf("%d %d\n",S,V);
    }
    return(0);
}

