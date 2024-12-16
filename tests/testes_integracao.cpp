#include <spdlog/spdlog.h>
#include "produto.h"
#include "catalogo.h"
#include "pedido.h"
#include <iostream>

int main() {
    Produto produto1(1, "PS5", 3000.00f);
    Produto produto2(2, "Controle PS5", 300.00f);
    Produto produto3(3, "Jogo", 49.00f);

    Catalogo catalogo;
    catalogo.adicionarProduto(produto1);
    catalogo.adicionarProduto(produto2);
    catalogo.adicionarProduto(produto3);

    // Pedido que não supera R$100,00, logo não tem desconto
    Pedido pedido1("Lucas Soares");
    pedido1.adicionarProduto(produto3, 2);
    int totalPedido1 = pedido1.calcularTotal();
    std::cout << "Valor total do pedido 1: " << totalPedido1 << std::endl;

    // Pedido que supera R$100,00, logo com desconto de 10%
    Pedido pedido2("Lucas Soares");
    pedido2.adicionarProduto(produto1, 1);
    pedido2.adicionarProduto(produto2, 2);
    pedido2.adicionarProduto(produto3, 2);
    int totalPedido2 = pedido2.calcularTotal();
    std::cout << "Valor total do pedido 2: " << totalPedido2 << std::endl;

    return 0;
}