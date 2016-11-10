#include <iostream>

class Critter
{
private:
    int m_hambre;
    static int s_total;
public:
    void saluda();
    Critter(int hambre = 0);
    void setHambre(int hambre);
    int getHambre() const;
    static int getTotal();
};

// inicializacion de la variable estatica
int Critter::s_total = 0;

int Critter::getTotal()
{
//     no es valido porque la variable pertenece a un objeto
//    std::cout << "Nivel de hambre " << m_hambre;
    return s_total;
}

Critter::Critter(int hambre)
{
    std::cout << "Ha nacido un nuevo critter!\n";
    m_hambre = hambre;
    s_total++;
}

void Critter::saluda()
{
    std::cout << "Hola, soy un critter. Mi nivel de hambre es "
                << m_hambre << std::endl;
}

int Critter::getHambre() const
{
    return m_hambre;
}

void Critter::setHambre(int hambre)
{
    if (hambre < 0) {
        std::cout << "El nivel del hambre tiene que ser positivo\n";
    }
    else    {
        m_hambre = hambre;
    }
}

int main(int argc, char **argv)
{
    Critter crit1(9);
    Critter crit2;
    Critter crit3;
    
    crit1.saluda();
    
    crit2.setHambre(-3);
    crit2.saluda();
    std::cout << "El nivel de hambre es " << crit2.getHambre() << std::endl;
    std::cout << "Total de critters creados " << Critter::getTotal() << std::endl;
	return 0;
}
