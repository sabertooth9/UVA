#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag,
      tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order // k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define max_ull 18446744073709551615
#define max_ll 9223372036854775807
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctzll(x)
#define total_1s(x) __builtin_popcountll(x)
#define first_1(x) __builtin_ffsll(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define QUERY           \
    int test;           \
    scanf("%d", &test); \
    for (int _T = 1; _T <= test; _T++)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull,ull>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define SEGMENT_TREE int mid=(st+en)/2,lt=node*2,rg=lt+1
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const pair<T1, T2>& ps) {
    fout << ps.ff << " " << ps.ss;
    return fout;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const map<T1, T2>& mp) {
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const ordered_set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */ // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */ // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */ // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */ // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
int n,m;
vector<int>edge[109];
int grid[109][109];
vector<string>input[30];
int par[109];
int mini[109];
int supersource=0,supersink=1;
void clear() {
    for(int i=0; i<109; i++)
        edge[i].clear();
    for(int i=0; i<30; i++)
        input[i].clear();
    memset(grid,0,sizeof grid);
    memset(par,-1,sizeof par);
    memset(mini,inf,sizeof mini);
}
int bfs() {
    memset(par,-1,sizeof par);
    memset(mini,inf,sizeof mini);
    queue<int>q;
    int p;
    q.push(supersource);
    par[supersource]=supersource;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==supersink){
            return mini[t];
        }
        for(int i=0;i<edge[t].size();i++){
            p=edge[t][i];
            if(par[p]==-1 && grid[t][p]>0){
                par[p]=t;
                mini[p]=min(mini[p],grid[t][p]);
                q.push(p);
            }
        }
    }
    return 0;
}
void update_path(int now,int cc){
    if(now==-1 || par[now]==now)return;
    grid[par[now]][now]-=cc;
    grid[now][par[now]]+=cc;
    update_path(par[now],cc);
}
int maxflow() {
    int ans=0;
    int mf=bfs();
    while(mf>0){
        update_path(supersink,mf);
        ans+=mf;
        mf=bfs();
    }
    return ans;
}
void print_str(string s) {
    printf("%c",toupper(s[0]));
    for(int j=1; j<s.size(); j++)
        printf("%c",tolower(s[j]));
    printf("\n");
}

///2-27
//28-28+n
inline int get_idx(char c) {
    return c-'A'+2;
}

int main() {
    QUERY{
        clear();
        scanf("%d",&n);
        string s;
        char tmp;
        int cnt=27;
        int mmk,tt;
        for(int i=0; i<n; i++) {
            cnt++;
            mmk=0;
            scanf("%d",&m);
            edge[cnt].EB(supersink);
            edge[supersink].EB(cnt);
            grid[cnt][supersink]=1;
            for(int j=0; j<m; j++) {
                cin>>s;
                tmp=s[0];
                if(islower(tmp))
                    tmp=toupper(tmp);
                if(tmp-'A'+1>n)
                    continue;
                tt=tmp-'A';
                if(mmk&(1<<tt))continue;
                mmk|=(1<<tt);
                input[i].EB(s);
                edge[get_idx(tmp)].EB(cnt);
                edge[cnt].EB(get_idx(tmp));
                grid[get_idx(tmp)][cnt]=1;
            }
        }
        for(int i=2; i<28; i++) {
            edge[supersource].EB(i);
            edge[i].EB(supersource);
            grid[supersource][i]=1;
        }
        maxflow();
        cnt=0;
        printf("Case #%d:\n",_T);
        for(int i=2;cnt<n;i++,cnt++){
            for(int j=0;j<n;j++){
                if(grid[j+28][i]>0){
                    for(int k=0;k<input[j].size();k++){
                        if(toupper(input[j][k][0])-'A'+2==i){
                            print_str(input[j][k]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
