#include <cstdio>
#include <set>
#include <queue>
#include <utility>
using namespace std;
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
queue <pair <pair <int,int>,int> > Q;
set <pair <int,int> > s;
int main()
{
    int Sx,Sy,Tx,Ty;
    scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int r,x,y;
        scanf("%d%d%d",&r,&x,&y);
        for (int j=x;j<=y;j++)
            s.insert(make_pair(r,j));
    }
    Q.push(make_pair(make_pair(Sx,Sy),0));
    while (!Q.empty())
    {
        int x0=Q.front().first.first,y0=Q.front().first.second,dep=Q.front().second;
        Q.pop();
        for (int i=0;i<8;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (s.count(make_pair(x,y)))
            {
                s.erase(make_pair(x,y));
                if (x==Tx && y==Ty)
                {
                    printf("%d\n",dep+1);
                    goto out;
                }
                Q.push(make_pair(make_pair(x,y),dep+1));
            }
        }
    }
    printf("-1\n");
out:
    return(0);
}

