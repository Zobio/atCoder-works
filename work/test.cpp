// common part begin
#include <bits/stdc++.h>

using namespace std;
#define INF ((1ll) << 60)
#define rep(i, n) for (long long i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
void chmax(ll &a, ll b)
{
    if (a < b)
        a = b;
}
void chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
    }
}
bool isprime(ll x)
{
    for (ll i = 2; i <= sqrt(x) + 0.1; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
// common part end
#define hi_ cout << "hi" << endl;
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define llV(name, size)                     \
    std::vector<long long> name(size);      \
    for (unsigned int i = 0; i < size; i++) \
    cin >> name[i]
#define die(x)             \
    {                      \
        cout << x << endl; \
        return 0;          \
    }
class Print
{
public:
    Print() {}
};

void operator<<(Print p, vector<ll> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void operator<<(Print p, vector<vector<ll>> v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void operator<<(Print p, ull x)
{
    cout << x << endl;
}
void operator<<(Print p, vector<ull> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void operator<<(Print p, vector<vector<ull>> v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void operator<<(Print p, ll x)
{
    cout << x << endl;
}

void operator<<(Print p, string s)
{
    cout << s << endl;
}
void operator<<(Print p, vector<string> s)
{
    for (auto i : s)
        cout << i << endl;
}

void operator<<(Print p, vector<pair<pair<ll, ll>, ll>> v)
{
    for (auto i : v)
    {
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }
}
void operator<<(Print p, vector<pair<ll, pair<ll, ll>>> v)
{
    for (auto i : v)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
}
void operator<<(Print p, pair<ll, ll> v)
{
    cout << v.first << " " << v.second << endl;
}
Print print;

// template <typename flow_t>
// struct FordFulkerson
// {
//     struct edge
//     {
//         int to;
//         flow_t cap;
//         int rev;
//         bool isrev;
//         int idx;
//     };

//     vector<vector<edge>> graph;
//     vector<int> used;
//     const flow_t INF;
//     int timestamp;

//     FordFulkerson(int n) : INF(numeric_limits<flow_t>::max()), timestamp(0)
//     {
//         graph.resize(n);
//         used.assign(n, -1);
//     }

//     void add_edge(int from, int to, flow_t cap, int idx = -1)
//     {
//         graph[from].emplace_back((edge){to, cap, (int)graph[to].size(), false, idx});
//         graph[to].emplace_back((edge){from, 0, (int)graph[from].size() - 1, true, idx});
//     }

//     flow_t dfs(int idx, const int t, flow_t flow)
//     {
//         if (idx == t)
//             return flow;
//         used[idx] = timestamp;
//         for (auto &e : graph[idx])
//         {
//             if (e.cap > 0 && used[e.to] != timestamp)
//             {
//                 flow_t d = dfs(e.to, t, min(flow, e.cap));
//                 if (d > 0)
//                 {
//                     e.cap -= d;
//                     graph[e.to][e.rev].cap += d;
//                     return d;
//                 }
//             }
//         }
//         return 0;
//     }

//     flow_t max_flow(int s, int t)
//     {
//         flow_t flow = 0;
//         for (flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++)
//         {
//             flow += f;
//         }
//         return flow;
//     }

//     void output()
//     {
//         for (int i = 0; i < graph.size(); i++)
//         {
//             for (auto &e : graph[i])
//             {
//                 if (e.isrev)
//                     continue;
//                 auto &rev_e = graph[e.to][e.rev];
//                 cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
//             }
//         }
//     }
// };
ld EPS = 1E-8;

vector<vector<ll>> G;
vector<ll> visited;
vector<ll> ans;
bool flag = false;
void dfs(ll now, queue<ll> que)
{
    // print << now;
    ll b = -1;
    if (que.size() != 4)
    {
        que.push(now);
    }
    else
    {
        b = que.front();
        que.pop();
        que.push(now);
    }
    for (auto e : G[now])
    {
        if (!flag&&visited[e] && que.size() == 4 && que.front() == e)
        {
            flag = true;
            auto q = que;
            rep(i, 4)
            {
                ans.push_back(q.front());
                q.pop();
            }
            continue;
        }
        else if (visited[e])
        {
            continue;
        }
        visited[e] = 1;
        dfs(e, que);
    }
}

int main()
{
    ll S, T, M;
    cin >> S >> T >> M;
    visited = vector<ll>(S + T);
    G = vector<vector<ll>>(S + T);
    rep(i, M)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i,S+T){
    if(!visited[i]){
        visited[i]=1;
        dfs(i, queue<ll>());
    }}
    if (flag)
    {
        rep(i, ans.size()) cout << ans[i]+1 << " ";
        cout << endl;
        return 0;
    }
    print << -1ll;
}