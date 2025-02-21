target_sources(zangoro
    PUBLIC  ws.c
    PRIVATE websocketpp_client.cpp emscripten_client.c
)
