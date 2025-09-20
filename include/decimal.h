#pragma once

#include <initializer_list>

class Decimal {
public:
  unsigned char *v;

  void pop();
  void push(unsigned char);

  Decimal();
  Decimal(std::initializer_list<unsigned char>);
  Decimal(unsigned long long);
  Decimal(unsigned int);

  ~Decimal();
  Decimal(const Decimal&);
  Decimal(Decimal&&) noexcept;
  
  int len();

  void print();

private:
  int size;
  int capacity;

  void resize(int);
};

Decimal plus(Decimal, Decimal);
Decimal sub(Decimal, Decimal);

bool equals(Decimal, Decimal);
bool greater(Decimal, Decimal);
bool less(Decimal, Decimal);
bool equalsgreater(Decimal, Decimal);
bool equalsless(Decimal, Decimal);
bool notequals(Decimal, Decimal);