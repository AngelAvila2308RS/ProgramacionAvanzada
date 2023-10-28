#include "Tuples.h"
#include <iostream>

void Tuples::set_element_at(Tuple value, int position) {
    if (position >= length || position < 0) throw ("La posicion indicada es invalida.");
    elements[position] = value;

}


void Tuples::print_elements() {
    for (int i = 0; i <= length; ++i) {
        std::cout << elements[i].to_string() << " ";
    }
    std::cout << std::endl;
}

int partition(Tuple arr[], int low, int high) {
    Tuple pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if ((arr[j].first + arr[j].last) <= (pivot.first + pivot.last)) {
            i++;
            Tuple temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Tuple temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Tuple arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Tuples::sort_elements() {
    quickSort(elements, 0, length - 1);
}