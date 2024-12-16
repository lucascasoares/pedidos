#include "catalogo.h"
#include "produto.h"
#include <iostream>
#include <spdlog/spdlog.h>

void Catalogo::adicionarProduto(const Produto& produto) {
    // Verificar se um produto com mesmo nome já existe no catálogo
    for (const Produto& produtoNoCatalogo : produtos) {
        if (produto.getId() == produtoNoCatalogo.getId()) {
            spdlog::error("Produto já adicionado ao catálogo");
            return;
        }

        if (produto.getNome() == produtoNoCatalogo.getNome()) {
            spdlog::error("Já existe um produto no catálogo com esse nome");
            return;
        }
    }
    produtos.push_back(produto);
    spdlog::info("Produto adicionado ao catálogo");
}

void Catalogo::listarProdutos() const {
    for (const Produto& produto : produtos) {
        std::cout << "ID: " << produto.getId() << ", Nome: " << produto.getNome() << ", Preço: " << produto.getPreco() << std::endl;
    }
}

const Produto* Catalogo::buscarProdutoPorId(int id) const {
    for (const Produto& produto : produtos) {
        if (produto.getId() == id) {
            return &produto;
        }
    }
    spdlog::info("Erro ao buscar produto por ID");
    return nullptr;
}
