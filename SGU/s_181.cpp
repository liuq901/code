#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int x,i,s,alpha,beta,gamma,m,k;
   int a[1001],f[1001];
   scanf("%d%d%d%d%d%d",&a[0],&alpha,&beta,&gamma,&m,&k);
   if (k==0)
      printf("%d\n",a[0]);
   else
   {
      memset(f,-1,sizeof(f));
      a[0]%=m;
      f[a[0]]=0;
      s=0;
      while (1)
      {
         s++;
         a[s]=a[s-1]*a[s-1]*alpha+a[s-1]*beta+gamma;
         a[s]%=m;
         if (f[a[s]]!=-1)
            break;
         f[a[s]]=s;
      }
      x=s-f[a[s]];
      if (k<f[a[s]])
         printf("%d\n",a[k]);
      else
         printf("%d\n",a[(k-f[a[s]])%x+f[a[s]]]);
   }
   system("pause");
   return(0);
}
