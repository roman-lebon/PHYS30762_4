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
};

#endif