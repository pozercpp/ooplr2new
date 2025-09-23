#include "decimal.h"
#include <initializer_list>
#include <iostream>

unsigned char Decimal::get(size_t i) { return v.get(i); }

void Decimal::print() {
  for (int i = v.len() - 1; i > -1; --i) {
    std::cout << (int)v.get(i);
  }
  if (v.len() == 0) {
    std::cout << 0;
  }
}

Decimal::Decimal(std::initializer_list<unsigned char> a) : v() {
  for (auto c : a) {
    v.push(c);
  }
  for (size_t i = 0; 2 * i < v.len(); ++i) {
    v.swap(i, v.len() - i - 1);
  }
}

Decimal::Decimal() : v() {}

Decimal::Decimal(unsigned int n) : v() {
  while (n) {
    v.push(n % 10);
    n /= 10;
  }
}

Decimal::Decimal(unsigned long long n) : v() {
  while (n) {
    v.push(n % 10);
    n /= 10;
  }
}

Decimal::~Decimal() { v.clear(); }

Decimal::Decimal(const Decimal &other) : v(other.v) {}

Decimal::Decimal(Decimal &&other) noexcept : v(other.v) { other.v.clear(); }

int Decimal::len() { return v.len(); }

bool equals(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return false;
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.get(i) != b.get(i)) {
      return false;
    }
  }
  return true;
}

bool notequals(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return true;
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.get(i) != b.get(i)) {
      return true;
    }
  }
  return false;
}

bool greater(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return a.len() > b.len();
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.get(i) < b.get(i)) {
      return false;
    }
  }
  return true;
}

bool less(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return a.len() < b.len();
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.get(i) > b.get(i)) {
      return false;
    }
  }
  return true;
}

bool equalsgreater(Decimal a, Decimal b) {
  return greater(a, b) || equals(a, b);
}

bool equalsless(Decimal a, Decimal b) { return less(a, b) || equals(a, b); }

Decimal plus(Decimal a, Decimal b) {
  if (a.len() < b.len()) {
    return plus(b, a);
  }
  Decimal res;
  for (int i = 0; i < a.len(); ++i) {
    if (res.len() <= i) {
      res.v.push((int)0);
    }
    int sum = res.v.get(i);
    res.v.pop();
    sum += (int)res.v.get(i) + (int)a.get(i);
    if (i < b.len()) {
      sum = sum + (int)b.get(i);
    }
    res.v.push(sum % 10);
    if (sum > 9) {
      res.v.push(1);
    }
  }
  return res;
}

Decimal sub(Decimal a, Decimal b) {
  if (less(a, b)) {
    return Decimal(0ull);
  }
  Decimal res;
  int prev = 0;
  for (int i = 0; i < a.len(); ++i) {
    int rz = a.v.get(i) - prev;
    if (i < b.len()) {
      rz -= b.v.get(i);
    }
    if (rz < 0) {
      prev = 1;
      rz += 10;
    } else {
      prev = 0;
    }
    res.v.push(rz);
  }
  while ((int)res.v.get(res.len() - 1) == 0) {
    res.v.pop();
  }
  return res;
}
