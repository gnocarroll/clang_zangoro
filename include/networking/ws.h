#ifndef WS_H
#define WS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int websocketpp_connect(const char *url);
int websocketpp_send(int conn_id, const void *msg, size_t count);
int websocketpp_recv(int conn_id, const void *buf, size_t max);
int websocketpp_close(int conn_id);

#ifdef __cplusplus
}
#endif

#endif // WS_H
