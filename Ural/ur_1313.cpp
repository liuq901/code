#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct data
{
    int x,y,v;
    data(int x,int y,int v):x(x),y(y),v(v){}
};
bool operator <(data a,data b)
{
    if (a.x+a.y!=b.x+b.y)
        return(a.x+a.y<b.x+b.y);
    return(a.x>b.x);
}
int main()
{
    int n;
    scanf("%d",&n);
    vector <data> a;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(data(i,j,x));
        }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();i++)
        printf("%d%c",a[i].v,i==a.size()-1?'\n':' ');
    return(0);
}

