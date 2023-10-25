// Copyright 2022 Marina Usova

#ifndef LIB_EXAMPLE_EXAMPLE_H_
#define LIB_EXAMPLE_EXAMPLE_H_

#include <iostream>
#include <string>
#include <stdexcept>

/********************************* FUNC EXAMPLE ****************************/
float division(int a, int b);
/*****************************************************************************/


/************************* TEMPLATE CLASS EXAMPLE **************************/
template <typename T> class ExampleClass;
template <typename T>
std::ostream& operator<<(std::ostream& out,
 const ExampleClass<T>& obj) noexcept;

template <typename T>
class ExampleClass {
    T* data;
    size_t size;
    
public:

    explicit ExampleClass() : data(nullptr), size(0) {}
    explicit ExampleClass(size_t _size) {
        if (_size > INT_MAX || _size <= 0) 
            throw std::length_error(
                "Size must be positive value, less then MAX_INT.\n");
        size = _size;
        data = new T[size];
    }
    ~ExampleClass() { delete[] data; data = nullptr; }

    std::string toString() const noexcept;

    inline int getSize() const noexcept;
    inline void setValue(size_t pos, T value);
    inline T getValue(size_t pos) const;

    void setRandValues(int min, int max) noexcept;

    friend std::ostream& operator<< <T>(std::ostream& out,
        const ExampleClass<T>& obj) noexcept;
};

template <typename T>
inline int ExampleClass<T>::getSize() const noexcept {
    return size;
}

template <typename T>
inline void ExampleClass<T>::setValue(size_t pos, T value) {
    if (pos >= size || pos < 0) 
        throw std::out_of_range(
            "Dont exist such position.\n");
    data[pos] = value;
}

template <typename T>
inline T ExampleClass<T>::getValue(size_t pos) const {
    if (pos >= size || pos < 0) throw std::out_of_range("Dont exist such position.\n");
    return data[pos];
}

template <typename T>
std::string ExampleClass<T>::toString() const noexcept {
    std::string str = "";
    for (int i = 0; i < size; i++) {
        str += std::to_string(data[i]) + " ";
    }
    return str;
}

template <typename T>
void ExampleClass<T>::setRandValues(int min, int max) noexcept {
    for (int i = 0; i < size; i++) {
        data[i] = min + rand() % (max - min + 1);
    }
}

template <typename T>
std::ostream& operator<< <T>(std::ostream& out, 
    const ExampleClass<T>& obj) noexcept {
    out << obj.toString();
    return out;
}
/*****************************************************************************/

#endif  // LIB_EXAMPLE_EXAMPLE_H_
