///Autor: Danilo Abellá.
///Carrera: Licenciatura en Ciencias de la Computación (LCC).
///Profesora: Rosa Berrera.
///Windows 8.0 / SO de 64 bits.
///Compilador: Code-Blocks.

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


/// TDAs ///-----------------------------------------------------------///
/// Lista enlazada de Dinos ( Sub-Lista )///
struct dinosaurio
{   char nombre[30];
    short ataque;
    short aguante;
    short defensa;
    short camuflaje;
    short agilidad;
    dinosaurio *sig;
};

/// Para guardar los datos extraídos del Archivo Binario ///
struct dinosaurio_archivo
{   char nombre[30];
    short ataque;
    short aguante;
    short defensa;
    short camuflaje;
    short agilidad;
};

/// Lista enlazada de Habitats ( Lista Principal ) ///
struct habitat
{   char nombre[30];
    short NumDinos;
    dinosaurio *a;
    habitat *sig;
};

/// Para guardar los datos extraídos del Archivo Binario ///
struct habitat_archivo
{
    char nombre[30];
    short NumDinos;
};

/// Objeto ///
class Usuario
{
private:
// El "nombre" y "pass" era para hacer un usuario, al final decidí dejarlo como está actualemente ///
    char nombre[30];
    char pass[20];
    habitat *p;
public:
// Declaracion de Funciones Públicas de la clase ///-------------------------------------------------------------///
    void IngresoUsuario(char *n, char *p);
    void Ingreso( char *NomH , int NumDinos , dinosaurio *k );
    dinosaurio*IngresoDino ( char *Dnom , int Datack , int Dlife , int Ddef , int Dcamu , int Dagility , dinosaurio *k);
    dinosaurio*EliminarDinos ( dinosaurio *a );
    void EliminarHabitat( char *Nombre_Habitat );
    void MostrarD( dinosaurio *d);
    void Mostrar();
    void Mostrar_x_habitat( char *nombre);
    void MostrarD_ataque( dinosaurio *d );
    void Mostrar_dino_ataque( char *nombreX );
    void Mostrar_dino_agilidad();
    int Sacar_agi( dinosaurio *d , int max_agilidad );
    void MostrarD_agilidad( dinosaurio *d , int max_agilidad );
    Usuario();
    ~Usuario();
};

/// Declaracion Funciones Externas a la Clase ///---------------///

void Escribir_Dinosaurio( dinosaurio_archivo muestraD , int contd );
void Escribir_Habitat ( habitat_archivo muestraH , int conth);

/// Constructor y Destructor ///-------------------------------------------------------------///
// C //
Usuario::Usuario()
{
    p = NULL;
}

// D //
Usuario::~Usuario()
{   habitat *q;
    dinosaurio *r;

    while(p)
    {   q=p;
        r=q->a;
        while(r)
        {
            r=q->a;
            q->a= (q->a)->sig;
            delete r;
        }
        p = p->sig;
        delete q;
    }
}



/// Programa prinipal ///-------------------------------------------------------------------------------------------------///

