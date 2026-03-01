// Question : 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>

using namespace std;

void printVecArr(vector <int> &arr){
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector <int> arr = {3,5,23,322,532,1,-1};



                        //* Erase and Fill *//

    fill(arr.begin(), arr.end(), 0);

    v.erase(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end()); //! (Removes consecutive duplicates)
    v.erase(remove(v.begin(), v.end(), x), v.end()); //!(Remove all x)
    remove_if()


    
                    //* COMParison *//


    min(a,b);
    max(a,b);

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());


                    //* SEARCH *//

    count(v.begin(), v.end(), x); //* return the x count in the range
    count_if(v.begin(), v.end(), [](int x){ return x%2==0; });

    auto it = find(v.begin(), v.end(), x); //* linear serch
    find_if()

    v.binary_search(v.begin(), v.end(), 10); //* return the idx of the ele

    auto it = lower_bound(v.begin(), v.end(), 20); 
    auto it = upper_bound(v.begin(), v.end(), x);
    auto it = equal_range(v.begin(), v.end(), 10); //* gives both lover upper


                    //* SORT & Rotation*//

    sort(arr.begin(), arr.end()); //* sort the container from [x,y)
    //? OR
    sort(v.begin(), v.end(), less<int>());

    sort(v.begin(), v.end(), greater<int>()); //todo: decending

    v.stable_sort() //* maintain relative order

    v.is_sorted(v.begin(), v.end()); //! isSorted ?

    //todo: 
    partition(v.begin(), v.end(), predicate);
    stable_partition()

    rotate(v.begin(), v.begin()+k, v.end());
    //3 4 5 1 2


                    //* std:: move *//


    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq(greater<int>(), std::move(v));
    /*
    Here:
    //* Without move → full copy of v
    ///todo: With move → v becomes empty, pq takes its memory
    */



                    //* REVERSE  *//

    vector<int> revV = reverse(v.begin(), v.end()); //* return the reversed array




                    //* MATHS *//

    int sum = accumulate(v.begin(), v.end(), 0); //* Sums all elements starting from initial value.

    vector<int> v = {1,2,3,4};
    vector<int> result(4);
    partial_sum(v.begin(), v.end(), result.begin());
    // 1 3 6 10


    vector<int> v(5);
    //*Fills container with sequential values starting from given number.
    iota(v.begin(), v.end(), 1); 
    // 1 2 3 4 5
        

    next_permutation(v.begin(), v.end());
    prev_permutation()

    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g); //! shuffel


return 0;}
