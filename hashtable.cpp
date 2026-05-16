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

  return k % nBuckets;
}
