#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"
#include <iostream>

int main() {
    HepMC3::GenEvent evt;
    auto vtx = std::make_shared<HepMC3::GenVertex>();
    auto p = std::make_shared<HepMC3::GenParticle>();
    vtx->add_particle_out(p);
    evt.add_vertex(vtx);
    std::cout << "Event created with " << evt.vertices().size() << " vertices." << std::endl;
    return 0;
}
