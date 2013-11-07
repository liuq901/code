#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y,z;
    point():x(0),y(0),z(0){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double length() const
    {
        return(sqrt(x*x+y*y+z*z));
    }
    double dot(const point &p) const
    {
        return(x*p.x+y*p.y+z*p.z);
    }
    point cross(const point &p) const
    {
        return(point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b,a.z/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && (sign(a.y-b.y)<0 || sign(a.y-b.y)==0 && sign(a.z-b.z)<0));
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0 && sign(a.z-b.z)==0);
}
int n,cnt,mark[110][110];
point info[110];
inline double mix(const point &a,const point &b,const point &c)
{
    return(a.dot(b.cross(c)));
}
inline double area(int a,int b,int c)
{
    return((info[b]-info[a]).cross(info[c]-info[a]).length());
}
inline double volume(int a,int b,int c,int d)
{
    return(mix(info[b]-info[a],info[c]-info[a],info[d]-info[a]));
}
struct Face
{
    int a,b,c;
    Face(int a,int b,int c):a(a),b(b),c(c){}
    int &operator [](int k)
    {
        if (k==0)
            return(a);
        if (k==1)
            return(b);
        return(c);
    }
};
vector <Face> face;
inline void insert(int a,int b,int c)
{
    face.push_back(Face(a,b,c));
}
void add(int v)
{
    vector <Face> tmp;
    int a,b,c;
    cnt++;
    for (int i=0;i<face.size();i++)
    {
        a=face[i][0];
        b=face[i][1];
        c=face[i][2];
        if (sign(volume(v,a,b,c))<0)
            mark[a][b]=mark[b][a]=mark[b][c]=mark[c][b]=mark[c][a]=mark[a][c]=cnt;
        else
            tmp.push_back(face[i]);
    }
    face=tmp;
    for (int i=0;i<tmp.size();i++)
    {
        a=face[i][0];
        b=face[i][1];
        c=face[i][2];
        if (mark[a][b]==cnt)
            insert(b,a,v);
        if (mark[b][c]==cnt)
            insert(c,b,v);
        if (mark[c][a]==cnt)
            insert(a,c,v);
    }
}
bool Find()
{
    for (int i=2;i<n;i++)
    {
        point ndir=(info[0]-info[i]).cross(info[1]-info[i]);
        if (ndir==point())
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
double calcDist(const point &p,int a,int b,int c)
{
    return(fabs(mix(info[a]-p,info[b]-p,info[c]-p)/area(a,b,c)));
}
double findDist()
{
    double totalWeight=0;
    point center(0,0,0);
    point first=info[face[0][0]];
    for (int i=0;i<face.size();i++)
    {
        point p=(info[face[i][0]]+info[face[i][1]]+info[face[i][2]]+first)*0.25;
        double weight=mix(info[face[i][0]]-first,info[face[i][1]]-first,info[face[i][2]]-first);
        totalWeight+=weight;
        center=center+p*weight;
    }
    center=center/totalWeight;
    double res=1e100;
    for (int i=0;i<face.size();i++)
        res=min(res,calcDist(center,face[i][0],face[i][1],face[i][2]));
    return(res);
}
double work()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        info[i].in();
    sort(info,info+n);
    n=unique(info,info+n)-info;
    face.clear();
    random_shuffle(info,info+n);
    if (Find())
    {
        memset(mark,0,sizeof(mark));
        cnt=0;
        for (int i=3;i<n;i++)
            add(i);
    }
    return(findDist());
}
int main()
{
    printf("%.10f\n",work()+work());
    return(0);
}

