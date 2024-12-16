#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "produto.h"

class Catalogo {
    private:
        std::vector<Produto> produtos;

    public:
        virtual void adicionarProduto(const Produto& produto);
        virtual void listarProdutos() const;
        virtual const Produto* buscarProdutoPorId(int id) const;
};

#endif
