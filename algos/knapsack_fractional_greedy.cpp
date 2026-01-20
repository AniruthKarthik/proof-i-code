
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int value;
};

// Comparator: sort by value/weight ratio (descending)
bool cmp(Item a, Item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {

  // Sort items by ratio
  sort(items.begin(), items.end(), cmp);

  double totalValue = 0.0;

  for (auto &item : items) {

    // If whole item fits
    if (item.weight <= W) {
      W -= item.weight;
      totalValue += item.value;
    }
    // Take fraction
    else {
      totalValue += item.value * ((double)W / item.weight);
      break;
    }
  }

  return totalValue;
}

int main() {
  int W = 50;

  vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

  cout << "Maximum value = " << fractionalKnapsack(W, items) << endl;

  return 0;
}
