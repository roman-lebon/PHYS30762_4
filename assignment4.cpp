#include <iostream>
#include "fourmomentum.h"
#include "particle.h"

int main() {

    Particle a("electron", 100.0, 1.0, 2.0, 3.0);
    Particle b(a); 
    Particle c("muon", 105.7, 2.0, 1.0, 0.5);
    c = a;                            
    Particle d(std::move(a));     
    Particle e("tau", 1776.9, 3.0, 2.0, 1.0);
    e = std::move(c);               

}