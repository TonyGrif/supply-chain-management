enable_testing()
include(GoogleTest)

set(TEST_CPP_FILES 
	cpp/main.cpp
	cpp/Test_Factory.cpp
	cpp/Test_Supplier.cpp
	cpp/Test_Warehouse.cpp
	cpp/Test_Part.cpp)

add_custom_target(tests)
add_executable(test_executable ${TEST_CPP_FILES})

target_link_libraries(
	test_executable
	GTest::gtest_main
	Factory
)

add_dependencies(tests test_executable)
gtest_discover_tests(test_executable)
