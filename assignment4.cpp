#include <iostream>
#include <vector>
#include "particle.h"
#include "fourmomentum.h"

int main() {

    std::cout << "[Assignment 4: Particles and Four-Momenta]\n\n";

    // Create test particles - two electrons, four muons, two taus
    // Four-momentum values use approximate rest mass energies (MeV)

    std::cout << "[Creating particles]\n\n";

    std::vector<Particle> particles;

    // Two electrons (rest mass approx. 0.511 MeV)
    particles.emplace_back("electron", 0.511, 0.1, 0.2, 0.0);
    particles.emplace_back("electron", 0.511, 0.3, 0.1, 0.1);

    // Four muons (rest mass approx. 105.66 MeV)
    particles.emplace_back("muon", 105.66, 1.0,  2.0,  3.0);
    particles.emplace_back("muon", 105.66, 2.0, -1.0,  1.0);
    particles.emplace_back("muon", 105.66, 0.5,  0.5, -0.5);
    particles.emplace_back("muon", 105.66, 1.0,  3.0,  0.0);

    // Two taus (rest mass approx. 1776.9 MeV)
    particles.emplace_back("tau", 1776.9,  5.0, 1.0,  2.0);
    particles.emplace_back("tau", 1776.9, -3.0, 4.0, -1.0);

    // Print all particles
    std::cout << "\n[All particles]\n\n";
    for(const Particle& p : particles) {
        p.print();
        std::cout << "\n";
    }

    // Sum the four-momenta of the two electrons (indices 0 and 1)
    std::cout << "[Summing four-momenta of the two electrons]\n\n";
    Particle electron_sum = particles[0] + particles[1];
    std::cout << "Result:\n";
    electron_sum.print();

    // Dot product of the first two muons (indices 2 and 3)
    std::cout << "\n[Dot product of the first two muons]\n\n";
    double muon_dot = particles[2].dotProduct(particles[3]);
    std::cout << "Dot product = " << muon_dot << " MeV^2\n";

    // Copy assignment: assign electron[0] to a new electron
    std::cout << "\n[Copy assignment: electron[0] -> new_electron]\n\n";
    Particle new_electron;
    new_electron = particles[0];
    std::cout << "new_electron after assignment:\n";
    new_electron.print();

    // Copy constructor: copy first muon to a new muon
    std::cout << "\n[Copy constructor: muon[0] -> new_muon]\n\n";
    Particle new_muon(particles[2]);
    std::cout << "new_muon after copy:\n";
    new_muon.print();

    // Move constructor: move antielectron
    std::cout << "\n[Move constructor: antielectron]\n\n";
    Particle antielectron("antielectron", 0.511, -0.1, -0.2, 0.0);
    Particle moved_antielectron(std::move(antielectron));
    std::cout << "moved_antielectron after move:\n";
    moved_antielectron.print();

    // Move assignment: move antimuon
    std::cout << "\n[Move assignment: antimuon]\n\n";
    Particle antimuon("antimuon", 105.66, 1.0, -2.0, 0.5);
    Particle moved_antimuon;
    moved_antimuon = std::move(antimuon);
    std::cout << "moved_antimuon after move:\n";
    moved_antimuon.print();

    std::cout << "\n[End of main: destructors firing]\n";

    return 0;
}