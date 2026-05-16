#include <iostream>
#include "hashtable.h"

void printResult(const std::optional<std::string>& result) {
  if (result) {
    std::cout << *result << '\n';
  } else {
    std::cout << "(nil)\n";
  }
}

int main() {
  HashTable h;
  h.print();

  printResult(h.get("hello"));

  h.set("hello", "wordl");
  h.print();
  printResult(h.get("hello"));
  h.set("hello", "world");
  h.print();
  printResult(h.get("hello"));
  h.set("hi", "there");
  h.print();
  printResult(h.get("hello"));

  return 0;
}
