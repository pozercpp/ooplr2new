#include "myvector.h"

myvector::myvector() : size(0), capacity(1), v(nullptr) {
    v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
}

myvector::myvector(const myvector& other) : size(0), capacity(1), v(nullptr) {
    v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
    for (size_t i = 0; i < other.size; ++i) {
        push(other.get(i));
    }
}

myvector::~myvector() {
    if (v != nullptr) {
        v = nullptr;
    }
    size = 0;
    capacity = 1;
    v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
}

void myvector::resize(size_t newsize) {
    capacity = newsize;
    v = (unsigned char *)realloc(v, sizeof(unsigned char) * capacity);
}

void myvector::push(unsigned char c) {
    if (size >= capacity) {
        resize(2 * capacity);
    }
    v[size++] = c;
}

void myvector::pop() {
    if (size) {
        --size;
    }
}

unsigned char myvector::get(size_t i) const {
    return v[i];
}

size_t myvector::len() {
    return size;
}

void myvector::swap(size_t i, size_t j) {
    unsigned char c = v[i];
    v[i] = v[j];
    v[j] = c;   
}

void myvector::clear() {
    size = 0;
    capacity = 1;
    v = (unsigned char *)malloc(sizeof(unsigned char) * capacity);
}