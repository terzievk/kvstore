#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <optional>
#include <vector>
#include <utility>

class HashTable {
  std::vector<std::vector<std::pair<std::string, std::string>>> v;
  const int base{131};
  const int nBuckets{16};

  int hash(std::string key) {
    int k{};
    int pow{1};

    for (size_t i{}; i < key.size(); ++i) {
      k += static_cast<int>(key[i]) * pow;
      pow *= base;
    }

    return k % nBuckets;
  }

public:
  void set(std::string key, std::string value) {}
  std::optional<std::string> get(std::string key) {}
  void deleteValue(std::string key) {}
};

#endif  // HASHTABLE_H_
