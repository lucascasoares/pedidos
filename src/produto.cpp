#include "produto.h"
#include <spdlog/spdlog.h>

Produto::Produto(int id, const std::string& nome, float preco) {
    if (id <= 0) {
        throw std::invalid_argument("ID do produto não pode ser menor do que zero");
    }
    if (preco <= 0) {
        throw std::invalid_argument("O preço do produto não pode ser menor do que zero");
    }
    this->id = id;
    this->preco = preco;
    this->nome = nome;
    spdlog::info("Produto criado com sucesso");
}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

float Produto::getPreco() const {
    return preco;
}
