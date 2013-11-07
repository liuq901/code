#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map <int,int> M1,M2;
vector <int> id,num;
int b[500010],a[500010][3];
inline int hash(map <int,int> &M,int x)
{
    if (!M.count(x))
    {
        int id=M.size();
        M[x]=id;
    }
    return(M[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x=hash(M1,x),y=hash(M2,y);
        a[i][0]=x,a[i][1]=z,a[i][2]=b[y],b[y]=i;
    }
    printf("-1");
    id.resize(M1.size());
    int tot=0;
    for (map <int,int>::iterator k=M1.begin();k!=M1.end();k++)
    {
        printf(" %d",k->first);
        id[tot++]=k->second;
    }
    printf("\n");
    for (map <int,int>::iterator k=M2.begin();k!=M2.end();k++)
    {
        printf("%d",k->first);
        int x=k->second;
        num.clear();
        num.resize(M1.size(),0);
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            num[y]+=a[i][1];
        }
        for (int i=0;i<num.size();i++)
            printf(" %d",num[id[i]]);
        printf("\n");
    }
    return(0);
}

