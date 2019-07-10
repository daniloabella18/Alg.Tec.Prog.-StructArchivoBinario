///Autor: Danilo Abellá.
///Carrera: Licenciatura en Ciencias de la Computación (LCC).
///Profesora: Rosa Berrera.
///Windows 8.0 / SO de 64 bits.
///Compilador: Code-Blocks 13.12

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/// TDA ///
struct dinosaurio
{   char nombre[30];
    short ataque;
    short aguante;
    short defensa;
    short camuflaje;
    short agilidad;
};

struct habitat
{
    char nombre[30];
    short NumDinos;
};

/// Declaracion de Funciones ///

void Escribir_Habitat ( habitat muestraH , int conth);
void Escribir_Dinosaurio ( dinosaurio muestraD , int contd);


/// Programa prinipal ///-------------------------------------------------------------------------------------------------///

int main()
{
    /// Creacion de Usuario ///

    ofstream f1 , g1;
    ifstream f2 , g2;

/// Menu ///------------------------------------------------------------------///

    /// Ingreso ///
    int NumH , contd , conth ;
    dinosaurio d , muestraD ;
    habitat h ,  muestraH ;

    /// Menu ///
    short y , c = 1 ;

    cout<<"\n\t\t\tMENU"<<endl;
    cout<<"\tOpciones:"<<endl;
    cout<<"\t(1)Ingresar habitats/dinos."<<endl;
    cout<<"\t(2)Leer habitats/dinos."<<endl;
    cout<<"\t(3)Salir."<<endl;

    while( c!=0 ){
    cout<<"\n\tIngrese numero correspondiente a cada tarea:"<<endl;
    cout<<"\tRealizar tarea #: ";
    cin>> y;
    cout<<"\n"<<endl;

    switch( y )
    {
        case 1:

        /// Ingresar ///-------------------------------------------------------------------------///

        do{
            cout<<"\tIngrese cantidad de habitats a crear:\n\tNumero de habitats:";
            cin>>NumH;
            if ( NumH < 1 )
            {   cout<<"\n\tDato Incorrecto. Ingrese un numero valido."<<endl;
            }
        }while( NumH < 1 );

            f1.open("Habitats", ios::binary | ios::app);
            g1.open("Dinos", ios::binary | ios::app);

            /// Caracterisiticas Habitat ///---------------------------------------------//
            for ( conth=0  ; conth < NumH ;  conth++ )
            {   cout<<"\n\t[Ingrese datos para habitat #"<< conth+1 <<"] "<<endl;
                cout<<"\tNombre: ";
                cin>>h.nombre;
                cout<<"\tNumero de Dinosaurios: ";
                cin>>h.NumDinos;
                cout<<"\n\tHora de ingresar las caracterisitcas para cada Dino!... \n"<<endl;

                f1.write((char *)(&h),sizeof(habitat));

                // Caracteristicas Dino //-------------------------------------------------//
                for( contd=0 ; contd < h.NumDinos ; contd++)
                {   cout<<"\n\t[Ingrese datos para dino #"<< contd+1 <<"] "<<endl;
                    cout<<"\tNombre: ";
                    cin>>d.nombre;
                    cout<<"\tAtaque: ";
                    cin>>d.ataque;
                    cout<<"\tVida: ";
                    cin>>d.aguante;
                    cout<<"\tDefenza: ";
                    cin>>d.defensa;
                    cout<<"\tNivel Camuflaje: ";
                    cin>>d.camuflaje;
                    cout<<"\tAgilidad : ";
                    cin>>d.agilidad;

                    g1.write((char *)(&d),sizeof(dinosaurio));
                }
                //-------------------------------------------------------------------------//
            }
            ///---------------------------------------------------------------------//
            g1.close();
            f1.close();

            break;

        case 2:

        /// Mostrar ///------------------------------------------------------------------------///

        f2.open("Habitats", ios::binary);
        g2.open("Dinos", ios::binary);

        if(f2.fail() || g2.fail())  {   cout<<"\tEl archivo no existe."<<endl;  }
        else
        {

            /// Habitat ///--------------------------------------------//
            f2.read((char *)(&muestraH),sizeof(habitat));
            g2.read((char *)(&muestraD) , sizeof(dinosaurio));

            for ( conth=0 ; (!f2.eof()) ; conth++ )
            {
                 if(!f2.eof()){  Escribir_Habitat ( muestraH , conth );   }

            // Dino //--------------------------------------------------//

                for ( contd=0 ; contd < muestraH.NumDinos ; contd++ )
                {   if(!g2.eof()){   Escribir_Dinosaurio( muestraD , contd );   }
                    g2.read((char *)(&muestraD) , sizeof(dinosaurio));
                }
            //--------------------------------------------------//
                f2.read((char *)(&muestraH),sizeof(habitat));
            }
            /// ---------------------------------------------------------//
        }
        g2.close(); f2.close();
        break;

///----------------------------------------------------------------------------------------------------------///

        default:
            c = 0;
            break;
    }
    }

    return 0;
}


/// Funciones ///----------------------------------------------------------------///

/// Mostrar ///

/// Habitats ///
void Escribir_Habitat ( habitat muestraH , int conth)
{   cout<<"\t[Habitat #"<< conth+1 <<"] "<<endl;
    cout<<"\tNombre: "<< muestraH.nombre <<endl;
    cout<<"\tNumero de Dinosaurios: "<< muestraH.NumDinos <<endl;
}

/// Dinos ///
 void Escribir_Dinosaurio( dinosaurio muestraD , int contd )
 {  cout<<"\n\t[Dino #"<< contd+1 <<"] "<<endl;
    cout<<"\tNombre: "<< muestraD.nombre <<endl;
    cout<<"\tAtaque:"<< muestraD.ataque <<endl;
    cout<<"\tVida: "<< muestraD.aguante <<endl;
    cout<<"\tDefenza: "<< muestraD.defensa <<endl;
    cout<<"\tNivel Camuflaje: "<< muestraD.camuflaje <<endl;
    cout<<"\tAgilidad :"<< muestraD.agilidad <<endl;
    cout<<"\n"<<endl;
 }


