#include <iostream>
#include "fourmomentum.h"
#include "particle.h"

int main() {

    Particle a("electron", 100.0, 1.0, 2.0, 3.0);
    Particle b("electron", 50.0, 0.5, 0.5, 0.5);
    Particle c = a + b;
    c.print();
    std::cout << "Dot product = " << a.dotProduct(b) << " MeV^2\n";

}