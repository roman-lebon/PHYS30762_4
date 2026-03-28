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

    if (E < 0) {
        std::cout << "-> Invalid energy: E cannot be negative.\n";
        exit(1);
    }

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

// Print function
void FourMomentum::print() const {
    std::cout << "Four-momentum (E, p_x, p_y, p_z) = (" << getE() << ", " << getp_x() << ", " << getp_y() << ", " << getp_z() << ") MeV\n";
}

// Getters
double FourMomentum::getE() const { return (*components)[0]; }
double FourMomentum::getp_x() const { return (*components)[1]; }
double FourMomentum::getp_y() const { return (*components)[2]; }
double FourMomentum::getp_z() const { return (*components)[3]; }

// Setters
void FourMomentum::setE(double E) {
    // Validates energy is non-negative (negative energy is unphysical)
    if (E < 0) {
        std::cout << "-> Invalid energy: E cannot be negative.\n";
        exit(1);
    }
    (*components)[0] = E;
}

void FourMomentum::setp_x(double p_x) { (*components)[1] = p_x; } // Momentum components can be negative (direction)
void FourMomentum::setp_y(double p_y) { (*components)[2] = p_y; }
void FourMomentum::setp_z(double p_z) { (*components)[3] = p_z; }