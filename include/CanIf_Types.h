#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#include "Std_Types.h"

#define CANIF_MAX_DATA_LEN 8
#define CANIF_MAX_MB       32

typedef struct {
    uint32_t id;
    uint8_t  length;
    uint8_t  data[CANIF_MAX_DATA_LEN];
} CanIf_PduType;

typedef void (*CanIf_RxIndicationType)(const CanIf_PduType* pdu);
typedef void (*CanIf_TxConfirmationType)(uint8_t mb);

#endif // CANIF_TYPES_H
