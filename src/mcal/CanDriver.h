#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include "CanIf_Types.h"
#include "Std_Types.h"

typedef enum {
    CAN_MBX_IDLE = 0,
    CAN_MBX_TX_PENDING,
    CAN_MBX_TX_CONFIRMED,
    CAN_MBX_RX_READY
} CanMbx_StateType;

typedef struct {
    CanMbx_StateType state;
    CanIf_PduType   pdu;
} CanMbxType;

void Can_Init(void);
Std_ReturnType Can_Write(uint8_t mb, const CanIf_PduType* pdu);
void Can_MainFunctionTx(void);
void Can_MainFunctionRx(void);

void Can_SetRxIndicationCallback(CanIf_RxIndicationType cb);
void Can_SetTxConfirmationCallback(CanIf_TxConfirmationType cb);

#endif // CAN_DRIVER_H
