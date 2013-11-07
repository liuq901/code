#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
char a[30],s[1010];
int c[30];
vector <char> b[30];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y] || a[x]==a[y] && x<y);
}
int main()
{
    gets(a);
    gets(s);
    int m=strlen(a),n=strlen(s),tot=-1,ma=0;
    for (int i=0;i<n;i++)
        if (s[i]!=' ')
        {
            tot=(tot+1)%m;
            b[tot].push_back(toupper(s[i]));
            ma=max(ma,int(b[tot].size()));
        }
    for (int i=0;i<m;i++)
    {
        c[i]=i;
        while (b[i].size()<ma)
            b[i].push_back('E');
    }
    sort(c,c+m,cmp);
    for (int i=0;i<m;i++)
        for (int j=0;j<ma;j++)
            printf("%c",b[c[i]][j]);
    printf("\n");
    return(0);
}

