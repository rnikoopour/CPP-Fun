#include <iostream>

template <class Func> struct WrappedFunc {
  Func function;
};

template <class T, class T2> 
auto operator|(wrapped<T> lhs, T2 rhs) {
  return rhs(lhs);
}

template <class T> 
auto add(const T& rhs) {
  return [=](auto lhs) { return wrapped<T>{lhs.val + rhs}; };
}

auto add_bar = add<std::string>(" bar");

int main() {
  const auto foo = (wrapped<std::string>{"foo"} | add_bar | add_bar | add_bar).val;
  std::cout << foo << std::endl;
}
