set(TARGET btree)

file(GLOB sources *)
file(GLOB utils ../utils/*)

add_executable(${TARGET}
    ${sources}
    ${utils}
)

target_include_directories(${TARGET} PUBLIC  ../)
