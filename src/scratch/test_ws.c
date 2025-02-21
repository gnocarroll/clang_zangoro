#include "scratch/test_ws.h"

#include <stdio.h>

#include "networking/ws.h"

#include <unistd.h>

void test_ws(void) {
    fprintf(stderr, "trying to connect to ws server");
    
    int id = websocketpp_connect("ws://localhost:5005");

    if (id == -1) {
        fprintf(stderr, "connecting to ws server failed\n");
        return;
    }

    sleep(1);

    char msg[] = "hello\n";

    fprintf(stderr, "will send msg: %s\n", msg);
    int send_ret = websocketpp_send(id, msg, sizeof(msg) - 1);

    printf("SEND RETURNED: %d\n", send_ret);

    // int websocketpp_recv(int conn_id, const void *buf, size_t max);
    
    printf("CLOSE RETURNED: %d\n", websocketpp_close(id));
}
