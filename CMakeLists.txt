cmake_minimum_required(VERSION 3.10)
project(Pedidos)
add_subdirectory(googletest)
add_subdirectory(spdlog)

include_directories(src tests/mocks)

add_executable(TestesIntegracao tests/testes_integracao.cpp src/produto.cpp src/catalogo.cpp src/pedido.cpp)
target_link_libraries(TestesIntegracao gtest gtest_main gmock gmock_main spdlog)

add_executable(TestesUnitarios tests/testes_unitarios.cpp src/produto.cpp src/catalogo.cpp src/pedido.cpp)
target_link_libraries(TestesUnitarios gtest gtest_main gmock gmock_main spdlog)
