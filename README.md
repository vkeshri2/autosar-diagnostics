# AUTOSAR Diagnostic Stack 🚗🧰  
A minimal AUTOSAR-inspired diagnostic implementation with UDS service handlers, DTC simulation, and fault memory support.

![GitHub last commit](https://img.shields.io/github/last-commit/vkeshri2/autosar-diagnostics)
![GitHub license](https://img.shields.io/github/license/vkeshri2/autosar-diagnostics)

---

## 📚 Table of Contents
- [Features](#features)
- [Folder Structure](#folder-structure)
- [How to Run](#how-to-run)
- [Architecture](#architecture)
- [Sample UDS Requests](#sample-uds-requests)
- [Contributing](#contributing)
- [LICENSE](LICENSE)

- ![Architecture](docs/architecture.png)
---

## ✅ Features

- Support for key UDS services:
  - Diagnostic Session Control (0x10)
  - ECU Reset (0x11)
  - Clear DTCs (0x14)
  - Read DTC Information (0x19)
  - ReadDataByIdentifier (0x22)
- DTC read/clear operations
- Configurable DIDs
- Fault memory simulation
- Python script for config generation

---

## 📁 Folder Structure

| Folder      | Description                                         |
|-------------|-----------------------------------------------------|
| `src/`      | Source code of the diagnostic manager               |
| `config/`   | Example config files for DIDs and DTCs              |
| `docs/`     | Design documentation and architecture diagrams      |
| `scripts/`  | Automation tools (e.g., DID config generator)       |
| `test/`     | Unit test samples for diagnostic functionality      |

---

## 🚀 How to Run

Ensure you have `gcc` installed. Then:

```bash
gcc src/*.c -o diag_test
./diag_test
