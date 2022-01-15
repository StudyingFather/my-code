#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
typedef pair<int, int> pii;  // et, ip
string H;
map<string, int> curip;
map<int, string> host;
priority_queue<pii, vector<pii>, greater<pii> > used_ip;
set<int> undist_ip;
set<int> exp_ip;
int vis[10005], ttl[10005];
void response(string sender, string receiver, string type, int ip, int et) {
  cout << sender << ' ' << receiver << ' ' << type << ' ' << ip << ' ' << et
       << endl;
}
int main() {
  // freopen("a.in", "r", stdin);
  int N, tdef, tmax, tmin;
  cin >> N >> tdef >> tmax >> tmin >> H;
  int n;
  cin >> n;
  for (int i = 1; i <= N; i++) undist_ip.insert(i);
  while (n--) {
    string sender, receiver, type;
    int rt, ip, et;
    cin >> rt >> sender >> receiver >> type >> ip >> et;
    if (receiver != "*" && receiver != H && type != "REQ") continue;
    if (type != "REQ" && type != "DIS") continue;
    if (receiver == "*" && type != "DIS") continue;
    if (receiver == H && type == "DIS") continue;

    while (!used_ip.empty()) {
      int et = used_ip.top().first, ip = used_ip.top().second;
      string user = host[ip];
      if (et > rt) break;
      used_ip.pop();
      if (et != ttl[ip]) continue;
      if (vis[ip] == 2) {
        exp_ip.insert(ip);
        vis[ip] = 3;
        ttl[ip] = 0;
      } else if (vis[ip] == 1) {
        curip[user] = 0;
        host[ip] = "";
        undist_ip.insert(ip);
        vis[ip] = 0;
        ttl[ip] = 0;
      }
    }

    if (type == "DIS") {
      int scip = curip[sender];
      if (scip != 0) {
        ip = scip;
        if (vis[ip] == 3) exp_ip.erase(ip);
      } else if (!undist_ip.empty()) {
        ip = *undist_ip.begin();
        undist_ip.erase(ip);
      } else if (!exp_ip.empty()) {
        ip = *exp_ip.begin();
        exp_ip.erase(ip);
        string olduser = host[ip];
        curip[olduser] = 0;
      } else
        continue;
      if (et == 0)
        et = rt + tdef;
      else if (et > rt + tmax)
        et = rt + tmax;
      else if (et < rt + tmin)
        et = rt + tmin;
      response(H, sender, "OFR", ip, et);
      used_ip.push(make_pair(et, ip));
      curip[sender] = ip;
      host[ip] = sender;
      ttl[ip] = et;
      vis[ip] = 1;
    } else {
      if (receiver != H) {
        int cip = curip[sender];
        if (cip != 0 && vis[cip] == 1) {
          undist_ip.insert(cip);
          curip[sender] = 0;
          host[cip] = "";
          ttl[cip] = 0;
          vis[cip] = 0;
        }
        continue;
      }
      if (ip < 1 || ip > N || host[ip] != sender) {
        response(H, sender, "NAK", ip, 0);
        continue;
      }
      if (vis[ip] == 3) exp_ip.erase(ip);
      if (et == 0)
        et = rt + tdef;
      else if (et > rt + tmax)
        et = rt + tmax;
      else if (et < rt + tmin)
        et = rt + tmin;
      response(H, sender, "ACK", ip, et);
      used_ip.push(make_pair(et, ip));
      curip[sender] = ip;
      host[ip] = sender;
      ttl[ip] = et;
      vis[ip] = 2;
    }
  }
  return 0;
}