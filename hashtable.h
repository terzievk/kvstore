#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <optional>
#include <vector>
#include <utility>

class HashTable {
  std::vector<std::vector<std::pair<std::string, std::string>>> v;

public:
  void set(std::string key, std::string value) {}
  std::optional<std::string> get(std::string key) {}
  void deleteValue(std::string key) {}
};

#endif  // HASHTABLE_H_
