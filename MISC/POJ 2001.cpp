/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
using namespace std;
typedef long long ll;
#define eps 1e-9
#define inf 0x3f3f3f3f
#define INF 2e18
#define PI acos(-1.0)
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define Iterator(a) __typeof__(a.begin())
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define TEST            \
    int test;           \
    scanf("%d", &test); \
    for (int T = 1; T <= test; T++)
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctz(x)
#define total_1s(x) __builtin_popcount(x)
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define segtree int mid = (st + en) / 2, lt = node * 2, rg = node * 2 + 1
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define pll pair<ll, ll>

string p;
struct node
{
    node *next[27];
    int cnt;
    node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        cnt = 0;
    }
};
node *root;
void insert_()
{
    node *now = root;
    int len = p.size();
    for (int i = 0; i < len; i++)
    {
        int id = p[i] - 'a';
        if (now->next[id] == NULL)
        {
            now->next[id] = new node();
        }
        now = now->next[id];
        now->cnt++;
    }
}
int query()
{
    node *now = root;
    int len = p.size();
    for (int i = 0; i < len; i++)
    {
        int id = p[i] - 'a';
        now = now->next[id];
        if (now->cnt == 1)
            return i + 1;
    }
    return len;
}
string ara[1009];
int main()
{
    root = new node();
    int i = 0;
    while (cin >> p)
    {
        insert_();
        ara[i++] = p;
    }
    for (int j = 0; j < i; j++)
    {
        p = ara[j];
        int x = query();
        printf("%s ", p.c_str());
        for (int k = 0; k < x; k++)
        {
            printf("%c", p[k]);
        }
        printf("\n");
    }
}
