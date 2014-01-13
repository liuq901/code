#include <cstdio>
#include <vector>
using namespace std;
int dep[100010],fa[100010];
vector <int> son[100010];
void dfs(int x)
{
    for (int i=0;i<son[x].size();i++)
    {
        int y=son[x][i];
        dep[y]=dep[x]+1;
        dfs(y);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int id;
        scanf("%d",&id);
        id++;
        int K;
        scanf("%d",&K);
        son[id].resize(K);
        for (int j=0;j<K;j++)
        {
            int x;
            scanf("%d",&x);
            x++;
            fa[x]=id;
            son[id][j]=x;
        }
    }
    int root;
    for (int i=1;i<=n;i++)
        if (fa[i]==0)
        {
            root=i;
            break;
        }
    dfs(root);
    for (int i=1;i<=n;i++)
    {
        printf("node %d: parent = %d, depth = %d, ",i-1,fa[i]-1,dep[i]);
        if (root==i)
            printf("root");
        else if (son[i].empty())
            printf("leaf");
        else
            printf("internal node");
        printf(", [");
        for (int j=0;j<son[i].size();j++)
        {
            if (j)
                printf(", ");
            printf("%d",son[i][j]-1);
        }
        printf("]\n");
    }
    return(0);
}

