#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1010;
const double eps=1e-8;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double dot(const point &b) const
    {
        return(x*b.x+y*b.y+z*b.z);
    }
    point det(const point &b) const
    {
        return(point(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x));
    }
    double len() const
    {
        return(sqrt(x*x+y*y+z*z));
    }
};
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)!=0)
        return(a.x<b.x);
    if (sign(a.y-b.y)!=0)
        return(a.y<b.y);
    return(a.z<b.z);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0 && sign(a.z-b.z)==0);
}
inline double mix(const point &a,const point &b,const point &c)
{
    return(a.dot(b.det(c)));
}
point info[N];
inline double area(int a,int b,int c)
{
    return((info[b]-info[a]).det(info[c]-info[a]).len());
}
inline double volume(int a,int b,int c,int d)
{
    return(mix(info[b]-info[a],info[c]-info[a],info[d]-info[a]));
}
struct facet
{
    int a,b,c;
    facet(){}
    facet(int a,int b,int c):a(a),b(b),c(c){}
    int &operator [](int k)
    {
        return(k==0?a:k==1?b:c);
    }
};
int n,cnt,mark[N][N];
vector <facet> face;
inline void insert(int a,int b,int c)
{
    face.push_back(facet(a,b,c));
}
bool Find()
{
    for (int i=2;i<n;i++)
    {
        point ndir=(info[0]-info[i]).det(info[1]-info[i]);
        if (ndir==point(0,0,0))
            continue;
        swap(info[i],info[2]);
        for (int j=i+1;j<n;j++)
            if (sign(volume(0,1,2,j))!=0)
            {
                swap(info[j],info[3]);
                insert(0,1,2);
                insert(0,2,1);
                return(true);
            }
    }
    return(false);
}
void add(int v)
{
    vector <facet> tmp;
    int a,b,c;
    cnt++;
    for (int i=0;i<face.size();i++)
    {
        a=face[i][0],b=face[i][1],c=face[i][2];
        if (sign(volume(v,a,b,c))<0)
        {
            mark[a][b]=mark[b][a]=mark[b][c]=cnt;
            mark[c][b]=mark[c][a]=mark[a][c]=cnt;
        }
        else
            tmp.push_back(face[i]);
    }
    face=tmp;
    for (int i=0;i<tmp.size();i++)
    {
        a=face[i][0],b=face[i][1],c=face[i][2];
        if (mark[a][b]==cnt)
            insert(b,a,v);
        if (mark[b][c]==cnt)
            insert(c,b,v);
        if (mark[c][a]==cnt)
            insert(a,c,v);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            info[i].in();
        sort(info,info+n);
        n=unique(info,info+n)-info;
        face.clear();
        random_shuffle(info,info+n);
        double Ans_volume=0,Ans_surface=0;
        if (Find())
        {
            memset(mark,0,sizeof(mark));
            cnt=0;
            for (int i=3;i<n;i++)
                add(i);
            int first=face[0][0];
            for (int i=0;i<face.size();i++)
            {
                Ans_surface+=area(face[i][0],face[i][1],face[i][2]);
                Ans_volume+=fabs(volume(first,face[i][0],face[i][1],face[i][2]));
            }
            Ans_volume/=6;
            Ans_surface/=2;
        }
        printf("%.4f %.4f\n",Ans_surface,Ans_volume);
    }
    return(0);
}

