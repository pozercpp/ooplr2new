#pragma once

#include <initializer_list>
#include <iostream>
#include <myvector.h>

class Decimal {
public:
  Decimal();
  Decimal(std::initializer_list<unsigned char>);
  Decimal(unsigned long long);
  Decimal(unsigned int);

  ~Decimal();
  Decimal(const Decimal &);
  Decimal(Decimal &&) noexcept;

  unsigned char get(size_t);

  int len();

  void print();

  MyVector v;
};

Decimal plus(Decimal, Decimal);
Decimal sub(Decimal, Decimal);

bool equals(Decimal, Decimal);
bool greater(Decimal, Decimal);
bool less(Decimal, Decimal);
bool equalsgreater(Decimal, Decimal);
bool equalsless(Decimal, Decimal);
bool notequals(Decimal, Decimal);
