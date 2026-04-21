#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Object {
    int id;
    double weight;
    double value;
    double unitValue;
};

int main() {
    int nItems;
    if (!(cin >> nItems)) return 0;

    vector<double> weights(nItems), values(nItems);
    for (int i = 0; i < nItems; i++) cin >> weights[i];
    for (int i = 0; i < nItems; i++) cin >> values[i];

    double maxCapacity;
    cin >> maxCapacity;

    vector<Object> items;
    for (int i = 0; i < nItems; i++) {
        // Use i+1 for 1-based indexing common in problem outputs
        items.push_back({i + 1, weights[i], values[i], values[i] / weights[i]});
    }

    // Sort descending by unit value
    sort(items.begin(), items.end(), [](const Object &a, const Object &b) {
        return a.unitValue > b.unitValue;
    });

    double totalValue = 0.0;
    double currentWeight = 0.0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < nItems; i++) {
        if (currentWeight + items[i].weight <= maxCapacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            double remain = maxCapacity - currentWeight;
            totalValue += items[i].unitValue * remain;
            currentWeight += remain;

            //*for printing
            items[i].weight = remain;
            items[i].value = items[i].unitValue * remain;
            items.erase(items.begin()+i+1);
            break; // Bag is full
        }
    }

    cout << "Maximum value : " << totalValue << endl;

    for (auto& elem : items) {
      cout << elem.id << " : " << elem.weight << " : " << elem.value << endl;
    }
    return 0;
}
