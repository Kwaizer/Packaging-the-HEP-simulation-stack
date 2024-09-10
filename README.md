# Packaging the HEP simulation stack on conda-forge
## hepmc2
https://github.com/conda-forge/hepmc2-feedstock/pull/9<br>
Adding `aarch64` and `ppc64le` platforms for a `hepmc2` package
> ![image](https://github.com/user-attachments/assets/e3a8df70-214a-42e2-94e6-f23e49ee8f3f)
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
## pyhepmc
https://github.com/conda-forge/pyhepmc-feedstock/pull/3<br>
> ![image](https://github.com/user-attachments/assets/c957e45e-16f4-4db0-8060-9cbf52a65dae)
