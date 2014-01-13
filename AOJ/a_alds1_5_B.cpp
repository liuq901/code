#include <cstdio>
int ans,a[500010],b[500010],c[500010];
void sort(int l,int r)
{
    if (l==r)
        return;
    int mid=l+r>>1;
    sort(l,mid);
    sort(mid+1,r);
    int n1=0,n2=0;
    for (int i=l;i<=mid;i++)
        b[++n1]=a[i];
    for (int i=mid+1;i<=r;i++)
        c[++n2]=a[i];
    b[n1+1]=c[n2+1]=1<<30;
    int u=1,v=1,t=l;
    while (u<=n1 || v<=n2)
    {
        ans++;
        if (b[u]<c[v])
            a[t]=b[u++];
        else
            a[t]=c[v++];
        t++;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(1,n);
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    printf("%d\n",ans);
    return(0);
}

