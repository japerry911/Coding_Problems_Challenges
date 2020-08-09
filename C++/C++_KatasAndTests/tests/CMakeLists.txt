include(ExternalProject)
find_package(Threads)

# Googletest
ExternalProject_Add(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.1
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/googletest
        INSTALL_COMMAND "" # Disable install step
        #TEST_BEFORE_INSTALL 1
        UPDATE_COMMAND "" # Don't need to update since using tagged release
        CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        BUILD_BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/googletest/libgtest_main.a ${CMAKE_CURRENT_BINARY_DIR}/googletest/libgtest.a
        )

add_library(gtest_main STATIC IMPORTED GLOBAL)
add_dependencies(gtest_main googletest)
add_library(gtest STATIC IMPORTED GLOBAL)
add_dependencies(gtest googletest)

ExternalProject_Get_Property(googletest source_dir binary_dir)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION
        ${binary_dir}/googlemock/gtest/libgtest_main.a)
set_property(TARGET gtest_main PROPERTY IMPORTED_LINK_INTERFACE
        ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET gtest_main PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        ${source_dir}/googletest/include)

set_property(TARGET gtest PROPERTY IMPORTED_LOCATION
        ${binary_dir}/googlemock/gtest/libgtest.a)
set_property(TARGET gtest PROPERTY IMPORTED_LINK_INTERFACE
        ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET gtest PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        ${source_dir}/googletest/include)

# Workaround for INTERFACE_INCLUDE_DIRECTORIES. The problem is the include
# directory needs to exist at cmake configuration time even though it won't
# exist until the external project is checked out at build time.
file(MAKE_DIRECTORY ${source_dir}/googletest/include)

# googletest triggers some warnings via macro includes, suppress them
if("${CMAKE_C_COMPILER}" MATCHES "clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-global-constructors")
endif()

add_executable(unit_tests ../CodeWars.cpp ../CodeWars.h CodeWarsTests.cpp)
include_directories(${PROJECT_SOURCE_DIR})

target_link_libraries(unit_tests
        gtest
        gtest_main
        ${CMAKE_THREAD_LIBS_INIT}
        )