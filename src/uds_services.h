#ifndef UDS_SERVICES_H
#define UDS_SERVICES_H

#include <stdint.h>

void uds_handle_request(uint8_t sid, const void* data);

#endif
