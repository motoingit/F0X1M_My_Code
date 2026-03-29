
// Question : Union of Disjoint Set

#include <iostream>
#include <vector>

using namespace std;

/// @brief X-Dont now
class DSU{
   public:
   vector <int> parentArr, rankArr;

   DSU(int size){
      parentArr.resize(size);
      rankArr.resize(size, 0); //* rank will be 0 for all init

      // self loop | every one is its own parent
      for (int i = 0; i < size; i++) {
         parentArr[i] = i;
      }
   }

   /// @brief Find the Representative of Group
   /// @param src 
   /// @return parentArr
   int findRank(int src){
      if(parentArr[src] != src){
         parentArr[src] = findRank(parentArr[src]);
         return parentArr[src];
      }else{
         return src;
      }
   }

   /// @brief Union of group of x1 and x2 wrt RANK
   /// @param x1 group one
   /// @param x2 group two
   /// @return Status of the task
   int unionRank(int x1, int x2){ 
      int x1Rank1 = findRank(x1);
      int x1Rank2 = findRank(x2);

      // if already union then ignore
      if(x1Rank1 == x1Rank2) return 200;

      if(x1Rank1 > x1Rank2){
         rankArr[x1Rank2] = x1Rank1;
      }else if(x1Rank1 < x1Rank2){
         rankArr[x1Rank1] = x1Rank2;
      }else{ //! incrementing rank
         rankArr[x1Rank2] = x1Rank1;
         rankArr[x1Rank1]++; 
      }

      return 200;
   }

   /// @brief Lame Funtion
   /// @param x1 
   /// @param x2 
   /// @return 
   int unionBasic(int x1, int x2){
      parentArr[x1] = x2;
      return 200;
   }

   int unionSize(int x1, int x2){
      
      return 200;
   }

   /// @brief Make new Element
   /// @return Status of the Task
   int makeElementDSU(){
      //* if 5 element is there then, idx[5] = 5
      parentArr.push_back(parentArr.size());
      return 200;
   }

   /// @brief Know the Range
   /// @return Status of the range
   int knowRange(){
      if(parentArr.size() == 0){
         cout << "Empty DSU !" << endl;
      }else{
         cout << "From 0 to "<< parentArr.size() << endl;
      }
   }


   
};

int main(){
   
   DSU graph1(10);

   while (condition)
   {
      /* code */
   }
   
   graph1.unionRank(2,5);

return 0;}
