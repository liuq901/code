#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double real;
const real eps=1e-14;
struct point
{
   real x,y;
   point(){}
   point(real x,real y):x(x),y(y){}
};
struct seg
{
   point a,b;
   seg(){}
   seg(point a,point b):a(a),b(b){}
};
bool operator ==(const point a,const point b)
{
   return(fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);
}
bool operator <(const point a,const point b)
{
   if (a.x==b.x)
      return(a.y<b.y);
   return(a.x<b.x);
}
seg l1,l2,l3,l4;
point tt;
int main()
{
   real cross(point,point,point),probx(seg);
   point a[10];
   int n,i,x,y;
   real ans;
   l1=seg(point(0,0),point(1,0));
   l2=seg(point(1,0),point(1,1));
   l3=seg(point(1,1),point(0,1));
   l4=seg(point(0,1),point(0,0));
   ans=0;
   scanf("%d",&n);
   for (i=0;i<n;i++)
   {
      scanf("%d%d",&x,&y);
      a[i].x=x/100.0;
      a[i].y=y/100.0;
   }
   a[n]=a[0];
   for (i=0;i<n;i++)
      ans+=cross(point(0,0),a[i],a[i+1])+probx(seg(a[i],a[i+1]));
   printf("%.10lf\n",(double)ans/2);
   system("pause");
   return(0);
}
real probx(seg a)
{
   point getpoint(seg,seg);
   bool cmp(const point,const point);
   real cross(point,point,point),dis(point,point),proby(seg);
   point a1,a2;
   set <point> s;
   vector <point> v;
   set <point>::iterator it;
   s.clear();
   v.clear();
   s.insert(getpoint(l1,a));
   s.insert(getpoint(l2,a));
   s.insert(getpoint(l3,a));
   s.insert(getpoint(l4,a));
   for (it=s.begin();it!=s.end();it++)
      if (!(it->x<-eps || it->x>1+eps || it->y<-eps || it->y>1+eps))
         if (!(fabs(it->x-1)>eps && fabs(it->x)>eps && fabs(it->y-1)>eps && fabs(it->y)>eps))
            v.push_back(*it);
   a1=v[0];
   a2=v[1];
   s.clear();
   v.push_back(point(0,0));
   v.push_back(point(0,1));
   v.push_back(point(1,1));
   v.push_back(point(1,0));
   tt=point(0,0);
   sort(v.begin(),v.end(),cmp);
   int n,i,j,l1,l2;
   n=v.size();
   for (i=0;i<n;i++)
      v.push_back(v[i]);
   for (i=0;i<v.size();i++)
      if (v[i]==a1)
      {
         l1=i;
         break;
      }
   for (i=l1+1;i<v.size();i++)
      if (v[i]==a2)
      {
         l2=i;
         break;
      }
   real ret;
   ret=0;
   for (i=l1;i<l2;i++)
      ret+=cross(point(0,0),v[i],v[i+1]);
   ret+=cross(point(0,0),v[l2],v[l1]);
   ret=fabs(ret)/2;
   ret*=1-ret;
   ret*=2;
   if (dis(a1,a.a)<dis(a1,a.b))
      ret-=proby(seg(a1,a.a))+proby(seg(a2,a.b));
   else
      ret-=proby(seg(a1,a.b))+proby(seg(a2,a.a));
   return(ret);
}
bool cmp(const point a,const point b)
{
   real get(point);
   return(get(a)<get(b));
}
real get(point a)
{
   if (fabs(a.y)<eps)
   {
      if (a.x+eps<tt.x)
         return(4-tt.x+a.x);
      return(a.x-tt.x);
   }
   if (fabs(a.x-1)<eps)
      return(a.y+1-tt.x);
   if (fabs(a.y-1)<eps)
      return(1-a.x+2-tt.x);
   if (fabs(a.x)<eps)
      return(1-a.y+3-tt.x);
   return(-1);
}
real dis(point a,point b)
{
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
real proby(seg a)
{
   int getl(point,point);
   point getpoint(seg,seg);
   bool equ(point,point);
   real cross(point,point,point),getr(real,real,real,real);
   switch (getl(a.a,a.a))
   {
   case 0:
      break;
   case 1:
      tt=a.a;
      a.a.x=tt.y;
      a.a.y=1-tt.x;
      tt=a.b;
      a.b.x=tt.y;
      a.b.y=1-tt.x;
      break;
   case 2:
      tt=a.a;
      a.a.x=1-tt.x;
      a.a.y=1-tt.y;
      tt=a.b;
      a.b.x=1-tt.x;
      a.b.y=1-tt.y;
      break;
   case 3:
      tt=a.a;
      a.a.x=1-tt.y;
      a.a.y=tt.x;
      tt=a.b;
      a.b.x=1-tt.y;
      a.b.y=tt.x;
      break;
   }
   if (fabs(a.a.x-1)<eps)
      a.a.x=1;
   if (fabs(a.a.x)<eps)
      a.a.x=0;
   if (fabs(a.a.y-1)<eps)
      a.a.y=1;
   if (fabs(a.a.y)<eps)
      a.a.y=0;
   if (fabs(a.b.x-1)<eps)
      a.b.x=1;
   if (fabs(a.b.x)<eps)
      a.b.x=0;
   if (fabs(a.b.y-1)<eps)
      a.b.y=1;
   if (fabs(a.b.y)<eps)
      a.b.y=0;
   set <point> s;
   vector <point> v;
   tt=a.a;
   s.clear();
   v.clear();
   s.insert(getpoint(l1,a));
   s.insert(getpoint(l2,a));
   s.insert(getpoint(l3,a));
   s.insert(getpoint(l4,a));
   s.insert(getpoint(l1,seg(a.b,point(0,0))));
   s.insert(getpoint(l1,seg(a.b,point(1,0))));
   s.insert(getpoint(l1,seg(a.b,point(1,1))));
   s.insert(getpoint(l1,seg(a.b,point(0,1))));
   s.insert(getpoint(l2,seg(a.b,point(0,0))));
   s.insert(getpoint(l2,seg(a.b,point(1,0))));
   s.insert(getpoint(l2,seg(a.b,point(1,1))));
   s.insert(getpoint(l2,seg(a.b,point(0,1))));
   s.insert(getpoint(l3,seg(a.b,point(0,0))));
   s.insert(getpoint(l3,seg(a.b,point(1,0))));
   s.insert(getpoint(l3,seg(a.b,point(1,1))));
   s.insert(getpoint(l3,seg(a.b,point(0,1))));
   s.insert(getpoint(l4,seg(a.b,point(0,0))));
   s.insert(getpoint(l4,seg(a.b,point(1,0))));
   s.insert(getpoint(l4,seg(a.b,point(1,1))));
   s.insert(getpoint(l4,seg(a.b,point(0,1))));
   set <point>::iterator it;
   for (it=s.begin();it!=s.end();it++)
      if (!(it->x<-eps || it->x>1+eps || it->y<-eps || it->y>1+eps))
         if (!(fabs(it->x-1)>eps && fabs(it->x)>eps && fabs(it->y-1)>eps && fabs(it->y)>eps))
            v.push_back(*it);
   sort(v.begin(),v.end(),cmp);
   for (int i=1;i<v.size();i++)
      if (equ(v[i],v[i-1]))
      {
         for (int j=i;j+1<v.size();j++)
            v[j]=v[j+1];
         v.pop_back();
         i--;
      }
   if (equ(v[0],v[v.size()-1]))
      v.pop_back();
   int i,j,n;
   n=v.size()/2;
   v.push_back(v[0]);
   real ret=0;
   for (i=0;i<n;i++)
   {
      for (j=i+n+1;j<n*2;j++)
         ret+=0.25*fabs(cross(a.b,v[j],v[j+1])*cross(a.b,v[i],v[i+1]));
      int l1,l2;
      l1=getl(v[i],v[i+1]);
      l2=getl(v[i+n],v[i+n+1]);
      if (abs(l1-l2)==2)
         ret+=0.125*fabs(cross(a.b,v[i+n],v[i+n+1])*cross(a.b,v[i],v[i+1]));
      else if (l1==0 && l2==1)
      {
         ret+=0.25*fabs(cross(a.b,v[i+n],v[i+n+1])*cross(a.b,v[i],v[i+1]));
         ret-=getr(1-a.b.x,a.b.y,a.b.x-v[i].x,v[i+n+1].y-a.b.y);
      }
      else if (l1==0 && l2==3)
         ret+=getr(a.b.x,a.b.y,v[i+1].x-a.b.x,v[i+n].y-a.b.y);
      else if (l1==1 && l2==2)
      {
         ret+=0.25*fabs(cross(a.b,v[i+n],v[i+n+1])*cross(a.b,v[i],v[i+1]));
         ret-=getr(1-a.b.x,1-a.b.y,a.b.x-v[i+n+1].x,a.b.y-v[i].y);
      }
      else if (l1==2 && l2==3)
      {
         ret+=0.25*fabs(cross(a.b,v[i+n],v[i+n+1])*cross(a.b,v[i],v[i+1]));
         ret-=getr(a.b.x,1-a.b.y,v[i].x-a.b.x,a.b.y-v[i+n+1].y);
      }
      else if (l1==1 && l2==0)
         ret+=getr(1-a.b.x,a.b.y,a.b.x-v[i+n].x,v[i+1].y-a.b.y);
      else if (l1==3 && l2==0)
      {
         ret+=0.25*fabs(cross(a.b,v[i+n],v[i+n+1])*cross(a.b,v[i],v[i+1]));
         ret-=getr(a.b.x,a.b.y,v[i+n+1].x-a.b.x,v[i].y-a.b.y);
      }
   }
   s.clear();
   return(ret*2);
}
int getl(point a,point b)
{
   if (fabs(a.y)<eps && fabs(b.y)<eps)
      return(0);
   if (fabs(a.x-1)<eps && fabs(b.x-1)<eps)
      return(1);
   if (fabs(a.y-1)<eps && fabs(b.y-1)<eps)
      return(2);
   return(3);
}
point getpoint(seg a,seg b)
{
   real cross(point,point,point);
   real s1;
   real s2;
   s1=cross(a.a,a.b,b.a);
   s2=-cross(a.a,a.b,b.b);
   if (fabs(s1+s2)<eps)
      return(point(-1,-1));
   point ret;
   ret.x=b.a.x*s2/(s1+s2)+b.b.x*s1/(s1+s2);
   ret.y=b.a.y*s2/(s1+s2)+b.b.y*s1/(s1+s2);
   return(ret);
}
bool equ(point a,point b)
{
   return(fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);
}
real cross(point a,point b,point c)
{
   real det(real,real,real,real);
   return(det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y));
}
real det(real x1,real y1,real x2,real y2)
{
   return(x1*y2-x2*y1);
}
real getr(real a,real b,real c,real d)
{
   return(a*a*b*b/4.*(log(c*d/a/b)+a*b/c/d-1));
}
