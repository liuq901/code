#include <cstdio>
#include <algorithm>
using namespace std;
int n,lca;
int LCA(int Xa,int Xb)
{
    for (int i=n-1;i>=0;i--)
        if ((Xa>>i&1)!=(Xb>>i&1))
            return(i+1);
    return(0);
}
int case1(int Xa,int Ya,int Xb,int Yb)
{
    int Ua=(Ya+1)/2,Ub=(Yb+1)/2;
    if (Ua>=lca || Ub>=lca)
        return(0);
    return(Ya-Ua+Yb-Ub+2*lca-Ua-Ub);
}
int case2(int Xa,int Ya,int Xb,int Yb)
{
    int Ua=(Ya+1)/2,Ub=(Yb+1)/2;
    if (Ua>=lca || Yb<lca || lca<Ub)
        return(0);
    int ret=Ya-Ua+lca-Ua;
    if (Yb==lca)
        return(ret);
    else
        return(ret+Yb-lca-2);
}
int case3(int Xa,int Ya,int Xb,int Yb)
{
    int Ua=(Ya+1)/2,Ub=(Yb+1)/2;
    if (Ya<lca || Yb<lca || lca<Ua || lca<Ub)
        return(0);
    return(Ya+Yb-2*lca);
}
int case4(int Xa,int Ya,int Xb,int Yb)
{
    if (lca==n)
        return(0);
    int Ua=(Ya+1)/2;
    if (Ua>=lca || Yb<=lca)
        return(0);
    return(Ya-Ua+lca-Ua+Yb-lca);
}
int case5(int Xa,int Ya,int Xb,int Yb)
{
    if (lca==n)
        return(0);
    int Ua=max((Ya+1)/2,lca+1);
    if (Ya<=lca || Yb<=lca || Ua>Yb)
        return(0);
    int ret=Ya-Ua+Yb-Ua;
    if (Ua==n && Yb!=n)
        return(ret-2);
    return(ret);
}
int case6(int Xa,int Ya,int Xb,int Yb)
{
    if (lca==n)
        return(0);
    int Ua=(Ya+1)/2;
    if (Ya<lca || Yb<=lca || lca<Ua)
        return(0);
    return(Ya-lca+Yb-lca);
}
int calc(int Xa,int Ya,int Xb,int Yb)
{
    lca=LCA(Xa,Xb);
    int ans=0;
    ans=max(case1(Xa,Ya,Xb,Yb),max(case2(Xa,Ya,Xb,Yb),case2(Xb,Yb,Xa,Ya)));
    ans=max(max(ans,case3(Xa,Ya,Xb,Yb)),max(case4(Xa,Ya,Xb,Yb),case4(Xb,Yb,Xa,Ya)));
    ans=max(ans,max(case5(Xa,Ya,Xb,Yb),case5(Xb,Yb,Xa,Ya)));
    ans=max(ans,max(case6(Xa,Ya,Xb,Yb),case6(Xb,Yb,Xa,Ya)));
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Ya,Yb,Xa,Xb,limit;
        scanf("%d%d%d%d%d%d",&n,&Xa,&Ya,&Xb,&Yb,&limit);
        n--;
        printf("%s\n",calc(Xa-1,Ya,Xb-1,Yb)<=limit?"NO":"YES");
    }
    return(0);
}

