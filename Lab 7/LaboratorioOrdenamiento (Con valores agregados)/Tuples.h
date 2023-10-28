#pragma once
#include <iostream>
using namespace std;
#include <string>

struct Tuple {
    int first;
    int last;
    std::string to_string () {
        return "(" + std::to_string(first) + "," + std::to_string(last) + ")";
    }
};
class Tuples {
public:
    void print_elements();
    void set_element_at(Tuple value, int position);
    int partition(Tuple arr[], int low, int high);
    void quickSort(Tuple arr[], int low, int high);
    void sort_elements();
    Tuples(int size){
        if (size <= 0) throw ("La lista de elementos no puede contener 0 elementos.");
        elements = new Tuple[size];
        length = size;
        Tuple _default;
        _default.first = 0;
        _default.last = 0;
        for (int i = 0; i < length; ++i) {
            elements[i] = _default;
        }
    }
private:
    Tuple * elements = nullptr;
    int length = 0;
};