int main()
{
    /// Declaración de Variables ///

// Usuario //---------------------------------------//
    ifstream f2 , g2;
    Usuario D;
    char nom[30], pass[30];
// Menu ///---------------------------------------//
    short tarea , c = 1;
// Ingreso ( case :1 ) //-------------------------------------//
    char NomH[30] , Dnom[30];
    int NumDinos , NumH , conth , contd ;
    int Datack , Dlife , Ddef , Dcamu , Dagility ;
    dinosaurio *k;
// Eliminar ( case :2 ) //----------------------------------//
    char HabitatE[30];
    int i , n ;
//Extraccion Archivo Binario ( case :4 ) //-------------------//
    habitat_archivo      auxH ;
    dinosaurio_archivo   auxD ;

//----------------------------------------------------------//

    cout<<"\n\n\tBienvenido a DinosaurBattlesSimulator! "<<endl;
    cout<<"\n\tIngrese un nombre de usuario y password: "<<endl;
    cout<<"\tNombre: "; cin>>nom;
    cout<<"\tPass: ";   cin>>pass;
    D.IngresoUsuario( nom , pass );     // Solo permite darle valor a las variables "nom" y "pass".

/// Menu ///------------------------------------------------------------------///

    cout<<"\n\t\t\tMENU"<<endl;
    cout<<"\tOpciones:"<<endl;
    cout<<"\t(1)Ingresar habitats/dinos."<<endl;
    cout<<"\t(2)Eliminar habitats."<<endl;
    cout<<"\t(3)Ver habitats/dinos."<<endl;
    cout<<"\t(4)Extraer datos de Archivo Binario."<<endl;
    cout<<"\t(5)Buscar un habitat."<<endl;
    cout<<"\t(6)Mostrar dino mas poderoso de un habitat."<<endl;
    cout<<"\t(7)Mostrar el dino con mas agilidad de todos."<<endl;
    cout<<"\t(8)Salir."<<endl;


    while( c!=0 ){
    cout<<"\n\tIngrese numero correspondiente a cada tarea:"<<endl;
    cout<<"\tRealizar tarea #: ";
    cin>> tarea;
    cout<<"\n"<<endl;

    switch( tarea )
    {
        case 1:

/// Ingresar ///-------------------------------------------------------------------------///
// Pregunta cantidad de habitats a ingresar //--------------------------------------------//
        do{
            cout<<"\tIngrese cantidad de habitats a crear:\n\tNumero de habitats:";
            cin>>NumH;
            if ( NumH < 1 )
            {   cout<<"\n\tDato Incorrecto. Ingrese un numero valido."<<endl;
            }
        }while( NumH < 1 );
//---------------------------------------------------------------------------------------//
/// Caracteristicas Habitat //-----------------------------------------------------------//
            for ( conth = 0 ; conth < NumH ; conth++ )
            {   k = NULL;
                cout<<"\n\t[Ingrese datos para habitat #"<< conth+1 <<"] "<<endl;
                cout<<"\tNombre: ";                 cin>>NomH;
                cout<<"\tNumero de Dinosaurios: ";  cin>>NumDinos;
                cout<<"\n\tHora de ingresar las caracterisitcas para cada Dino!... \n"<<endl;

// Caracteristicas Dino ///---------------------------------------------------------------------//
                for( contd = 0 ; contd < NumDinos ; contd++ )                                   //
                {   cout<<"\n\t[Ingrese datos para dino #"<< contd+1 <<"] "<<endl;              //
                    cout<<"\tNombre: ";             cin>>Dnom;                                  //
                    cout<<"\tVida: ";               cin>>Dlife;                                 //
                    cout<<"\tAtaque: ";             cin>>Datack;                                //
                    cout<<"\tDefenza: ";            cin>>Ddef;                                  //
                    cout<<"\tAgilidad :";           cin>>Dagility;                              //
                    cout<<"\tNivel Camuflaje: ";    cin>>Dcamu;                                 //
                                                                                                //
                    k = D.IngresoDino( Dnom , Datack , Dlife , Ddef , Dcamu , Dagility , k );   //
                }                                                                               //
//----------------------------------------------------------------------------------------------//
                D.Ingreso( NomH , NumDinos , k );
///-----------------------------------------------------------------------------------//
            }
        break;


        case 2:
/// Eliminar ///------------------------------------------------------------------///


        cout<<"\tCuantos habitats desea eliminar? Num habitats:";
        do{ cin>>n;
            if ( n < 0) { cout<<"\n\tIngrese una cantidad valida!\n\tNum habitats:"; }
        }while( n < 0 );
        for( i=0 ; i < n ; i++)
        {   cout<<"\tIngrese el habitat que quiere eliminar: ";
            cin>>HabitatE;
            D.EliminarHabitat( HabitatE );
        }
        break;


        case 3:
/// Mosrtar ///------------------------------------------------------------------///

        D.Mostrar();

        break;

        case 4:

/// Extraccion desde Archivo Binario ///-----------------------------------------///

    f2.open("Habitats", ios::binary);
    g2.open("Dinos", ios::binary);

    if(g2.fail() || f2.fail())  {   cout<<"\tEl archivo no existe."<<endl;  }
    else
    {
        /// Habitat ///--------------------------------------------//
            f2.read((char *)(&auxH),sizeof(habitat_archivo));
            g2.read((char *)(&auxD) , sizeof(dinosaurio_archivo));

            for ( conth=0 ; (!f2.eof()) ; conth++ )
            {    k = NULL;
                 if(!f2.eof()){  Escribir_Habitat ( auxH , conth );}

            // Dino //--------------------------------------------------//
                for ( contd=0 ; contd < auxH.NumDinos ; contd++ )
                {   if(!g2.eof()){   Escribir_Dinosaurio( auxD , contd );
                    k = D.IngresoDino( auxD.nombre , auxD.ataque , auxD.aguante , auxD.defensa , auxD.camuflaje , auxD.agilidad , k );}
                    g2.read((char *)(&auxD) , sizeof(dinosaurio_archivo));
                }
            //--------------------------------------------------//
                D.Ingreso( auxH.nombre , auxH.NumDinos , k );
                f2.read((char *)(&auxH),sizeof(habitat_archivo));
            }
            /// ---------------------------------------------------------//
        }
        g2.close(); f2.close();

            break;

        case 5:

        /// Mostrar Habitat pedido ///-------------------------------------///

            cout<<"\tIngrese el habitat que quiere ver:";
            cin>>NomH;

            D.Mostrar_x_habitat( NomH );

            break;

        case 6:

            /// Muestra el dino mas poderoso de un habitat ///----------------------///

            cout<<"\tIngrese el habitat en el que quiere buscar:";
            cin>>NomH;
            D.Mostrar_dino_ataque( NomH );

            break;

        case 7 :

            /// Muestra el dino con mas agilidad de todos los habitats///----------------------///

            D.Mostrar_dino_agilidad();

        break;

    /// Salir ///---------------------------------------------------------///

        default:
            c = 0;
            break;
    }
    }
    return 0;
}






