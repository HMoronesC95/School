#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
using namespace std;

struct libro
{
  int id;
  int isbn;
  string autores;
  int anio;
  string titulo;
  string editorial;
  bool disponible;
};

struct usuario{
  int id;
  string nombre;
  int edad;
  char sexo; // m - male | f - famale
  string facultad;
  char disponible; // p - professor | s - student
};

struct prestamo{
  int id_libro;
  int id_usuario;
};

libro add_libro(int x)
{
	libro b;
	b.id = x+1;
	std::cout << "-------------------------\n     Agregando libro \n-------------------------";
	std::cout << "\n\n\n id :"<< x+1 <<" \n";
	std::cout << " (int)Dame el isbn: "; std::cin >> b.isbn;
	std::cout << " (string)Dame los autores: "; std::cin >> b.autores;
	std::cout << " (int)Dame el año: "; std::cin >> b.anio;
	std::cout << " (string)Dame el titulo: "; std::cin >> b.titulo;
	std::cout << " (string)Dame la editorial: "; std::cin >> b.editorial;
	std::cout << " (bool) Disponible: true";
	b.disponible = true;

	return b;
}

usuario add_usuario(int x)
{
	usuario c;
	c.id = x+1;
	std::cout << "-------------------------\n     Agregando cliente \n-------------------------";
	std::cout << "\n\n\n id :"<< x+1 <<" \n";
	std::cout << " Nombre: "; std::cin >> c.nombre;
	std::cout << " (int) Edad: "; std::cin >> c.edad;
	std::cout << " (char) Sexo(m/f): "; std::cin >> c.sexo;
	std::cout << " (string) Facultad: "; std::cin >> c.facultad;
	std::cout << " (bool) Inscrito: true";
	c.disponible = true;

	return c;
}

int main()
{
  list<libro> Libro;
  list<usuario> Usuario;
  list<prestamo> Prestamo;
	//esto es un iterador, lo coloque aqui para ver si funcionaba mejor, pero no lo logre
	list<libro>::iterator it=Libro.begin();

  int op = -1;
  while(op != 0)
  {
    std::cout << "\n\nElige una de las siguientes opciones:\n1- Registra un libro\n";
	std::cout <<"2- Registra un cliente\n3- Registra un prestamo\n4- Retira prestamo\n";
	std::cout <<"5- Muestra los libros registrados\n6- Muestra los clientes registrados\n";
	std::cout <<"7- Muestra los prestamos actuales\n0 - Salir" << '\n';
    std::cin >> op;
    switch (op) {
      case 1:
      Libro.push_back(add_libro(Libro.size()));
      break;

      case 2:
      Usuario.push_back(add_usuario(Usuario.size()));
      break;
	  case 5:
		list<libro>::iterator it=Libro.begin();
  	for (it=Libro.begin();it=Libro.end();it++)
	  cout<<it<<"\n";
	  break;
    }
  }
}
