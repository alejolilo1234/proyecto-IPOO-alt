#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

#include"./Headers/Personaje.h"
#include"./Headers/Personajes/Conejo.h"

bool play = true;
string name;
string matrix[5][4] = 
{
{"IZQUIERDA","BARCA","","DERECHA"},
{"Robot","","",""},
{"Zorro","","",""},
{"Conejo","","",""},
{"Lechuga","","",""}
};

void pedirNombre();
void enunciado();
void crearInterfaz();
void mover();
void clear();

int main()
{
  pedirNombre();

  enunciado();

  crearInterfaz();

  return 0;
}

void pedirNombre()
{
  cout << "¿Cual es tu nombre? "; getline(cin,name);
  if(name == "")
  {
    name = "JUGADOR";
  }
}

void enunciado()
{
  cout << "\n¡Bienvenido " << name <<  "!\n\nEres un Robot y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la barca solo caben dos individuos, y uno de ellos debes ser tú, para pilotarla. Las órdenes que puedes dar son:\n\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte\n\n";
}

void crearInterfaz()
{
  while(play == true)
  {
    for(int i = 0; i < 49; i++) cout << "-"; cout << endl;

    for(int i = 0; i < 5; i++)
    {
      cout << "| ";
      for(int j = 0; j < 4; j++)
      {
        if(matrix[i][j].length() < 9)
        {
          int espacios = 9 - matrix[i][j].length(); cout << matrix[i][j];

          for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
        } 
        else cout << matrix[i][j] << " | ";
      }
      cout << endl;
    }
    for(int i = 0; i < 49; i++) cout << "-"; cout << endl;

    mover();
  }
}

void mover()
{
  string mover;

  cout << "\n¿Que desea mover? "; getline(cin,mover);

  //Si ninguna letra esta
  if((mover != "B" || mover != "b") || (mover != "R" || mover != "r") || (mover != "Z" || mover != "z") || (mover != "C" || mover != "c") || (mover != "L" || mover != "l") || (mover != "Q" || mover != "q"))
  {
    system("clear");
    cout << "No " << name << ", recuerda que solo puedes ingresar las letras B, R, Z, C, L y Q." << endl << endl;
  }
  //Para BARCA
  if((mover == "B" || mover == "b") && matrix[0][2] == "")
  {
    matrix[0][1] = "";
    matrix[0][2] = "BARCA";
    clear();
  }
  else if((mover == "B" || mover == "b") && matrix[0][2] == "BARCA")
  {
    matrix[0][1] = "BARCA";
    matrix[0][2] = "";
    clear();
  }
  //Para Robot
  if((mover == "R" || mover == "r") && matrix[1][1] == "")
  {
    matrix[1][0] = "";
    matrix[1][1] = "Robot";
    clear();
  }
  else if((mover == "R" || mover == "r") && matrix[1][1] == "Robot")
  {
    matrix[1][0] = "Robot";
    matrix[1][1] = "";
    clear();
  }
  //Para Zorro
  if((mover == "Z" || mover == "z") && matrix[2][1] == "")
  {
    matrix[2][0] = "";
    matrix[2][1] = "Zorro";
    clear();
  }
  else if((mover == "Z" || mover == "z") && matrix[2][1] == "Zorro")
  {
    matrix[2][0] = "Zorro";
    matrix[2][1] = "";
    clear();
  }
  //Para rendirse
  if(mover == "Q" || mover == "q")
  {
    play = false;
    system("clear");
    cout << "PERDISTE :C" << endl;
  }
  // cout << endl;
}
void clear()
{
  system("clear");
  cout << "B = Barca, Z = Zorro" << endl <<endl;
  crearInterfaz();
}