/// Funciones ///-------------------------------------------------------------------------------------------------------///

/// Usuario ///
    void Usuario::IngresoUsuario(char *nom1, char *pass1)
    {
        strcpy(nombre,nom1);
        strcpy(pass,pass1);
    }

/// Funcion Ingreso Dino///

dinosaurio*Usuario::IngresoDino( char *Dnom , int Datack , int Dlife , int Ddef , int Dcamu , int Dagility , dinosaurio *k )
{   dinosaurio *q , *r;
    q = new dinosaurio;

    // Copia Datos //--------------------------------------------------------//

    strcpy( q->nombre , Dnom );
    q->ataque = Datack;
    q->aguante = Dlife;
    q->defensa = Ddef;
    q->camuflaje = Dcamu;
    q->agilidad = Dagility;
    q->sig = k;

    if((!k) )
    {
        k = q;
    }
    else
    {   r = k->sig;
        while( r )
        {   q->sig = r;
            r = r->sig;
        }
        q-> sig -> sig = q;
        q-> sig = r;
    }
    return k;
}

/// Funcion Ingreso Habitat ///

void Usuario::Ingreso( char *NomH , int NumDinosaurios , dinosaurio *k )
{
    habitat *q , *r;
    q = new habitat;

    /// Copiando Datos ///

    strcpy( q->nombre , NomH );
    q->NumDinos = NumDinosaurios;
    q->a = k;
    q->sig = p;

    if((!p))
    {
        p = q;
    }
    else
    {   r = p->sig;
        while( r )
        {   q->sig = r;
            r = r->sig;
        }
        q-> sig -> sig = q;
        q-> sig = r;
    }
}


/// Eliminar ///----------------------------------------------------------------------------///

/// Eliminar Dinosaurio ///

dinosaurio*Usuario::EliminarDinos ( dinosaurio *a )
{
    dinosaurio *z;
    while( a != NULL)
    {
        z = a;
        a = a->sig;
        delete z;
    }
    return NULL;
}

