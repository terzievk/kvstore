#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <optional>
#include <vector>
#include <utility>

// notes: maybe string_view fits here?

class HashTable {
  std::vector<std::vector<std::pair<std::string, std::string>>> v;
  const int nBuckets{16};
  int hash(const std::string& key) const;

public:
  void set(const std::string& key, const std::string& value);
  std::optional<std::string> get(const std::string& key) const;
  void deleteValue(const std::string& key);
};

#endif  // HASHTABLE_H_
