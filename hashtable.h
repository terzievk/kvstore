#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <optional>
#include <vector>
#include <utility>

class HashTable {
  std::vector<std::vector<std::pair<std::string, std::string>>> v;
  const int nBuckets{16};

  // Converts a string key to a bucket index.
  // Treats each character as a digit in base 131
  // with the lowest power first so it's simpler,
  // accumulates into an integer, then mods by nBuckets.
  int hash(const std::string& key) const {
    const int base{131};

    int k{};
    int pow{1};

    for (size_t i{}; i < key.size(); ++i) {
      k += static_cast<int>(key[i]) * pow;
      pow *= base;
    }

    return k % nBuckets;
  }

public:
  void set(const std::string& key, const std::string& value) {}
  std::optional<std::string> get(const std::string& key) const {}
  void deleteValue(const std::string& key) {}
};

#endif  // HASHTABLE_H_
