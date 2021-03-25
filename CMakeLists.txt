cmake_minimum_required(VERSION 3.10)

project(eopi)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

file(GLOB_RECURSE eopi_SOURCES src/*.cpp )
file(GLOB_RECURSE eopi_HEADERS include/*.hpp)

include_directories(include)

foreach( testsourcefile ${eopi_SOURCES} )

    get_filename_component(testname ${testsourcefile} NAME)
    string( REPLACE ".cpp" "" testname ${testname} )

    add_executable( ${testname} ${testsourcefile} )
    target_compile_features(${testname} PRIVATE cxx_std_17)

endforeach( testsourcefile ${eopi_SOURCES} )