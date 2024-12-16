#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <unordered_map>
#include "produto.h"

class Pedido {
    private:
        std::string cliente;
        std::unordered_map<int, std::pair<Produto, int>> produtos;

    public:
        Pedido(const std::string& cliente);
        virtual void adicionarProduto(const Produto& produto, int quantidade);
        virtual float calcularTotal() const;
        virtual std::string getCliente() const;
        virtual void listarProdutos() const;
};

#endif
