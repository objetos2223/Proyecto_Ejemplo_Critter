#include <iostream>

/**
 * @class Critter
 * @author cominf
 * @date 10/11/2016
 * @file main.cpp
 * @brief Esta clase representa una mascota virtual. 
 */
class Critter
{
private:
    int m_hambre;   // nivel del hambre
    int m_aburrido; // nivel del aburrimiento
    static int s_total;
public:
    void habla();
    Critter(int hambre = 0, int aburrido = 0);
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

/**
 * @brief Constructor del Critter
 * @param hambre es el nivel inicial de hambre
 * @param aburrido es el nivel inicial de aburrimiento
 */
Critter::Critter(int hambre, int aburrido)
: m_hambre(hambre), m_aburrido(aburrido)
{
    std::cout << "Ha nacido un nuevo critter!\n";
    s_total++;
}

/**
 * @brief Muestra el estado de ánimo del critter
 */
void Critter::habla()
{
    int animo = m_hambre + m_aburrido;
    std::cout << "Hola, soy un critter. Estoy ";
    if (animo <= 5) {  
        std::cout << "feliz\n";
    }
    else if (animo <= 10)   {
        std::cout << "okay\n";
    }
    else if (animo <= 15)   {
        std::cout << "frustrado\n";
    }
    else {
        std::cout << "furioso\n";
    }
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
    Critter crit1;
    Critter crit2(6);
    Critter crit3(3, 8);
    crit1.habla();
    crit2.habla();
    crit3.habla();
	return 0;
}
