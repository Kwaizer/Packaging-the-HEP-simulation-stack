# Packaging the HEP simulation stack on conda-forge
This repository summarizes a work done during IRIS-HEP 2024 Fellowship under the mentorship of<br>Dr. Matthew Feickert (the University of Wisconsin-Madison).
## Initial setup
For demostration of things added to the conda-forge ecosystem a `pixi` environment was created. It allows installation of libraries and applications in a reproducible way and also is cross-platform, which is helpful because it shows that those tools are now accessible on different platforms.
Here is an edited `pixi.toml`:
```
[project]
...
platforms = ["linux-64", "osx-64", "osx-arm64"]
version = "0.1.0"

[tasks]
lab = "jupyter lab"

[dependencies]
python = ">=3.12.6,<4"
cxx-compiler = ">=1.8.0,<2"
lhapdf = ">=6.5.4,<7"
hepmc2 = ">=2.6.11,<3"
hepmc3 = ">=3.3.0,<4"
pythia8 = ">=8.311,<9"
notebook = ">=7.2.2,<8"
jupyterlab = ">=4.2.5,<5"
uproot = ">=5.3.12,<6"
jupytext = ">=1.16.4,<2"
matplotlib = ">=3.9.2,<4"
ipympl = ">=0.9.4,<0.10"
pyhepmc = "*"
```

> [!NOTE] 
> If a tool is not available for a particular platform listed in `platforms`, `pixi` environment won't be installed
> ![image](https://github.com/user-attachments/assets/af06dcbc-e46f-4ef9-b8e1-29e2c55a8440)
## hepmc2
https://github.com/conda-forge/hepmc2-feedstock/pull/9<br>
Added and specified `aarch64`, `ppc64le` and `osx_64` platforms for a `hepmc2` package
> ![image](https://github.com/user-attachments/assets/e3a8df70-214a-42e2-94e6-f23e49ee8f3f)
#### Example usage
```
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

## hepmc3
- https://github.com/conda-forge/hepmc3-feedstock/pull/19
- Added macOS and Linux aarch64 and ppc64le builds
- Re-rendered with `{{ stdlib("c") }}`
- Updated sha256
- Refactored use of CMake in build.sh
- Added `zlib` and `bzip2` as host requirements
- Refactored `commands `due to MacOS issues
- Fallback to readlink if macOS missing greadlink (implemented with patch)
> ![image](https://github.com/user-attachments/assets/8a97a798-45c5-4673-9084-ec273e82aff2)
#### Example usage. 
```
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

## pyhepmc
https://github.com/conda-forge/pyhepmc-feedstock/pull/3
- Adding macOS and Linux aarch64 and ppc64le builds
> [!NOTE] 
> `pyhepmc` isn't on here at the moment with the macOS builds, because they are currently skipped.
###
![image](https://github.com/user-attachments/assets/c957e45e-16f4-4db0-8060-9cbf52a65dae)
#### Here is an example of a working tool
> ![image](https://github.com/user-attachments/assets/d35bbd9f-4496-4beb-809a-68d37112bd62)

