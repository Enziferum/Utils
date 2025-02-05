cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(TESTS_NAME utils-tests)
set(SRC main.cpp EnumTests.cpp)

add_executable(${TESTS_NAME} ${SRC})
target_link_libraries(${TESTS_NAME} PUBLIC GTest::gtest_main PRIVATE utils)

include(GoogleTest)
gtest_discover_tests(${TESTS_NAME})