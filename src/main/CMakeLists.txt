add_executable(${PROJECT_NAME} cpp/main.cpp)

set(SOURCES 
	cpp/Factory.cpp
	cpp/Supplier.cpp
	cpp/Warehouse.cpp
	cpp/Part.cpp)

add_library(Factory ${SOURCES})

target_link_libraries(${PROJECT_NAME} Factory)