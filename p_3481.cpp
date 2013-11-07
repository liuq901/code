#include <cstdio>
#include <cstdlib>
#include <utility>
#include <map>
using namespace std;
typedef map <int,int>::iterator type;
map <int,int> a;
int main()
{
   while (1)
   {
      int p;
      scanf("%d",&p);
      if (!p)
         break;
      if (p==1)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a.insert(make_pair(y,x));
      }
      else
      {
         if (a.empty())
         {
            printf("0\n");
            continue;
         }
         type k;
         if (p==2)
            k=a.end(),k--;
         else
            k=a.begin();
         printf("%d\n",k->second);
         a.erase(k);
      }
   }
   system("pause");
   return(0);
}
