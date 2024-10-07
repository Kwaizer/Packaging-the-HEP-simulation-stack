import pyhepmc

# Create a HepMC3 event
event = pyhepmc.GenEvent()

# Create a vertex and a particle
vertex = pyhepmc.GenVertex(position=(0, 0, 0, 0))  # (x, y, z, t)
particle = pyhepmc.GenParticle(momentum=(0, 0, 100, 100), pid=2212, status=1)  # Proton

# Add particle to vertex and vertex to event
vertex.add_particle_out(particle)
event.add_vertex(vertex)

print(f"\nNumber of vertices: {len(event.vertices)}")
print(f"Number of particles: {len(event.particles)}")
