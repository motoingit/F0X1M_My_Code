// Bellman Ford Algrorithm - Find shortest path from src to all verteces - DP - Detect Negitive Weight Cycle

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

/// @brief BelminFord Algorithm for (src, wei, des)
/// @param adjList 
/// @param nV 
/// @param src 
/// @return distArray
vector<int> bellmanFordAlgo(vector<vector<tuple<int, int, int>>> &adjList, int nV, int src){
   const int _INF = 1e8; // INT_MAX

   vector<int> dist(nV, _INF);
   dist[src] = 0;

   //*relaxation for n-1 times
   for (int i = 1; i <= nV-1; i++) { 
     bool relaxed = false;
      for (auto& ele1 : adjList) {
         for (auto& ele2 : ele1) {

            auto [xStart, xWeight, xEnd] = ele2;

            if(dist[xStart] != _INF && dist[xStart] + xWeight < dist[xEnd]){
               dist[xEnd] = dist[xStart] + xWeight;
               relaxed = true;
            }
         }
      }
      if (relaxed == false) break; //* optimisation
   }

   // ✅ Add this after the n-1 relaxations: for cycle -ve wweighted
   for (auto& ele1 : adjList) {
      for (auto& ele2 : ele1) {
         auto [xStart, xWeight, xEnd] = ele2;
         if (dist[xStart] + xWeight < dist[xEnd]) {
               cout << "Negative weight cycle detected!\n";
               return {};
         }
      }
   }

   return dist;
}

int main(){
   int nV, nE;
   cout << "Enter nV : ";
   cin >> nV;
   cout << "Enter nE : ";
   cin >> nE;

   // {start, weight, end}
   vector<vector<tuple<int, int, int>>> adjList(nV);

   cout << "Enter all Edges in {start, weight, end} > \n\n";
   for (int i = 0; i < nE; i++) {
      int start, weight, end;
      cout << "Edge " << i << " : ";
      cin >> start >> weight >> end;

      adjList[start].push_back({start, weight, end});

      //todo: if undirected then >>
      //! adjList[end].push_back({end, weight, start}); 
   }

   int src = 0; //* for now src is 0
   vector<int> distSrc = bellmanFordAlgo(adjList, nV, src); 

   // ✅ Add this check:
   if (distSrc.empty()) {
      cout << "No result due to negative cycle.\n";
      return 1;
   }

   cout << "Resutls > \n";
   for (int i = 0; i < nV; i++) {
      cout << "Node " << i << " : " << distSrc[i] << endl;
   }
   return 0;
}

/* //! Test Cases


   //* Graph 1 (No Negative Cycle)
7
10
0 6 1
0 5 2
0 5 3
1 -1 4
2 -2 1
2 1 0
3 -2 2
3 -1 5
4 3 6
5 3 6

//* Test 2 — Simple Graph (All Positive)
5
6
0 4 1
0 2 2
1 3 3
2 1 1
2 5 3
3 2 4

//* Test 3 — Graph With Negative Edges (No Cycle)
5
5
0 10 1
0 5 2
1 -3 3
2 2 1
3 1 4

//* Test 4 — Actual Negative Weight Cycle 🔴
4
5
0 1 1
1 2 2
2 -6 1
1 3 3
0 5 3

//* Test 5 — Unreachable Nodes
6
4
0 3 1
1 2 2
2 1 3
4 5 5

*/


/* Tupes
#include <tuple>

// Method 1: Direct declaration
std::tuple<int, std::string, double> t1(1, "hello", 3.14);

// Method 2: Using make_tuple (type deduction)
auto t2 = std::make_tuple(1, "hello", 3.14);

int    a = std::get<0>(t);   // 10
string b = std::get<1>(t);   // "world"
double c = std::get<2>(t);   // 2.5
*/
