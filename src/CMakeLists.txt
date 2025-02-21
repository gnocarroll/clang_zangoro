target_sources(zangoro
    PUBLIC main.c memutils.c bitset.c events.c clock.c vectors.c
)

add_subdirectory(networking)
add_subdirectory(scratch)
