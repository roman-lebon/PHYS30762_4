#include "particle.h"
#include <iostream>

// Default constructor
Particle::Particle() : fourmomentum() {
    std::cout << "Calling Particle default constructor\n";
    name = "unknown";
}

// Parameterized constructor
Particle::Particle(std::string n, double E, double p_x, double p_y, double p_z) : fourmomentum(E, p_x, p_y, p_z) {
    std::cout << "Calling particle paramterized constructor\n";
    name = n;
}

// Destructor
Particle::~Particle() {
    std::cout << "Calling particle destructor\n";
}

