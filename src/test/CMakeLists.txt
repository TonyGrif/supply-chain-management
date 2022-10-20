enable_testing()

set(TEST_CPP_FILES cpp/main.cpp)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG	       release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
include(GoogleTest)

add_custom_target(tests)
add_executable(test_executable ${TEST_CPP_FILES})

target_link_libraries(
	test_executable
	GTest::gtest_main
)

add_dependencies(tests test_executable)
gtest_discover_tests(test_executable)
