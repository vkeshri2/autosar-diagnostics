#ifndef RTE_CANIF_H
#define RTE_CANIF_H

#include "CanIf_Types.h"
#include "Std_Types.h"

Std_ReturnType Rte_CanIf_Transmit(uint8_t mb, const CanIf_PduType* pdu);
void Rte_CanIf_RxIndication(const CanIf_PduType* pdu);
void Rte_CanIf_TxConfirmation(uint8_t mb);

void Rte_Init(void);

#endif // RTE_CANIF_H
