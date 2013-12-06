#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> a;
    map <int,int> b;
    int x,y;
    while (1)
    {
        scanf("%d,%d",&x,&y);
        y*=-1;
        if (x==0 && y==0)
            break;
        a.push_back(y);
        b[x]=y;
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int n;
    while (scanf("%d",&n)==1)
        printf("%d\n",lower_bound(a.begin(),a.end(),b[n])-a.begin()+1);
    return(0);
}

