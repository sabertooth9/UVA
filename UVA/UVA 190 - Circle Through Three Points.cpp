#include<bits/stdc++.h>
using namespace std;


/*--Policy Based Data Structure--*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo         find_by_order //index wise op
#define ook         order_of_key  //number of elements less than key


typedef long long ll;
typedef unsigned long long ull;
#define PI              acos(-1.0)
#define eps             1e-5
#define inf             0x3f3f3f3f

#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)

#define max_ull         18446744073709551615
#define max_ll          9223372036854775807

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2

#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define first_1(x)      __builtin_ffs(x)
#define log2_(x)        __builtin_clz(1) - __builtin_clz(x);
#define isPowerOfTwo(x) (x!=0 && (x&(x-1))==0)
#define isLeap(x)       ((x%400==0) || (x%100?x%4==0:false))

#define set(N,cur)      N=(N|(1<<cur))
#define reset(N,cur)    N=(N&(~(1<<cur)))
#define check(N,cur)    ((N&(1<<cur))==0)

#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define rep(i,begin,end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

/*-----STL------*/
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define ii              int,int
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define pii             pair<ii>
#define ff              first
#define ss              second
#define Iterator(a)     __typeof__(a.begin())
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back

template<typename T>
using dijkstra=priority_queue<T,vector<T>,greater<T> >;

/*____Debug____*/
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

#define what_is(x)      cerr << #x << " is " << x << endl;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};   */// 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};*/
typedef pair<double,double> point;
double distance_(point A,point B)
{
    return (A.ff-B.ff)*(A.ff-B.ff)+(A.ss-B.ss)*(A.ss-B.ss);
}
double area_traingle(point A,point B,point C)
{
    return fabs((C.ss-A.ss)*(B.ff-A.ff)-(B.ss-A.ss)*(C.ff-A.ff));
}
istream& operator >> (istream&sin,point&px)
{
    sin>>px.ff>>px.ss;
    return sin;
}
ostream& operator << (ostream&sin,point px)
{
    sin<<px.ff<<" "<<px.ss;
    return sin;
}
class rectangle
{
public:
    point a,b,c,d;
    rectangle() {}
    rectangle(point a,point c)
    {
        this->a=a;
        this->c=c;
        this->b=MP(c.ff,a.ss);
        this->d=MP(a.ff,c.ss);
    }
    friend bool intersect(rectangle A,rectangle B,rectangle &C)
    {
        double leftX=max(A.a.ff,B.a.ff);
        double rightX=min(A.b.ff,B.b.ff);
        double topY=max(A.a.ss,B.a.ss);
        double bottomY=min(A.c.ss,B.c.ss);
        if(leftX<rightX and topY<bottomY)
        {
            C=rectangle(MP(leftX,topY),MP(rightX,bottomY));
            return true;
        }
        return false;
    }
    friend istream& operator>>(istream &sin,rectangle &x)
    {
        sin>>x.a;
        sin>>x.c;
        x.b=MP(x.c.ff,x.a.ss);
        x.d=MP(x.a.ff,x.c.ss);
        return sin;
    }
};
class circle
{
public:
    point centre;
    double r,g,f,mc;
    circle() {}
    circle(point centre,double r)
    {
        this->centre=centre;
        this->r=r;
    }
    /*
    Circle that intersects 3 given points
    ((x-x1)*(x-x2)+(y-y1)*(y-y2))/((x-x1)*(y1-y2)-(y-y1)*(x1-x2))=((x3-x1)*(x3-x2)+(y3-y1)*(y3-y2))/((x3-x1)*(y1-y2)-(y3-y1)*(x1-x2))
    */
    circle(point a,point b,point c)
    {
        double x1=a.ff,x2=b.ff,x3=c.ff,y1=a.ss,y2=b.ss,y3=c.ss;
        double C=((x3-x1)*(x3-x2)+(y3-y1)*(y3-y2))/((x3-x1)*(y1-y2)-(y3-y1)*(x1-x2));
        g=-0.5*(x1+x2+C*(y1-y2));
        f=-0.5*(y1+y2-C*(x1-x2));
        mc=x1*x2+y1*y2+C*x1*(y1-y2)-C*y1*(x1-x2);
        centre=MP(-1.0*g,-1.0*f);
        r=sqrtl(g*g+f*f-mc);
    }
    double getArea()
    {
        return PI*r*r;
    }
    double getCircumference()
    {
        return 2.0*PI*r;
    }
    void print_equ()
    {
        cout<<fixed<<setprecision(3);
        cout<<"(x ";
        if(centre.ff<0.0)cout<<"+ ";
        else cout<<"- ";
        cout<<fabs(centre.ff)<<")^2 + (y ";

        if(centre.ss<0.0)cout<<"+ ";
        else cout<<"- ";
        cout<<fabs(centre.ss)<<")^2 = "<<r<<"^2"<<endl;

        cout<<"x^2 + y^2 ";
        double tmp=2.0*g;
        if(tmp<0.0)cout<<"- "<<fabs(tmp)<<"x ";
        else cout<<"+ "<<tmp<<"x ";
        tmp=2.0*f;
        if(tmp<0.0)cout<<"- "<<fabs(tmp)<<"y ";
        else cout<<"+ "<<tmp<<"y ";
        if(mc<0.0)cout<<"- "<<fabs(mc)<<" = 0\n";
        else cout<<"+ "<<mc<<" = 0\n";
        puts("");
    }
};
int main()
{
    point a,b,c;
    while(cin>>a>>b>>c){
      //  if(f)puts("");
       // f=1;
        circle C(a,b,c);
        C.print_equ();
    }
}
