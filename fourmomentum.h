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

        // Print function
        void print() const;

        // Getters - user should not access the vector directly as internal ordering is an implementation detail
        double getE() const;
        double getp_x() const;
        double getp_y() const;
        double getp_z() const;

        // Setters
        void setE(double E); // Validates that energy is non-negative
        void setp_x(double p_x);
        void setp_y(double p_y);
        void setp_z(double p_z);
};

#endif