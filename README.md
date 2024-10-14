# Packaging the HEP simulation stack on conda-forge

This repository summarizes a work done during [IRIS-HEP 2024 Fellowship](https://iris-hep.org/fellows/Kwaizer.html) under the mentorship of Dr. Matthew Feickert (University of Wisconsin-Madison).

## Initial setup

For demonstration of things added to the conda-forge ecosystem a `pixi` environment was created. It allows installation of libraries and applications in a reproducible way and also is cross-platform, which is helpful because it shows that those tools are now accessible on different platforms.

Clone the repo

```
git clone git@github.com:Kwaizer/Packaging-the-HEP-simulation-stack.git
```

Start Jupyter notebook

```
cd Packaging-the-HEP-simulation-stack
pixi run lab
```

Compile `hepmc2`/`hepmc3` code:

```
pixi run hepmc2-example
pixi run hepmc3-example
```

The binaries can be executed in notebook itself.

## [`hepmc2`](https://github.com/conda-forge/hepmc2-feedstock/)
https://github.com/conda-forge/hepmc2-feedstock/pull/9

Added and specified `aarch64`, `ppc64le` and `osx_64` platforms for a `hepmc2` package
> ![image](https://github.com/user-attachments/assets/e3a8df70-214a-42e2-94e6-f23e49ee8f3f)

#### Example usage:

```cxx
#include "HepMC/GenEvent.h"
#include "HepMC/GenParticle.h"
#include "HepMC/GenVertex.h"

int main() {

    HepMC::GenEvent event(HepMC::Units::GEV, HepMC::Units::MM);

    // Create a vertex and add it to the event
    HepMC::GenVertex* vertex = new HepMC::GenVertex();
    event.add_vertex(vertex);

    // Create a particle and add it to the vertex
    HepMC::GenParticle* particle = new HepMC::GenParticle(HepMC::FourVector(0,0,100,100), 11, 1);
    vertex->add_particle_out(particle);
    event.print();

    return 0;
}


```
>![image](https://github.com/user-attachments/assets/7eeb9db4-d6d0-476a-857c-a2983d389dbd)

## [`hepmc3`](https://github.com/conda-forge/hepmc3-feedstock)

- https://github.com/conda-forge/hepmc3-feedstock/pull/19
- Added macOS and Linux aarch64 and ppc64le builds
- Re-rendered with `{{ stdlib("c") }}`
- Updated sha256
- Refactored use of CMake in build.sh
- Added `zlib` and `bzip2` as host requirements
- Refactored `commands `due to MacOS issues
- Fallback to readlink if macOS missing greadlink (implemented with patch)
> ![image](https://github.com/user-attachments/assets/8a97a798-45c5-4673-9084-ec273e82aff2)

#### Example usage:

```cxx
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"

int main() {
    HepMC3::GenEvent evt;
    auto vtx = std::make_shared<HepMC3::GenVertex>();
    auto p = std::make_shared<HepMC3::GenParticle>();
    vtx->add_particle_out(p);
    evt.add_vertex(vtx);
    std::cout << "Event created with " << evt.vertices().size() << " vertices." << std::endl;
    return 0;
}

```
>![image](https://github.com/user-attachments/assets/db0bb6eb-817e-4a4d-b97e-8956d87960af)

## [`pyhepmc`](https://github.com/conda-forge/pyhepmc-feedstock)

https://github.com/conda-forge/pyhepmc-feedstock/pull/3
- Adding macOS and Linux `aarch64` and `ppc64le` builds

![image](https://github.com/user-attachments/assets/c957e45e-16f4-4db0-8060-9cbf52a65dae)

#### Here is an example of a working tool:

```python
import pyhepmc

# Create a HepMC3 event
event = pyhepmc.GenEvent()

# Create a vertex and a particle
vertex = pyhepmc.GenVertex(position=(0, 0, 0, 0))  # (x, y, z, t)
particle = pyhepmc.GenParticle(momentum=(0, 0, 100, 100), pid=2212, status=1)  # Proton

# Add particle to vertex and vertex to event
vertex.add_particle_out(particle)
event.add_vertex(vertex)

print(f"Number of vertices: {len(event.vertices)}")
print(f"Number of particles: {len(event.particles)}")
```
> ![image](https://github.com/user-attachments/assets/d35bbd9f-4496-4beb-809a-68d37112bd62)


## Acknowledgements

This work was supported by the United States National Science Foundation under Cooperative Agreements PHY-2323298 (Institute for Research and Innovation in Software for High Energy Physics) [![NSF-2323298](https://img.shields.io/badge/NSF-2323298-blue.svg)](https://nsf.gov/awardsearch/showAward?AWD_ID=2323298)
