#include "uds_services.h"
#include <stdio.h>

void uds_handle_request(uint8_t sid, const void* data) {
    switch(sid) {
        case 0x10:
            printf("Session Control Request Received\n");
            break;
        default:
            printf("Unsupported Service\n");
    }
}
