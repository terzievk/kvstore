#include <cassert>
#include "hashtable.h"

// Converts a string key to a bucket index.
// Treats each character as a digit in base 131
// with the lowest power first so it's simpler,
// accumulates into an integer, then mods by nBuckets.
// Basically string hashing, where
// hash(s) = s[0] + s[1] * p + s[2] * p^2 + ... s[n] * p^(n-1) mod m
// where p = 131 and m = nBuckets, see:
// https://cp-algorithms.com/string/string-hashing.html
size_t HashTable::hash(const std::string& key) const {
  const int base{131};

  int k{};
  int pow{1};

  for (size_t i{}; i < key.size(); ++i) {
    k += static_cast<int>(key[i]) * pow;
    pow *= base;
  }

  return static_cast<size_t>(k) % nBuckets;
}

// just print the hashtable
void HashTable::print() const {
  for (size_t i{}; i < v.size(); ++i) {
    std::cout << "Bucket N:" << i << '\n';
    for (size_t j{}; j < v[i].size(); ++j) {
      std::cout << v[i][j].first << ' ' << v[i][j].second << '\n';
    }
  }
  std::cout << "Number of elements: " << nElements << '\n';
}


void HashTable::set(const std::string& key, const std::string& value) {
  size_t h{hash(key)};

  for (size_t i{}; i < v[h].size(); ++i) {
    if (v[h][i].first == key) {
      v[h][i].second = value;
      return;
    }
  }

  v[h].push_back(std::make_pair(key, value));
  ++nElements;
  // if the hashtable is 70% full resize
  if (static_cast<double>(nElements) > static_cast<double>(nBuckets) * 0.7) {
    resize();
  }
}


std::optional<std::string> HashTable::get(const std::string& key) const {
  size_t h{hash(key)};

  for (size_t i{}; i < v[h].size(); ++i) {
    if (v[h][i].first == key) {
      return v[h][i].second;
    }
  }

  return std::nullopt;
}

// returns true if there was an element to be deleted
bool HashTable::deleteValue(const std::string& key) {
  size_t h{hash(key)};

  for (Bucket::iterator it = v[h].begin(); it != v[h].end();) {
    if (it->first == key) {
      it = v[h].erase(it);

      assert(nElements > 0);
      --nElements;
      return true;
    } else {
      ++it;
    }
  }

  return false;
}

void HashTable::resize() {
  nBuckets *= 2;
  std::vector<Bucket> vNew(nBuckets);

  for (size_t i{}; i < v.size(); ++i) {
    for (size_t j{}; j < v[i].size(); ++j) {
      std::string key{v[i][j].first};
      std::string value{v[i][j].second};

      vNew[hash(key)].push_back(std::make_pair(key, value));
    }
  }

  v = vNew;
}
