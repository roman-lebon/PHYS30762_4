#include "particle.h"
#include <iostream>
#include <vector>

// Vector containing valid SM particle names
const std::vector<std::string> valid_particles {
    "electron", "muon", "tau", "antielectron", "antimuon", "antitau", "electron neutrino", "muon neutrino", "tau neutrino",
    "photon", "Z boson", "W boson", "Higgs boson", "up quark", "down quark", "charm quark", "strange quark", "top quark", "bottom quark"};

// Default constructor
Particle::Particle() : fourmomentum() {
    std::cout << "Calling Particle default constructor\n";
    name = "unknown";
}

// Parameterized constructor
Particle::Particle(std::string n, double E, double p_x, double p_y, double p_z) : fourmomentum(E, p_x, p_y, p_z) {
    std::cout << "Calling Particle parameterized constructor\n";
    set_name(n); 
}

// Destructor
Particle::~Particle() {
    std::cout << "Calling Particle destructor\n";
}

// Print function
void Particle::print() const {
    std::cout << "Particle: " << name << "\n";
    fourmomentum.print(); // Delegates to FourMomentum print function
}

// Getters
std::string Particle::get_name() const { return name; }
double Particle::getE() const { return fourmomentum.getE(); }
double Particle::getp_x() const { return fourmomentum.getp_x(); }
double Particle::getp_y() const { return fourmomentum.getp_y(); }
double Particle::getp_z() const { return fourmomentum.getp_z(); }

// Setters
void Particle::set_name(std::string n) {
    // Validation loop checks if name is in the accepted list
    for (const std::string& p : valid_particles) {
        if (p == n) {
            name = n;
            return;
        }
    }
    // Program exits if not
    std::cout << "-> Invalid particle name: " << n << ". Not a recognised Standard Model particle.\n";
    exit(1);
}

void Particle::setE(double E) { fourmomentum.setE(E); }
void Particle::setp_x(double p_x) { fourmomentum.setp_x(p_x); }
void Particle::setp_y(double p_y) { fourmomentum.setp_y(p_y); }
void Particle::setp_z(double p_z) { fourmomentum.setp_z(p_z); }

