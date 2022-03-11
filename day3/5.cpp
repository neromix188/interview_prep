#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 1e3 + 10, M = N;
//=======================

vi g[N];

// dp[i][j] = [0,1], 0 means that substring of s from i to j is not palindromic string and vice versa
// dp[i][j] = 1 in case of dp[i+1,j-i] = 1 and s[i] == s[j]
int dp[N][N];

int solve(int (&dp)[N][N], string s, int begin, int end) {
    if (dp[begin][end] != -1) 
        return dp[begin][end];
    if (begin == end) {
        return dp[begin][end] = 1;
    } 
    if (end - begin == 1) {
        if (s[begin] == s[end])
            return dp[begin][end] = 1;
        else return dp[begin][end] = 0;
    }
    if (s[begin] == s[end] && solve(dp, s, begin+1, end-1) == 1) {
        return dp[begin][end] = 1;
    }
    return dp[begin][end] = 0;
}

string longestPalindomicSubstring(string s) {
    int start = 0;
    int maxLength = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            solve(dp, s, i, j);
            if (dp[i][j] == 1 && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLength);
} 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    string s = "cbbd";
    // init value for dp array
    memset(dp, -1, sizeof dp);
    cout << longestPalindomicSubstring(s);
    return 0;
}
