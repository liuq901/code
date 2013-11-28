#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char a[30],b[1010];
int c[30];
vector <int> v[30];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y] || a[x]==a[y] && x<y);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a,b);
        int m=strlen(a),n=strlen(b);
        for (int i=0;i<m;i++)
        {
            c[i]=i;
            v[i].clear();
        }
        sort(c,c+m,cmp);
        int tot=0;
        for (int i=0;i<m;i++)
            for (int j=0;j<n/m;j++)
                v[c[i]].push_back(b[tot++]);
        for (int i=0;i<n/m;i++)
            for (int j=0;j<m;j++)
                printf("%c",v[j][i]);
        printf("\n");
    }
    return(0);
}

