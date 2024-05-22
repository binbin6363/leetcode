set(TARGET btree)

file(GLOB sources turn_btree.cpp)
file(GLOB utils ../utils/*)

add_executable(${TARGET}
    ${sources}
    ${utils}
)

target_include_directories(${TARGET} PUBLIC  ../)
