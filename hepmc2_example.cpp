#include "HepMC/GenEvent.h"
#include "HepMC/GenParticle.h"
#include "HepMC/GenVertex.h"
#include <iostream>

int main() {
    // Create a HepMC event
    HepMC::GenEvent event(HepMC::Units::GEV, HepMC::Units::MM);

    // Create a vertex and add it to the event
    HepMC::GenVertex* vertex = new HepMC::GenVertex();
    event.add_vertex(vertex);

    // Create a particle and add it to the vertex
    HepMC::GenParticle* particle = new HepMC::GenParticle(HepMC::FourVector(0,0,100,100), 11, 1);
    vertex->add_particle_out(particle);

    // Print the event
    event.print();

    return 0;
}
