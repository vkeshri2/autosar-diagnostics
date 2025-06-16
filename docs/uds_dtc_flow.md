# UDS and DTC Flow

This document outlines the flow of UDS diagnostic requests and how they interact with the DTC system.

1. Tester sends UDS service (e.g., 0x10)
2. Stack routes to service handler
3. If DTC-related, invokes DTC manager
