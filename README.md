# autosar-diagnostics
A sample diagnostic stack for AUTOSAR-based ECUs with UDS service implementations and DTC handling.

# AUTOSAR Diagnostic Stack

This repository contains a simplified implementation of a UDS-based diagnostic stack, inspired by AUTOSAR architecture. It includes basic services, DTC handling, and example configuration files.

## Features
- Support for key UDS services (0x10, 0x11, 0x14, 0x19, 0x22, etc.)
- DTC read/clear
- Configurable DIDs
- Fault memory simulation
- Python script for config generation

## Folder Structure
- `src/`: Source code of the diagnostic manager
- `config/`: Example config files for DIDs and DTCs
- `docs/`: Design documentation
- `scripts/`: Automation tools (e.g., DID generator)
- `test/`: Unit test samples

## How to Run
```sh
gcc src/*.c -o diag_test
./diag_test
