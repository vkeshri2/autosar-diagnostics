#include "Rte_CanIf.h"
#include "CanDriver.h"
#include <stdio.h>

static void OnRxIndication(const CanIf_PduType* pdu) {
    printf("[RTE] RxIndication received ID 0x%X, length %d\n", pdu->id, pdu->length);
    // Further processing or signal routing here
}

static void OnTxConfirmation(uint8_t mb) {
    printf("[RTE] TxConfirmation received for MB %d\n", mb);
    // Further processing or signal routing here
}

Std_ReturnType Rte_CanIf_Transmit(uint8_t mb, const CanIf_PduType* pdu) {
    return Can_Write(mb, pdu);
}

void Rte_CanIf_RxIndication(const CanIf_PduType* pdu) {
    OnRxIndication(pdu);
}

void Rte_CanIf_TxConfirmation(uint8_t mb) {
    OnTxConfirmation(mb);
}

void Rte_Init(void) {
    Can_Init();
    Can_SetRxIndicationCallback(Rte_CanIf_RxIndication);
    Can_SetTxConfirmationCallback(Rte_CanIf_TxConfirmation);
    printf("[RTE] Initialized and callbacks set.\n");
}