/// Elimina Habitat ///
void Usuario::EliminarHabitat( char *Nombre_Habitat )
{   habitat *q , *r;
    int valor;

    if ( p == NULL ) /// if (!p)
    {   cout<<endl<<"\n\tLista vacia"<<endl;
    }
    else
    {
        q = p;
        if (!strcmp(p->nombre , Nombre_Habitat))
        {
            p = p->sig;
            q->a = EliminarDinos ( q->a );
            delete q;
            cout<<"\n\tBorrado Exitoso!"<<endl;
        }
        else
        {
            do{ r = q;
                q = q->sig;
                valor = strcmp(q->nombre , Nombre_Habitat);
            }while( q && valor != 0 );

            if (q)
            {
                r->sig = q->sig;
                q->a = EliminarDinos ( q->a );
                delete q;
                cout<<"\n\tBorrado Exitoso!"<<endl;
            }
            else
            {
                cout<<"\n\tEl habitat no esta en la lista\n"<<endl;
            }
        }
    }
}


/// Mostrar ///--------------------------------------------------------------------------///

void Usuario::Mostrar()
{   int cont = 1;
    habitat *q;
    q = p;

    if( p == NULL)
    {
        cout<<"\tLa lista esta vacia\n"<<endl;
    }
    else
    {
        while(q)
        {   cout<<"\n\t[Habitat #"<< cont <<"]"<<endl;
            cout<<"\tNombre: "<< q->nombre <<endl;
            cout<<"\tCantidad de Dinos: "<< q->NumDinos<<endl;
            MostrarD ( q->a );
            q = q->sig;
            cont++;
        }
    }
}

/// Dinos ///
void Usuario::MostrarD( dinosaurio *d)
{   int cont = 1;
    while(d)
    {   cout<< "\n\t[Dinosairio #"<< cont <<"]";
        cout<< "\n\tNombre: " << d->nombre;
        cout<< "\n\tAtaque: " << d->ataque;
        cout<< "\n\tVida: " << d->aguante;
        cout<< "\n\tDefensa: "<< d->defensa;
        cout<< "\n\tCamuflaje: "<< d->camuflaje;
        cout<< "\n\tAgilidad: " << d->agilidad;
        cout<< ""<<endl;
        d = d->sig;
        cont++;
    }
}

/// Habitats ///

void Escribir_Habitat( habitat_archivo muestraH , int conth)
{   cout<<"\t[Habitat #"<< conth+1 <<"] "<<endl;
    cout<<"\tNombre: "<< muestraH.nombre <<endl;
    cout<<"\tNumero de Dinosaurios: "<< muestraH.NumDinos <<endl;
}

/// Dinos ///
 void Escribir_Dinosaurio( dinosaurio_archivo muestraD , int contd )
 {  cout<<"\n\t[Dino #"<< contd+1 <<"] "<<endl;
    cout<<"\tNombre: "<< muestraD.nombre <<endl;
    cout<<"\tAtaque:"<< muestraD.ataque <<endl;
    cout<<"\tVida: "<< muestraD.aguante <<endl;
    cout<<"\tDefenza: "<< muestraD.defensa <<endl;
    cout<<"\tNivel Camuflaje: "<< muestraD.camuflaje <<endl;
    cout<<"\tAgilidad :"<< muestraD.agilidad <<endl;
    cout<<"\n"<<endl;
 }

 /// Muetra el habitat pedido ///
void Usuario::Mostrar_x_habitat( char *nombreX )
{   int cont = 1 , visto=0 ;
    habitat *q;
    q = p;

    if( p == NULL)
    {
        cout<<"\tLa lista esta vacia\n"<<endl;
    }
    else
    {
        while(q)
        {   if ( !strcmp( q->nombre , nombreX ))
            {   cout<<"\n\t[Habitat #"<< cont <<"]"<<endl;
                cout<<"\tNombre: "<< q->nombre <<endl;
                cout<<"\tCantidad de Dinos: "<< q->NumDinos<<endl;
                MostrarD ( q->a );
                visto = 1;
            }
            q = q->sig;
            cont++;
        }
    }
if ( visto == 0)    { cout<<"\n\tNo hay un habitat con ese nombre."<<endl; }
}

