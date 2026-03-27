#include "fourmomentum.h"
#include <iostream>
#include <cstdlib>

// Default constructor
FourMomentum::FourMomentum() {
    std::cout << "Calling FourMomentum default constructor\n";
    components = new std::vector<double>(4, 0.0); // Allocates vector and initialises all four components to zero
}

// Parameterised constructor
FourMomentum::FourMomentum(double E, double p_x, double p_y, double p_z) {
    std::cout << "Calling FourMomentum parameterised constructor\n";
    components = new std::vector<double>(); // Allocate empty vector
    components->push_back(E);
    components->push_back(p_x);
    components->push_back(p_y);
    components->push_back(p_z);
}

// Destructor
FourMomentum::~FourMomentum() {
    std::cout << "Calling FourMomentum destructor\n";
    delete components; // Frees the dynamically allocated vector to prevent memory leak
}