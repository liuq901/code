#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char a[10];
bool vis[10];
void dfs(int x,int now)
{
    if (x==-1)
    {
        printf("print(");
        for (int i=1;i<=n;i++)
            printf("%c%c",a[i],i==n?')':',');
        printf(";\n");
        return;
    }
    if (now==n+1 || vis[now])
    {
        vis[x]=true;
        int k=-1;
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                k=i;
                break;
            }
        dfs(k,k+1);
        vis[x]=false;
        return;
    }
    printf("if (%c<%c)\n",a[x],a[now]);
    dfs(x,now+1);
    printf("else\n");
    swap(a[x+1],a[now]);
    swap(a[x],a[x+1]);
    dfs(x+1,now+1);
    swap(a[x],a[x+1]);
    swap(a[x+1],a[now]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        static int id=0;
        printf("Case %d:\n",++id);
        printf("void print(");
        for (int i=1;i<=n;i++)
            printf("int %c%c",i+'a'-1,i==n?')':',');
        printf("{\nprintf(\"");
        for (int i=1;i<n;i++)
            printf("%%d ");
        printf("%%d\\n\"");
        for (int i=1;i<=n;i++)
            printf(",%c",i+'a'-1);
        printf(");\n}\nvoid sort(");
        for (int i=1;i<=n;i++)
            printf("int %c%c",i+'a'-1,i==n?')':',');        
        printf("{\n");
        for (int i=1;i<=n;i++)
            a[i]=i+'a'-1;
        dfs(1,2);
        printf("}\n");
    }
    return(0);
}

