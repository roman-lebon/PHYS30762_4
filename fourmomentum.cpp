#include "fourmomentum.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

// Default constructor
FourMomentum::FourMomentum() {
    std::cout << "Calling FourMomentum default constructor\n";
    components = new std::vector<double>(4, 0.0); // Allocates vector and initialises all four components to zero
}

// Parameterized constructor
FourMomentum::FourMomentum(double E, double p_x, double p_y, double p_z) {
    std::cout << "Calling FourMomentum parameterized constructor\n";

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

// Copy constructor - creates a completely independent deep copy of other
FourMomentum::FourMomentum(const FourMomentum& other) {
    std::cout << "Calling FourMomentum copy constructor\n";
    components = new std::vector<double>(*other.components); // Allocates new vector and copies all values across (deep copy)
}

// Copy assignment operator - replaces this object's data with a deep copy of other
FourMomentum& FourMomentum::operator=(const FourMomentum& other) {
    std::cout << "Calling FourMomentum copy assignment operator\n";
    if (this != &other) { // Self-assignment check: if a = a, avoids freeing memory we still need
        delete components; // Free existing memory before overwriting
        components = new std::vector<double>(*other.components); // Deep copy
    }
    return *this; // Returns reference to this object so chained assignment (a = b = c) works
}

// Move constructor - transfers ownership of other's memory to this object without copying
FourMomentum::FourMomentum(FourMomentum&& other) {
    std::cout << "Calling FourMomentum move constructor\n";
    components = other.components; // Steal the pointer - no new allocation needed
    other.components = nullptr; // Leave other in a valid empty state so its destructor doesn't double-free
}

// Move assignment operator - transfers ownership of other's memory, replacing this object's existing data
FourMomentum& FourMomentum::operator=(FourMomentum&& other) {
    std::cout << "Calling FourMomentum move assignment operator\n";
    std::swap(components, other.components); // Swap pointers - other's destructor cleans up old memory
    return *this;
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

// Overloaded + operator - adds each component and returns a new FourMomentum
FourMomentum FourMomentum::operator+(const FourMomentum& other) const {
    return FourMomentum(getE() + other.getE(), getp_x() + other.getp_x(), getp_y() + other.getp_y(), getp_z() + other.getp_z());
}

// Dot product using the (+,-,-,-) metric convention
// For a particle dotted with itself this gives m^2 (rest mass squared)
double FourMomentum::dotProduct(const FourMomentum& other) const {
    return getE() * other.getE() - getp_x() * other.getp_x() - getp_y() * other.getp_y() - getp_z() * other.getp_z();
}