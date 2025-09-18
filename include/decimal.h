#ifndef DECIMALE_H
#define DECIMALE_H

#include <initializer_list>

class Decimal {
public:
  Decimal();
  Decimal(std::initializer_list<unsigned char>);
  Decimal(unsigned long long);
  Decimal(unsigned int);

  ~Decimal();
  Decimal(const Decimal&);
  Decimal(Decimal&&) noexcept;
  
  int len();

  friend Decimal operator+(Decimal, Decimal);
  friend Decimal operator-(Decimal, Decimal);
  friend bool operator==(Decimal, Decimal);
  friend bool operator!=(Decimal, Decimal);
  friend bool operator<(Decimal, Decimal);
  friend bool operator>(Decimal, Decimal);
  friend bool operator<=(Decimal, Decimal);
  friend bool operator>=(Decimal, Decimal);

  void print();

private:
  unsigned char *v;
  int size;
  int capacity;

  void pop();
  void push(unsigned char);
  void resize(int);
};
#endif