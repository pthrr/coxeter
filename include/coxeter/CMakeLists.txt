add_library(${PROJECT_NAME} INTERFACE ${${PROJECT_NAME}_HEADER})
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} INTERFACE xtensor xtensor-blas)
target_include_directories(${PROJECT_NAME} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                                            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
