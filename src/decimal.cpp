#include "decimal.h"
#include <initializer_list>
#include <iostream>

void Decimal::print() {
  for (int i = size - 1; i > -1; --i) {
    printf("%d", (int)v[i]);
  }
  if (size == 0) {
    printf("0");
  }
}

void Decimal::resize(int newsize) {
  capacity = newsize;
  v = (unsigned char *)realloc(v, sizeof(unsigned char) * capacity);
}

void Decimal::push(unsigned char c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void Decimal::pop() {
  if (size > 0) {
    size--;
  }
}

Decimal::Decimal(std::initializer_list<unsigned char> a)
    : v(nullptr), size(0), capacity(1) {
  v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
  for (auto c : a) {
    push(c);
  }
  for (int i = 0; 2 * i < size; ++i) {
    std::swap(v[i], v[size - i - 1]);
  }
}

Decimal::Decimal() : size(0), capacity(1) {
  v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
  push(0);
}

Decimal::Decimal(unsigned int n) : size(0), capacity(1) {
  v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
  while (n) {
    push(n % 10);
    n /= 10;
  }
}

Decimal::Decimal(unsigned long long n) : size(0), capacity(1) {
  v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
  while (n) {
    push(n % 10);
    n /= 10;
  }
}

Decimal::~Decimal() {
    if (v != nullptr) {
        delete[] v;
        v = nullptr;
    }
    size = 0;
    capacity = 1;
}

Decimal::Decimal(const Decimal& other) : size(other.size), capacity(other.capacity) {
    v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
    for (int i = 0; i < size; ++i) {
        v[i] = other.v[i];
    }
}

Decimal::Decimal(Decimal&& other) noexcept 
    : v(other.v), size(other.size), capacity(other.capacity) {
    other.v = nullptr;
    other.size = 0;
    other.capacity = 1;
}

int Decimal::len() { return size; }

bool operator==(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return false;
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.v[i] != b.v[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return true;
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.v[i] != b.v[i]) {
      return true;
    }
  }
  return false;
}

bool operator>(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return a.len() > b.len();
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.v[i] < b.v[i]) {
      return false;
    }
  }
  return true;
}

bool operator<(Decimal a, Decimal b) {
  if (a.len() != b.len()) {
    return a.len() < b.len();
  }
  for (int i = 0; i < a.len(); ++i) {
    if (a.v[i] > b.v[i]) {
      return false;
    }
  }
  return true;
}

bool operator>=(Decimal a, Decimal b) { return a > b || a == b; }

bool operator<=(Decimal a, Decimal b) { return a < b || a == b; }

Decimal operator+(Decimal a, Decimal b) {
  if (a.len() < b.len()) {
    return b + a;
  }
  Decimal res;
  for (int i = 0; i < a.len(); ++i) {
    if (res.len() <= i) {
      res.push((int)0);
    }
    int sum = (int)res.v[i] + (int)a.v[i];
    if (i < b.len()) {
      sum = sum + (int)b.v[i];
    }
    res.v[i] = sum % 10;
    if (sum > 9) {
      res.push(1);
    }
  }
  return res;
}

Decimal operator-(Decimal a, Decimal b) {
  if (a < b) {
    return Decimal(0ull);
  }
  Decimal res;
  int prev = 0;
  for (int i = 0; i < a.len(); ++i) {
    if (res.len() <= i) {
      res.push(0);
    }
    int rz = a.v[i] - prev;
    if (i < b.len()) {
      rz -= b.v[i];
    }
    if (rz < 0) {
      prev = 1;
      rz += 10;
    } else {
      prev = 0;
    }
    res.v[i] = rz;
  }
  while ((int)res.v[res.len() - 1] == 0) {
    res.pop();
  }
  return res;
}