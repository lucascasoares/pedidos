#ifndef MOCK_PRODUTO_H
#define MOCK_PRODUTO_H

#include <gmock/gmock.h>
#include "produto.h"

class MockProduto : public Produto {
    public:
        MockProduto(int id, std::string nome, float preco) : Produto(id, nome, preco) {}
        MOCK_METHOD(std::string, getNome, (), (const, override));
        MOCK_METHOD(float, getPreco, (), (const, override));
};

#endif
