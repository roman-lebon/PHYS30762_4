#include <iostream>
#include "fourmomentum.h"
#include "particle.h"

int main() {
    
    Particle p("electron", 100.0, 1.0, 2.0, 3.0);
    p.print();
    return 0;

}