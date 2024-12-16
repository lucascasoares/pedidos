#include "pedido.h"
#include "produto.h"
#include <iostream>
#include <spdlog/spdlog.h>
#include <unordered_map>

Pedido::Pedido(const std::string& cliente) : cliente(cliente) {
    spdlog::info("Pedido criado com sucesso");
}

void Pedido::adicionarProduto(const Produto& produto, int quantidade) {
    if (quantidade <= 0) {
        throw std::invalid_argument("A quantidade do produto não pode ser menor ou igual a zero");
    }
    auto it = produtos.find(produto.getId());
    if (it != produtos.end()) {
        it->second.second += quantidade;
    } else {
        produtos.emplace(produto.getId(), std::make_pair(produto, quantidade));
    }
    spdlog::info("Produto adicionado ao pedido com sucesso");
}

float Pedido::calcularTotal() const {
    float total = 0.0f;
    for (const auto& item : produtos) {
        total += item.second.first.getPreco() * item.second.second;
    }

    if (total > 100.0f) {
        spdlog::info("Desconto de 10% aplicado ao pedido por superar o valor de R$100,00");
        return total*0.9f;
    }
    return total;
}

std::string Pedido::getCliente() const {
    return cliente;
}

void Pedido::listarProdutos() const {
    for (const auto& item : produtos) {
        std::cout << "ID: " << item.second.first.getId() << ", Nome: " << item.second.first.getNome() << ", Preço: " << item.second.first.getPreco() << ", Quantidade: " << item.second.second << std::endl;
    }
}
