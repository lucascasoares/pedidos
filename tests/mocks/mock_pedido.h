#ifndef MOCK_PEDIDO_H
#define MOCK_PEDIDO_H

#include <gmock/gmock.h>
#include "produto.h"
#include "pedido.h"

class MockPedido : public Pedido {
    public:
        MockPedido(const std::string& cliente) : Pedido(cliente) {}
        MOCK_METHOD(void, adicionarProduto, (const Produto& produto, int quantidade), (override));
        MOCK_METHOD(float, calcularTotal, (), (const, override));
        MOCK_METHOD(std::string, getCliente, (), (const, override));
        MOCK_METHOD(void, listarProdutos, (), (const, override));
};

#endif