/// Muestra el dino con mas ataque de un X habitat ///
void Usuario::Mostrar_dino_ataque( char *nombreX )
{   int cont = 1 ;
    habitat *q;
    q = p;

    if( p == NULL)
    {
        cout<<"\tLa lista esta vacia\n"<<endl;
    }
    else
    {
        while(q)
        {   if ( !strcmp( q->nombre , nombreX ))
            {   if ( cont == 1 )
                {   cout<<"\n\tEl/los dinos con mas ataque de este habitat es/son:"<<endl;
                    cout<<"\n\t[Habitat #"<< cont <<"]"<<endl;
                    cout<<"\tNombre: "<< q->nombre <<endl;
                    cout<<"\tCantidad de Dinos: "<< q->NumDinos<<endl;
                }
                MostrarD_ataque ( q->a );
            }
            q = q->sig;
            cont++;
        }
    }
if ( cont == 1 && p )    { cout<<"\n\tNo hay un habitat con ese nombre."<<endl; }
}

/// Muestra al Dino con el mayor Ataque ///
void Usuario::MostrarD_ataque( dinosaurio *d )
{   int cont = 1 , max_ataque=0 ;
    dinosaurio *z;

    z = d;

    while(z)
    {   if ( z->ataque > max_ataque )
        max_ataque = z->ataque;
        z = z->sig;
    }

    while(d)
    {   if ( d->ataque == max_ataque)
        {   cout<< "\n\t[Dinosairio #"<< cont <<"]";
            cout<< "\n\tNombre: " << d->nombre;
            cout<< "\n\tAtaque: " << d->ataque;
            cout<< "\n\tVida: " << d->aguante;
            cout<< "\n\tDefensa: "<< d->defensa;
            cout<< "\n\tCamuflaje: "<< d->camuflaje;
            cout<< "\n\tAgilidad: " << d->agilidad;
            cout<< ""<<endl;
        }
        d = d->sig;
        cont++;
    }
}

/// Es la funcion "base" de las 3 funciones que permiten mostrar el dino con mas agilidad ///----------------------------///
void Usuario::Mostrar_dino_agilidad()
{   int cont = 1 , visto=0 ,  max_agilidad=0 ;
    habitat *q;
    q = p;

    if( p == NULL)
    {
        cout<<"\tLa lista esta vacia\n"<<endl;
    }
    else
    {
        cout<<"\tEl/los dinos con mas agilidad son:"<<endl;
        max_agilidad = Sacar_agi (  q->a , max_agilidad );

        while(q)
        {   MostrarD_agilidad ( q->a , max_agilidad );
            q = q->sig;
            cont++;
        }
    }
if ( cont == 1)    { cout<<"\n\tNo hay un habitat con ese nombre."<<endl; }
}

/// Saca el valor de la maxima agilidad existente ///
int Usuario::Sacar_agi( dinosaurio *d , int max_agilidad )
{   while(d)
    {   if ( d->agilidad > max_agilidad )
        {   max_agilidad = d->agilidad;
        }
        d = d->sig;
    }
    return max_agilidad;
}

/// Muestra el dino con mas agilidad ///
void Usuario::MostrarD_agilidad( dinosaurio *d , int max_agilidad )
{   int cont = 1 ;

    while(d)
    {   if ( d->agilidad == max_agilidad )
        {   cout<< "\n\t[Dinosairio #"<< cont <<"]";
            cout<< "\n\tNombre: " << d->nombre;
            cout<< "\n\tAtaque: " << d->ataque;
            cout<< "\n\tVida: " << d->aguante;
            cout<< "\n\tDefensa: "<< d->defensa;
            cout<< "\n\tCamuflaje: "<< d->camuflaje;
            cout<< "\n\tAgilidad: " << d->agilidad;
            cout<< ""<<endl;
        }
        d = d->sig;
        cont++;
    }
}


