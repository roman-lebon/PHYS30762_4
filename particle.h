#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include "fourmomentum.h"

// Particle class - represents a standard model particle with a name and four-momentum

class Particle {
    private: // Private variables store the data describing the particle

        std::string name; // Particle name - must be a valid SM particle
        FourMomentum fourmomentum; // Four-momentum of the particle

    public:
        // Constructors
        Particle();
        Particle(std::string name, double E, double p_x, double p_y, double p_z);

        // Destructor
        ~Particle();

        // Print function
        void print() const;

        // Getters
        std::string get_name() const;
        double getE() const;
        double getp_x() const;
        double getp_y() const;
        double getp_z() const;

        // Setters
        void set_name(std::string n); // Validates name against list of accepted SM particles
        void setE(double E);
        void setp_x(double p_x);
        void setp_y(double p_y);
        void setp_z(double p_z);
};

#endif