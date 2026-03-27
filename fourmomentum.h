#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <vector>

// FourMomentum class representing the relativistic four-momentum P = (E, p_x, p_y, p_z)
// Uses natural units where c = 1; energy and momentum both measured in MeV

class FourMomentum {
    private: // Private variable stores the four components
        std::vector<double>* components; // Pointer to dynamically allocated vector storing [E, p_x, p_y, p_z] in that order

    public:
        // Constructors
        FourMomentum();
        FourMomentum(double E, double p_x, double p_y, double p_z);

        // Destructor
        ~FourMomentum();
};

#endif