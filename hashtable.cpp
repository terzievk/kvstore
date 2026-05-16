#include "hashtable.h"

// Converts a string key to a bucket index.
// Treats each character as a digit in base 131
// with the lowest power first so it's simpler,
// accumulates into an integer, then mods by nBuckets.
int HashTable::hash(const std::string& key) const {
  const int base{131};

  int k{};
  int pow{1};

  for (size_t i{}; i < key.size(); ++i) {
    k += static_cast<int>(key[i]) * pow;
    pow *= base;
  }

  return k % static_cast<int>(nBuckets);
}

// just print the hashtable
void HashTable::print() const {
  for (size_t i{}; i < v.size(); ++i) {
    std::cout << "Bucket N:" << i << '\n';
    for (size_t j{}; j < v[i].size(); ++j) {
      std::cout << v[i][j].first << ' ' << v[i][j].second << '\n';
    }
  }
}
