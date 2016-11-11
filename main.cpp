#include <iostream>
#include <vector>

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
    void transcurreTiempo(int tiempo = 1);
public:
    void habla();
    Critter(int hambre = 0, int aburrido = 0);
    void comer(int comida = 4);
    void jugar(int tiempo = 3); // tarea
    void setHambre(int hambre);
    int getHambre() const;
    static int getTotal();
};

class Granja
{
private:
    std::vector<Critter> m_critters;
public:
    Granja();
    void agrega(const Critter& nuevo);
    void imprime();
};

Granja::Granja()
{
    std::cout << "Se ha creado la granja de critters!\n";
    std::cout << "La ganja está vacía\n";
}

void Granja::agrega(const Critter& nuevo)
{
    m_critters.push_back(nuevo);
}

void Granja::imprime()
{
    for (unsigned int i = 0; i < m_critters.size(); i++) {
        m_critters[i].habla();
    }
}

/**
 * @brief Incrementa el nivel de hambre y de aburrimiento
 * @param tiempo Cantidad del incremento de hambre y aburrimiento
 */
void Critter::transcurreTiempo(int tiempo)
{
    m_aburrido += tiempo;
    m_hambre += tiempo;
}

/**
 * @brief Juega un determinado tiempo con el critter y disminuye
 *        su nivel de aburrimiento.
 * @param tiempo
 */
void Critter::jugar(int tiempo)
{
    std::cout << "Yupiii\n";
    m_aburrido -= tiempo;
    if (m_aburrido < 0) {
        m_aburrido = 0;
    }
}

/**
 * @brief Alimenta al critter disminuyendo su nivel de hambre
 * @param comida Es la cantidad de alimento para disminuir el hambre
 */
void Critter::comer(int comida)
{
    std::cout << "Yumiii\n";
    m_hambre -= comida;
    if (m_hambre < 0)   {
        m_hambre = 0;
    }
}

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
    transcurreTiempo();
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

void pruebaGranja()
{
    Granja granjaCritters;
    Critter c1, c2(6,8), c3(7);
    
    granjaCritters.agrega(c1);
    granjaCritters.agrega(c2);
    granjaCritters.agrega(c3);
    granjaCritters.imprime();
}

void pruebaCritter()
{
    int opcion;
    Critter crit;
    
    do
    {
        std::cout << "1 - Hablar con el critter\n";
        std::cout << "2 - Alimentar al critter\n";
        std::cout << "3 - Jugar con el critter\n";
        std::cout << "0 - Salir\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1 : crit.habla();
            break;
            case 2 : crit.comer();
            break;
            case 3 : crit.jugar();
            break;
        }
    }   while (opcion != 0);
}

int main(int argc, char **argv)
{
//    pruebaCritter();
    pruebaGranja();
	return 0;
}
