#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

#include"./Headers/Personaje.h"
#include"./Headers/Personajes/Conejo.h"

bool play = true;
string interfaz[5][4] = 
{
{"IZQUIERDA","BARCA","","DERECHA"},
{"Robot","","",""},
{"Zorro","","",""},
{"Conejo","","",""},
{"Lechuga","","",""}
};


void enunciado();
void crearInterfaz();
void mover();
void clear();

int main()
{
  enunciado();

  crearInterfaz();


  return 0;
}

void enunciado()
{
  cout << "\nEres un Robot y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la barca solo caben dos individuos, y uno de ellos debes ser tú, para pilotarla. Las órdenes que puedes dar son:\n\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte\n\n";
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
        if(interfaz[i][j].length() < 9)
        {
          int espacios = 9 - interfaz[i][j].length(); cout << interfaz[i][j];

          for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
        } 
        else cout << interfaz[i][j] << " | ";
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
    cout << "Error" << endl;
  }
  //Para BARCA
  if((mover == "B" || mover == "b") && interfaz[0][2] == "")
  {
    interfaz[0][1] = "";
    interfaz[0][2] = "BARCA";
    clear();
  }
  else if((mover == "B" || mover == "b") && interfaz[0][2] == "BARCA")
  {
    interfaz[0][1] = "BARCA";
    interfaz[0][2] = "";
    clear();
  }
  //Para Robot
  if((mover == "R" || mover == "r") && interfaz[1][1] == "")
  {
    interfaz[1][0] = "";
    interfaz[1][1] = "Robot";
    clear();
  }
  else if((mover == "R" || mover == "r") && interfaz[1][1] == "Robot")
  {
    interfaz[1][0] = "Robot";
    interfaz[1][1] = "";
    clear();
  }
  //Para Zorro
  if((mover == "Z" || mover == "z") && interfaz[2][1] == "")
  {
    interfaz[2][0] = "";
    interfaz[2][1] = "Zorro";
    clear();
  }
  else if((mover == "Z" || mover == "z") && interfaz[2][1] == "Zorro")
  {
    interfaz[2][0] = "Zorro";
    interfaz[2][1] = "";
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
  cout << "Juego" << endl <<endl;
  crearInterfaz();
}