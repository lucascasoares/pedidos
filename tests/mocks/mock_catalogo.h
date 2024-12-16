#ifndef MOCK_CATALOGO_H
#define MOCK_CATALOGO_H

#include <gmock/gmock.h>
#include "produto.h"
#include "catalogo.h"

class MockCatalogo : public Catalogo {
    public:
        MOCK_METHOD(void, adicionarProduto, (const Produto& produto), (override));
        MOCK_METHOD(void, listarProdutos, (), (const, override));
        MOCK_METHOD(const Produto*, buscarProdutoPorId, (int id), (const, override));
};

#endif
