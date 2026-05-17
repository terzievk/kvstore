#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <optional>
#include <vector>
#include <utility>
#include <iostream>

// notes: maybe string_view fits here?

class HashTable {
  size_t nBuckets{2};
  size_t nElements{};
  size_t hash(const std::string& key) const;
  using Bucket = std::vector<std::pair<std::string, std::string>>;
  std::vector<Bucket> v;
  void resize();

public:
  HashTable() : v(nBuckets) {}
  void set(const std::string& key, const std::string& value);
  std::optional<std::string> get(const std::string& key) const;
  bool deleteValue(const std::string& key);
  void print() const;
};

#endif  // HASHTABLE_H_
