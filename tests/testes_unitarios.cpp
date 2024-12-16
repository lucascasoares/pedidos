#include <gtest/gtest.h>
#include "produto.h"
#include "mock_produto.h"
#include "mock_catalogo.h"
#include "mock_pedido.h"

using ::testing::_;
using ::testing::Return;

TEST(CatalogoTest, TesteAdicionarProduto) {
    MockCatalogo mockCatalogo;

    EXPECT_CALL(mockCatalogo, adicionarProduto(::testing::_)).Times(1);

    Produto produto(1, "PS5", 3000.00f);
 
    mockCatalogo.adicionarProduto(produto);

    EXPECT_CALL(mockCatalogo, buscarProdutoPorId(1)).WillOnce(Return(&produto));
    EXPECT_EQ(mockCatalogo.buscarProdutoPorId(1)->getNome(), "PS5");
}

TEST(PedidoTest, TesteCalcularTotalSemDesconto) {
    MockPedido mockPedido("Cliente 1");

    EXPECT_CALL(mockPedido, adicionarProduto(::testing::_, ::testing::_)).Times(2);

    Produto produto1(1, "Jogo Need For Speed", 40.00f);
    Produto produto2(2, "Jogo God of War", 50.00f);

    mockPedido.adicionarProduto(produto1, 1);
    mockPedido.adicionarProduto(produto2, 1);

    EXPECT_CALL(mockPedido, calcularTotal()).WillOnce(Return(90.00f));
    EXPECT_EQ(mockPedido.calcularTotal(), 90.00f);
}

TEST(PedidoTest, TesteCalcularTotalComDesconto) {
    MockPedido mockPedido("Cliente 2");

    EXPECT_CALL(mockPedido, adicionarProduto(::testing::_, ::testing::_)).Times(2);

    Produto produto1(1, "PS5", 3000.00f);
    Produto produto2(2, "Controle PS5", 300.00f);

    mockPedido.adicionarProduto(produto1, 1);
    mockPedido.adicionarProduto(produto2, 1);

    EXPECT_CALL(mockPedido, calcularTotal()).WillOnce(Return(2970.00f));
    EXPECT_EQ(mockPedido.calcularTotal(), 2970.00f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}