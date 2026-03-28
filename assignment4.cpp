#include <iostream>
#include "fourmomentum.h"
#include "particle.h"

int main() {
    
    Particle p("electron", 100.0, 1.0, 2.0, 3.0);
    std::cout << "Particle created\n";
    return 0;

}