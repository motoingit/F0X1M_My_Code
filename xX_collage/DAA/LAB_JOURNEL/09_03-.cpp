/* 
Optimal File Merging — Minimum Cost
Problem (Compact):
Given N files with sizes, merge all into one file. Cost of merging two files = sum of their sizes. Find the minimum total computation cost to merge all files.

Approach — Min-Heap (Greedy):

Always merge the two smallest files first (greedy insight)
Use a priority_queue (min-heap) to always get smallest two in O(log n)
Add their sum back to heap, accumulate cost
Repeat until 1 file remains


Why smallest first? Smaller merges early means those sizes don't get repeatedly added. Same idea as Huffman encoding — frequent items get shorter codes.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
   int nFiles;
   if (!(cin >> nFiles))
   {
      cout << "Enter Numerric";
      return 404;
   }

   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i < nFiles; i++)
   {
      int fileData;
      if (cin >> fileData)
      {
         pq.push(fileData);
      }
      else
      {
         cout << "some wong value";
         return 404;
      }
   }

   if (pq.size() < 2)
   {
      cout << 0;
      return 0;
   }

   long long totalCost = 0;
   int nMerging = 0;
   while (pq.size() > 1)
   {
      int file1 = pq.top();
      pq.pop();
      int file2 = pq.top();
      pq.pop();

      int resultTwoFiles = file1 + file2;
      pq.push(resultTwoFiles);

      nMerging++;
      totalCost += resultTwoFiles;
   }

   cout << totalCost;
   return 0;
}
/*
Sample Input:
10
10 5 100 50 20 15 5 20 100 10
Expected Output:
960

Dry Run (smaller example from problem: {5, 10, 15, 20, 50, 100}):
Heap: [5, 10, 15, 20, 50, 100]

Step 1: merge 5+10   = 15   → cost=15,   heap: [15, 15, 20, 50, 100]
Step 2: merge 15+15  = 30   → cost=45,   heap: [20, 30, 50, 100]
Step 3: merge 20+30  = 50   → cost=95,   heap: [50, 50, 100]
Step 4: merge 50+50  = 100  → cost=195,  heap: [100, 100]
Step 5: merge 100+100= 200  → cost=395,  heap: [200]

Total = 395 ✅  (matches problem's stated optimal)

Why NOT brute force (merge in given order)?
Brute {10,5,100,50,20,15,5,20,100,10} → left to right:
  10+5=15, 15+100=115, 115+50=165 ... total = much higher

Greedy (min-heap) → always merges cheapest pair → 960 ✅

Complexity:
ValueTimeO(N log N) — each merge is O(log N), N-1 mergesSpaceO(N) — heap storageSonnet 4.6Adaptive
*/
