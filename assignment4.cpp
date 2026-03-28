#include <iostream>
#include "fourmomentum.h"
#include "particle.h"

int main() {

    FourMomentum a(100.0, 1.0, 2.0, 3.0);
    FourMomentum b(50.0, 0.5, 0.5, 0.5);
    b = std::move(a); // Move assignment called here
    b.print();

}