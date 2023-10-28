#include <iostream>
#include "Tuples.h"

int main() {
    // Initilisation of first Tuples...
    Tuples * myTuples = new Tuples(5);

    // Testing first Tuple
    Tuple oneTuple;
    oneTuple.first = 10;
    oneTuple.last = 30;
    myTuples->set_element_at(oneTuple, 0);

    // Printing
    myTuples->print_elements();

    std::cout << "Metodo Insertion Sort implementado: " << std::endl;
    // Sorting
    myTuples->sort_elements();

    // Printing again
    myTuples->print_elements();

}
