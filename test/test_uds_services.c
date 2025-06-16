#include "../src/uds_services.h"
#include <assert.h>

void test_session_control() {
    uds_handle_request(0x10, NULL);  // Should print "Session Control Request Received"
}

int main() {
    test_session_control();
    return 0;
}
