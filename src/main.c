#include "Rte_CanIf.h"
#include <stdio.h>
#include <unistd.h> // for sleep, if on Linux

int main(void) {
    Rte_Init();

    CanIf_PduType pduTx = { .id = 0x200, .length = 8, .data = {10,20,30,40,50,60,70,80} };
    if (Rte_CanIf_Transmit(1, &pduTx) == 0) {
        printf("[APP] Transmit requested successfully.\n");
    } else {
        printf("[APP] Transmit request failed.\n");
    }

    // Simulate periodic tasks
    for (int i = 0; i < 5; i++) {
        Can_MainFunctionTx();
        Can_MainFunctionRx();
        sleep(1);  // Wait 1 sec (simulate time passing)
    }

    return 0;
}
