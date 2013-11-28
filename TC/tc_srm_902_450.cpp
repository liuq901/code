#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct state
{
    int red,green,white;
    state(){}
    state(int x,int y,int z):red(x),green(y),white(z){}
    int sum()
    {
        return(red+green+white);
    }
};
inline bool operator <(const state &a,const state &b)
{
    return(a.white<b.white);
}
state f[4100][140];
queue <pair <int,int> > Q;
bool in[4100][140];
struct KeyDungeonDiv1
{
    int maxKeys(vector <int> doorR,vector <int> doorG,vector <int> roomR,vector <int> roomG,vector <int> roomW,vector <int> keys)
    {
        int n=doorR.size(),limit=1<<n;
        for (int i=0;i<limit;i++)
            for (int j=0;j<=130;j++)
                f[i][j]=state(0,0,-1);
        state S(keys[0],keys[1],keys[2]);
        Q.push(make_pair(0,keys[0]));
        in[0][keys[0]]=true;
        f[0][keys[0]]=S;
        int ans=0;
        while (!Q.empty())
        {
            int x=Q.front().first,x0=Q.front().second;
            state now=f[x][x0];
            in[x][x0]=false;
            Q.pop();
            ans=max(ans,now.sum());
            for (int i=0;i<n;i++)
            {
                if (x>>i&1)
                    continue;
                int R=min(doorR[i],now.red),G=min(doorG[i],now.green);
                int need=doorR[i]-R+doorG[i]-G;
                if (need>now.white)
                    continue;
                state here(now.red-R+roomR[i],now.green-G+roomG[i],now.white-need+roomW[i]);
                int y=x|1<<i,y0=here.red;
                if (f[y][y0]<here)
                {
                    f[y][y0]=here;
                    if (!in[y][y0])
                    {
                        in[y][y0]=true;
                        Q.push(make_pair(y,y0));
                    }
                }
            }
        }
        return(ans);
    }
};
int main(){}

