#pragma once
#include <iostream>

class MyVector {
private:
  size_t size;
  size_t capacity;
  unsigned char *v;
  void resize(size_t sz);

public:
  void push(unsigned char);
  void pop();
  void clear();

  unsigned char get(size_t);

  void swap(size_t, size_t);

  size_t len();

  MyVector(MyVector&&);
  MyVector(const MyVector &);
  MyVector();
  ~MyVector();
};
