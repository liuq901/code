#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const char c[4][10]={".#..#.###","###.#..#.","#..####..","..####..#"};
struct data
{
    int x,y,z;
    data(){}
    data(int x,int y,int z):x(x),y(y),z(z){}
};
queue <data> Q;
int ind,t[12],f[12][520][520];
bool vis[12][520][520];
inline bool get(int x,int y)
{
    return(!(y&t[x]));
}
vector <data> Now,p[12][520][520];
data O,pre[12][520][520];
void dfs(int id,int state,int up,int now,int pos,int value,int m)
{
    if (value>f[id+1][now][state])
    {
        f[id+1][now][state]=value;
        pre[id+1][now][state]=O;
        p[id+1][now][state]=Now;
        if (!vis[id+1][now][state])
        {
            vis[id+1][now][state]=true;
            Q.push(data(id+1,now,state));
        }
    }
    if (pos+2>=m)
        return;
    for (int i=pos;i<=m-3;i++)
    {
        if (get(i+1,state) && get(i+1,up) && get(i,now) && get(i+1,now) && get(i+2,now))
        {
            Now.push_back(data(id+1,i,0));
            dfs(id,state^t[i+1],up^t[i+1],now^t[i]^t[i+1]^t[i+2],i+1,value+1,m);
            Now.pop_back();
        }
        if (get(i+1,state) && get(i,up) && get(i+1,up) && get(i+2,up) && get(i+1,now))
        {
            Now.push_back(data(id+1,i,1));
            dfs(id,state^t[i+1],up^t[i]^t[i+1]^t[i+2],now^t[i+1],i+1,value+1,m);
            Now.pop_back();
        }
        if (get(i,state) && get(i+1,state) && get(i+2,state) && get(i,up) && get(i,now))
        {
            Now.push_back(data(id+1,i,2));
            dfs(id,state^t[i]^t[i+1]^t[i+2],up^t[i],now^t[i],i+1,value+1,m);
            Now.pop_back();
        }
        if (get(i,state) && get(i+1,state) && get(i+2,state) && get(i+2,up) && get(i+2,now))
        {
            Now.push_back(data(id+1,i,3));
            dfs(id,state^t[i]^t[i+1]^t[i+2],up^t[i+2],now^t[i+2],i+1,value+1,m);
            Now.pop_back();
        }
    }
}
char a[12][12];
void fill(data p)
{
    char ch='A'+ind;
    int t=0;
    for (int i=p.x-2;i<=p.x;i++)
        for (int j=p.y;j<=p.y+2;j++)
            if (c[p.z][t++]=='#')
                a[i][j]=ch;
    ind++;
}
void print(data now)
{
    if (now.x==0)
        return;
    int x=now.x,y=now.y,z=now.z;
    for (int i=0;i<p[x][y][z].size();i++)
        fill(p[x][y][z][i]);
    print(data(pre[x][y][z]));
}
int main()
{
    t[0]=1;
    for (int i=1;i<12;i++)
        t[i]=t[i-1]<<1;
    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,-1,sizeof(f));
    vis[0][t[m]-1][t[m]-1]=true;
    f[0][t[m]-1][t[m]-1]=0;
    Q.push(data(0,t[m]-1,t[m]-1));
    while (!Q.empty())
    {
        int x=Q.front().x,y=Q.front().y,z=Q.front().z;
        Q.pop();
        if (x<n)
        {
            O=data(x,y,z);
            dfs(x,y,z,0,0,f[x][y][z],m);
        }
    }
    int ans=0;
    data final;
    for (int i=0;i<t[m];i++)
        for (int j=0;j<t[m];j++)
            if (f[n][i][j]>ans)
            {
                ans=f[n][i][j];
                final=data(n,i,j);
            }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<m;j++)
            a[i][j]='.';
        a[i][m]='\0';
    }
    if (ans!=0)
        print(final);
    for (int i=1;i<=n;i++)
        printf("%s\n",a[i]);
    return(0);
}

