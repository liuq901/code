#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <complex>
using namespace std;
typedef complex <int> data;
struct check
{
   data base;
   check(data base):base(base){}
   bool operator ()(pair <data,int> a,pair <data,int> b)
   {
      data x=a.first-base;
      data y=b.first-base;
      if (x.imag()<0 || x.imag()==0 && x.real()<0) 
         x=-x;
      if (y.imag()<0 || y.imag()==0 && y.real()<0) 
         y=-y;
      return(imag(conj(x)*y)>0);
   }
};
int main()
{
   bool compare(data,data);
   int n;
   scanf("%d",&n);
   data a[n];
   for (int i=0;i<n;i++)
      scanf("%d%d",&a[i].real(),&a[i].imag());
   sort(a,a+n,compare);
   int b[n],c[n][n];
   memset(c,-1,sizeof(c));
   for (int i=0;i<n;i++)
   {
      int s=-1;
      pair <data,int> f[n];
      for (int j=0;j<n;j++)
         if (i!=j)
         {
            s++;
            f[s]=make_pair(a[j],j);
         }
      sort(f,f+s+1,check(a[i]));
      for (int j=1;j<n-1;j++)
         c[i][f[j].second]=f[j-1].second;
      c[i][f[0].second]=f[s].second;
      b[i]=f[s].second;
   }
   int ans=0;
   int f[n][n];
   for (int j=0;j<n;j++)
   {
      bool red[n];  
      fill(red,red+n,false);
      int k=b[j];
      while (1)
      {
         if (k>j)
         {
            int best=2;
            int i=j;
            while (1)
            {
               i=c[k][i];
               if (i>=j)
               {
                  if (red[i])
                     best=max(best,f[i][k]+1);
                  else
                     f[k][i]=best;
               }
               if (i==j)
                  break;
            }
            red[k]=true;
            ans=max(ans,f[k][j]);
         }
         k=c[j][k];
         if (k==b[j])
            break;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool compare(data a,data b)
{
   if (a.imag()!=b.imag())
      return(a.imag()<b.imag());
   return(a.real()<b.real());
}
