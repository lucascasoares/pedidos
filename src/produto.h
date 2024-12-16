#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
    private:
        int id;
        std::string nome;
        float preco;

    public:
        Produto(int id, const std::string& nome, float preco);

        virtual int getId() const;
        virtual std::string getNome() const;
        virtual float getPreco() const;
};

#endif