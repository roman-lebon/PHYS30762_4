#include <iostream>
#include "fourmomentum.h"

int main() {
    FourMomentum p(-50.0, 1.0, 2.0, 3.0);
    p.print();
    std::cout << "E = " << p.getE() << "\n";
    std::cout << "p_x = " << p.getp_x() << "\n";
    return 0;
}