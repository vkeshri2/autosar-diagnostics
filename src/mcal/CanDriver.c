#include "CanDriver.h"
#include "Mcal_Cfg.h"
#include <string.h> // for memcpy
#include <stdio.h>  // for simulation printf

static CanMbxType Can_Mailboxes[CAN_MCAL_MAX_MB];

static CanIf_RxIndicationType RxIndicationCb = NULL;
static CanIf_TxConfirmationType TxConfirmationCb = NULL;

void Can_SetRxIndicationCallback(CanIf_RxIndicationType cb) {
    RxIndicationCb = cb;
}

void Can_SetTxConfirmationCallback(CanIf_TxConfirmationType cb) {
    TxConfirmationCb = cb;
}

void Can_Init(void) {
    for (int i = 0; i < CAN_MCAL_MAX_MB; i++) {
        Can_Mailboxes[i].state = CAN_MBX_IDLE;
    }
    printf("[MCAL] CAN initialized with %d mailboxes at %d baud.\n", CAN_MCAL_MAX_MB, CAN_MCAL_BAUDRATE);
}

Std_ReturnType Can_Write(uint8_t mb, const CanIf_PduType* pdu) {
    if (mb >= CAN_MCAL_MAX_MB) {
        return E_NOT_OK;
    }
    if (Can_Mailboxes[mb].state == CAN_MBX_IDLE) {
        memcpy(&Can_Mailboxes[mb].pdu, pdu, sizeof(CanIf_PduType));
        Can_Mailboxes[mb].state = CAN_MBX_TX_PENDING;
        printf("[MCAL] CAN Write requested on MB %d with ID 0x%X\n", mb, pdu->id);
        return E_OK;
    }
    return E_NOT_OK; // mailbox busy
}

void Can_MainFunctionTx(void) {
    for (int i = 0; i < CAN_MCAL_MAX_MB; i++) {
        if (Can_Mailboxes[i].state == CAN_MBX_TX_PENDING) {
            // Simulate transmission success
            Can_Mailboxes[i].state = CAN_MBX_TX_CONFIRMED;
            printf("[MCAL] CAN Transmission confirmed on MB %d\n", i);

            if (TxConfirmationCb) {
                TxConfirmationCb(i);
            }
            // Reset mailbox after confirmation
            Can_Mailboxes[i].state = CAN_MBX_IDLE;
        }
    }
}

void Can_MainFunctionRx(void) {
    // Simulate receiving a CAN frame in mailbox 0 (for demo)
    static int toggle = 0;
    if (toggle == 0) {
        CanIf_PduType rxPdu = { .id = 0x100, .length = 8, .data = {0,1,2,3,4,5,6,7} };
        printf("[MCAL] CAN Received frame ID 0x%X\n", rxPdu.id);

        if (RxIndicationCb) {
            RxIndicationCb(&rxPdu);
        }
    }
    toggle = !toggle;
}
