#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1010][110];
int a[1010];
inline bool less(char *a,char *b)
{
    if (a[0]=='-' && b[0]!='-')
        return(true);
    if (a[0]!='-' && b[0]=='-')
        return(false);
    if (a[0]=='-')
        return(less(b+1,a+1));
    int la=strlen(a),lb=strlen(b);
    return(la<lb || la==lb && strcmp(a,b)<0);
}
inline bool cmp(int x,int y)
{
    return(less(s[x],s[y]));
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s[i]);
            a[i]=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
            printf("%s\n",s[a[i]]);
    }
    return(0);
}

