// Sample solution for UVa 10054 - The Necklace
// Euler Cycle Finding (the easy part) + printing the Euler Cycle (the hard part)

#include <cstdio>
#include <cstring>
#include <list>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

bool EulerTourExist;
int i, T, N, A, B, degree[1010], caseNo = 1;
vector<vii> AdjList;

#define TRAVERSE(c, it) \
  for (vii::iterator it = (c).begin(); it != (c).end(); it++)

list<int> cyc;             // we need list for fast insertion in the middle

void EulerTour(list<int>::iterator i, int u) {
  TRAVERSE (AdjList[u], v)
    if (v->second) {          // if this edge can still be used/not removed
      v->second = 0;              // must use -> to change the actual value
      TRAVERSE (AdjList[v->first], uu)
        if (uu->first == u && uu->second) {
          uu->second = false;
          break;
        }
      EulerTour(cyc.insert(i, u), v->first);
    }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    AdjList.assign(51, vii());            // there can be up to 50 vertices
    memset(degree, 0, sizeof degree);
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
      scanf("%d %d", &A, &B);
      AdjList[A].push_back(ii(B, 1));
      AdjList[B].push_back(ii(A, 1));
      degree[A] = (degree[A] + 1) % 2;
      degree[B] = (degree[B] + 1) % 2;
    }

    EulerTourExist = true;
    for (i = 1; i <= 50; i++)
      if (degree[i] == 1) // odd-degree vertex => Euler tour does not exist
        EulerTourExist = false;

    printf("Case #%d\n", caseNo++);
    if (EulerTourExist) {
      cyc.clear();
      EulerTour(cyc.begin(), A);// cyc contains an Euler tour starting at A
      int prev = A;
      for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++) {
        printf("%d %d\n", prev, *it);                     // the Euler tour
        prev = *it;
      }
    }
    else
      printf("some beads may be lost\n");

    if (T) printf("\n");
  }

  return 0;
}
