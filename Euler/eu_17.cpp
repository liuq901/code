#include <cstdio>
#include <cstdlib>
const int a[]={0,3,3,5,4,4,3,5,5,4};
const int b[]={0,0,6,6,5,5,5,7,6,6};
const int c[]={3,6,6,8,8,7,7,9,8,8};
int main()
{
   int ans=11;
   for (int i=1;i<1000;i++)
   {
      int x=i/100,y=i/10%10,z=i%10;
      if (x>0)
         ans+=a[x]+(y+z?3:0)+7;
      if (y>=2)
         ans+=b[y]+a[z];
      else if (y==1)
         ans+=c[z];
      else
         ans+=a[z];
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
