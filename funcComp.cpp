#include <iostream>

template <class T, class T2> 
auto operator|(T lhs, T2 rhs) {
  return rhs(lhs);
}

template <class T> 
auto add(const T& rhs) {
  return [=](auto lhs) { return lhs + rhs; };
}

auto add_bar = add<std::string>(" bar");

int main() {
  const auto foo = "foo" | add_bar | add_bar | add_bar;
  std::cout << foo << std::endl;
}
