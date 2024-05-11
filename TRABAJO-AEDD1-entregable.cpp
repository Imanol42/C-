#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define cls system("CLS");
using namespace std;
//funciones de presentación
void menuprincipal();
void cuadrado_asteriscos();
void menu_numericos();
void gotox();
void tiempo(int);
void fechaactual();
void tiempodedetalles();
//Funciones de algoritmos Numericos
void raizDiezrecursivo();
void raizDieziterativo();
void conversori();
void conversorR();
void sumatriangularrecursivo();
void sumatriangulariterativo();
//cabeceras de funciones de algoritmos numericos 
double raizDiezi(int);
double raizDiezr(int,double);
unsigned long long conversorr(unsigned long long, int&, int&);
unsigned long long sumaTriangularr(int,unsigned long long,unsigned long long,unsigned long long);
unsigned long long sumaTriangulari(int);

void gotoxy( int column, int line ){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
struct pos{
	bool arriba;
	bool abajo;
	bool izquierda;
	bool derecha;
	int x;
	int y;
} 
posicion;
int main (int argc, char * argv[]){	
	system("color 6f");//Cambiamos color de fondo y de texto de la consola 
	system("mode con: cols=116 lines=31");//Definimos tamaños de filas y columnas de la consola
	SetConsoleTitle("AEDD O.G.U");
	time_t t1 = time(0);//Primer tiempo al ejecutar programa
	gotoxy(posicion.y= 50, posicion.x=13);
	cout<<"CARGANDO "<<endl;
	gotoxy(posicion.y= 49, posicion.x=14);
	for(int a=0; a<3; a++){		
		for(int cargando=3; cargando >0; cargando--){
			gotoxy(posicion.y= 49, posicion.x=14);
			for (posicion.x=15; posicion.x <= 24; ++posicion.x){
				cout<<" ";
				Sleep(50);
			}
		}
	}cls
	posicion.arriba     = true;
	posicion.izquierda  = true;
	posicion.derecha    = false;
	posicion.abajo      = false;
	posicion.x          = 0;
	posicion.y          = 0;
	for(int a=0;a<2;a++){//for de asteriscos de la introduccion
		if((posicion.arriba == true && posicion.izquierda == true)){
			for(; posicion.x != 115; ++posicion.x){
				gotoxy(posicion.x,posicion.y);
				cout<<"*";
				Sleep(10);
			}
			posicion.izquierda  = false;
			posicion.derecha    = true;
			for (; posicion.y != 30; ++posicion.y){
				gotoxy(posicion.x,posicion.y);
				cout<<"*";
				Sleep(10);
			}
			posicion.arriba     = false;
			posicion.abajo      = true;
		}
		else if((posicion.abajo == true) && (posicion.derecha == true))
		{
			for(; posicion.x != 0; --posicion.x){
				gotoxy(posicion.x,posicion.y);
				cout<<"*";
				Sleep(10);
			}
			posicion.izquierda  = true;
			posicion.derecha    = false;
			for (; posicion.y != 0; --posicion.y){
				gotoxy(posicion.x,posicion.y);
				cout<<"*";
				Sleep(10);
			}
			posicion.arriba     = true;
			posicion.abajo      = false;
		}
	}
	gotoxy(posicion.x=19,posicion.y=2);
	cout << R"(
		    _   U  _____ u____    ____          U  ___ u              ____                _   _     
		U  /"\  u\| ___"||  _"\  |  _"\          \/"_ \/           U /"___|u           U |"|u| |    
		 \/ _ \/  |  _|"/| | | |/| | | |         | | | |           \| |  _ /            \| |\| |    
		 / ___ \  | |___U| |_| |U| |_| |\    .-,_| |_| |            | |_| |              | |_| |    
		/_/   \_\_|_____||____/ _|____/ u     \_)-\___/      _       \____|      _      <<\___/     
		 \\    >("<<   >("|||_ (")|||_             \\       (")      _)(|_      (")    (__) )(      
		(__)  (__(__) (__(__)_) "(__)_)           (__)       "      (__)__)      "         (__)     		
																				)" << '\n';
	int a=1, b=105, c=1, d=105, f=1, h=105;
	gotoxy(posicion.x=2,posicion.y=29);
	cout<<"UTN FRSF";
	gotoxy(posicion.x=55,posicion.y=29);
	cout<<"2021";	 
	gotoxy(posicion.x=104,posicion.y=29);
	cout<<"Versión 1.0";
	gotoxy(posicion.x=50,posicion.y=22);
	cout<<"DESARROLLADORES:";
	gotoxy(posicion.x=50,posicion.y=23);
	cout<<"----------------";
	for(int i=0;i<=46;i++){//nombres de presentacion
		if(posicion.x!=40){
			Sleep(15);
			++a;
			gotoxy(posicion.x=a,posicion.y=24);
			cout<<" Valentin";
			++c;
			gotoxy(posicion.x=a,posicion.y=25);
			cout<<"   Imanol";
			++f;
			gotoxy(posicion.x=a,posicion.y=26);
			cout<<"  Manuela";
		}
		if(posicion.x != 50){
			Sleep(15);
			b--;
			gotoxy(posicion.x=b,posicion.y=24);
			cout<<"Ulman ";
			d--;
			gotoxy(posicion.x=b,posicion.y=25);
			cout<<"Gonzalez ";
			h--;
			gotoxy(posicion.x=b,posicion.y=26);
			cout<<"Ollocco ";
		}
	}
	Sleep(5000);
	menuprincipal();
	time_t t2 = time(0);//Segundo tiempo al finalizar programa
	tiempo(difftime(t2,t1));
	return 0;
}
void menuprincipal(){	
	cuadrado_asteriscos();
	int a;
	char c=' ';
	gotoxy(posicion.x=50,posicion.y=2);
	cout<<"MENU PRINCIPAL";
	gotoxy(posicion.x=45,posicion.y=4);
	cout<<"1. Algoritmos Numericos";
	gotoxy(posicion.x=45,posicion.y=5);
	cout<<"2. Juegos (En Construcción)";
	gotoxy(posicion.x=45,posicion.y=6);
	cout<<"9. Cerrar Aplicación";
	gotoxy(posicion.x=45,posicion.y=9);
	cout<<"Ingrese una Opción: ";
	cin>>a;
	switch (a){
	case 1:
		gotoxy(posicion.x=40,posicion.y=15);	
		menu_numericos();
		break;
	case 2:
		cuadrado_asteriscos();
		gotoxy(posicion.x=40,posicion.y=15);
		cout<<"Proximamente version 1.1..."<<endl;
		break;
	case 9:
		gotoxy(posicion.x=40,posicion.y=15);	
		cout<<"SALIR: 'S' PARA SI 'N' PARA NO: ";cin>>c;
		c=tolower(c);
		if(c=='s'){
			return;
		}
		else if(c=='n'){
			c=' ';
			return menuprincipal();
		}
		break;
	default:
		cuadrado_asteriscos();
		gotoxy(posicion.x=45,posicion.y=15);
		cout<<"Caracter ingresado no valido";
		Sleep(2000);
		return menuprincipal();
	}	
}
		void menu_numericos(){
			cuadrado_asteriscos();
			int a,b;
			gotoxy(posicion.x=45,posicion.y=2);
			cout<<"ALGORITMOS NUMERICOS";
			gotoxy(posicion.x=35,posicion.y=4);
			cout<<"1. Conversion Binario a Decimal(Solución iterativa)";
			gotoxy(posicion.x=35,posicion.y=6);
			cout<<"2. Conversion Binario a Decimal(Solución recursiva)";
			gotoxy(posicion.x=35,posicion.y=8);
			cout<<"3. Raiz Cuadrada de 10(Solución iterativa)";
			gotoxy(posicion.x=35,posicion.y=10);
			cout<<"4. Raiz Cuadrada de 10(Solución recursiva)";
			gotoxy(posicion.x=35,posicion.y=12);
			cout<<"5. Funcion de Suma Triangular(Solución iterariva)";
			gotoxy(posicion.x=35,posicion.y=14);
			cout<<"6. Funcion de Suma Triangular(Solución recursiva)";
			gotoxy(posicion.x=35,posicion.y=17);
			cout<<"9. Volver al Menu Principal";
			gotoxy(posicion.x=45,posicion.y=19);
			cout<<"Ingrese una Opción: ";cin>>a;
			switch (a){
				case 1:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Conversion Binario a Decimal(Solución iterativa)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"El sistema binario, es un sistema de numeración en el que los números son representados utilizando";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"únicamente dos cifras: cero (0) y uno (1). Es uno de los sistemas que se utilizan en las computadoras.";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"Lo que nuestro algoritmo hará será la conversión de binario a decimal mas facil en este caso de forma"; 
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"iterativa";
						gotoxy(posicion.x=25,posicion.y=9);	
						cout<<"Acontinuacion ingresar valor binario a convertir a sistema decimal";
						tiempodedetalles();
						conversori();
					}
					if(b==2){
						conversori();
					}
					if(b==9){
						return menu_numericos();
					}
					break;
				case 2:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Conversion Binario a Decimal(Solución recursiva)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"El sistema binario, es un sistema de numeración en el que los números son representados utilizando";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"únicamente dos cifras: cero (0) y uno (1). Es uno de los sistemas que se utilizan en las computadoras.";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"Lo que nuestro algoritmo hará será la conversión de binario a decimal mas facil en este caso de forma";
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"recursiva";
						gotoxy(posicion.x=25,posicion.y=9);	
						cout<<"A continuacion ingresar valor binario a convertir a sistema decimal";
						tiempodedetalles();
						conversorR();
					}
					if(b==2){
						conversorR();
					}
					if(b==9){
						return menu_numericos();
					}
					break;	
				case 3:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Raiz Cuadrada de 10(Solución iterativa)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"La raiz cuadrada aritmetica de 10 es un numero irracional es decir tiene infinitas cifras y carece de";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"periodo. En este algoritmo lo que haremos es aproximarnos a su valor real, tal aproximacion sera dada";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"por el numero que de la precision que el usuario desee, siendo este un valor entero positivo.";
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"su numero real aproximado es de: 3,16228... pero no es este su verdadero valor.  ";
						gotoxy(posicion.x=25,posicion.y=9);	
						cout<<"A continuacion ingresar valor de aproximacion deseado.";
						tiempodedetalles();
						raizDieziterativo();
					}
					if(b==2){
						raizDieziterativo();
					}
					if(b==9){
						return menu_numericos();
					}
					break;	
				case 4:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Raiz Cuadrada de 10(Solución recursiva)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"La raiz cuadrada aritmetica de 10 es un numero irracional es decir tiene infinitas cifras y carece de";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"periodo. En este algoritmo lo que haremos es aproximarnos a su valor real, tal aproximacion sera dada";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"por el numero que de la precision que el usuario desee, siendo este un valor entero positivo.";
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"su numero real aproximado es de: 3,16228... pero no es este su verdadero valor.  ";
						gotoxy(posicion.x=25,posicion.y=9);	
						cout<<"A continuacion ingresar valor de aproximacion deseado.";
						tiempodedetalles();
						raizDiezrecursivo();
					}
					if(b==2){
						raizDiezrecursivo();
					}
					if(b==9){
						return menu_numericos();
					}
					
					break;
				case 5:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Suma Triangular (Solución iterativa)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"Un número triangular cuenta objetos dispuestos en un triángulo equilátero. El n-ésimo número";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"triangular es el número de puntos en la disposición triangular con n puntos en un lado, y es ";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"igual a la suma de los n números naturales de 1 a n, siendo por convención, el 1 el primer ";
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"número triangular.  ";
						gotoxy(posicion.x=10,posicion.y=7);
						cout<<"Nuestro algoritmo facilita la denominada 'Suma triangular' ingresando un valor en el rango ";
						gotoxy(posicion.x=10,posicion.y=8);
						cout<<"[1;7] y entregando en su salida el resultado de la suma.";
						gotoxy(posicion.x=25,posicion.y=12);	
						cout<<"A continuacion ingresar valor deseado.";
						tiempodedetalles();
						sumatriangulariterativo();
					}
					if(b==2){
						sumatriangulariterativo();
					}
					if(b==9){
						return menu_numericos();
					}
					break;
				case 6:
					cuadrado_asteriscos();
					gotoxy(posicion.x=25,posicion.y=3);
					cout<<"Acaba de seleccionar: Suma Triangular (Solución recursiva)";
					gotox();
					gotoxy(posicion.x=65,posicion.y=15);	
					cin>>b;
					if(b==1){
						cuadrado_asteriscos();
						gotoxy(posicion.x=10,posicion.y=3);
						cout<<"Un número triangular cuenta objetos dispuestos en un triángulo equilátero. El n-ésimo número";
						gotoxy(posicion.x=10,posicion.y=4);
						cout<<"triangular es el número de puntos en la disposición triangular con n puntos en un lado, y es ";
						gotoxy(posicion.x=10,posicion.y=5);
						cout<<"igual a la suma de los n números naturales de 1 a n, siendo por convención, el 1 el primer ";
						gotoxy(posicion.x=10,posicion.y=6);
						cout<<"número triangular.  ";
						gotoxy(posicion.x=10,posicion.y=7);
						cout<<"Nuestro algoritmo facilita la denominada 'Suma triangular' ingresando un valor en el rango ";
						gotoxy(posicion.x=10,posicion.y=8);
						cout<<"[1;7] y entregando en su salida el resultado de la suma.";
						gotoxy(posicion.x=25,posicion.y=12);	
						cout<<"A continuacion ingresar valor deseado.";
						tiempodedetalles();
						sumatriangularrecursivo();
					}
					if(b==2){
						sumatriangularrecursivo();
					}
					if(b==9){
						return menu_numericos();
					}
					break;
				case 9:
					return menuprincipal();
					break;
				default:
					cuadrado_asteriscos();
					gotoxy(posicion.x=45,posicion.y=15);
					cout<<"Caracter ingresado no valido";
					Sleep(2000);
					return menuprincipal();	
			}
		}
		unsigned long long conversorr(unsigned long long a, int& b, int& c){
				if(a==0){
					return c;
				}
				if(a%10==1){
					c=c+pow(2,b);
					b++;
					return conversorr((a/=10),b,c);
				}
				else{
					b++;
					return conversorr((a/=10),b,c);
				}
		}
		void conversorR(){
			cuadrado_asteriscos();
			unsigned long long c=0;
			int v=0,d=0;
			char q;
			gotoxy(posicion.x=15,posicion.y=3);
			cout<<"Ingrese valor binario a convertir (Todo valor distinto de 1 o 0 será tomado como '0'): "<<endl;
			gotoxy(posicion.x=45,posicion.y=4);
			cin>>c;
			gotoxy(posicion.x=45,posicion.y=6);
			cout<<"Decimal: "<<c<<"="<<conversorr(c,v,d)<<endl;
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return conversorR();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
		void conversori(){//iterativo
			cuadrado_asteriscos();
			int b=1,e=0;
			unsigned long long m=0,a=0,c=0;
			char q;
			gotoxy(posicion.x=15,posicion.y=3);
			cout<<"Ingrese valor binario a convertir (Todo valor distinto de 1 o 0 será tomado como '0'): "<<endl;
			gotoxy(posicion.x=45,posicion.y=4);
			cin>>c;
			a=c;
			m=a;
			while(a!=0){
				a/=10;
				e++;
			}
			for(int i=0;i<e;i++){
				if(c%10==1){
				c /=10;
				b=b+pow(2,i);
				}
				else{
					c/=10;
				}
			}
			gotoxy(posicion.x=45,posicion.y=6);
			cout<<"Decimal: "<<m<<"="<<b-1<<endl;
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return conversori();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
		void raizDieziterativo(){
			cuadrado_asteriscos();
			char q;
			int a;
			gotoxy(posicion.x=40,posicion.y=3);
			cout<<"INGRESE VALOR DE PRECISION: ";
			gotoxy(posicion.x=68,posicion.y=3);
			cin>> a;
			gotoxy(posicion.x=23,posicion.y=10);
			cout<<"EL VALOR DE LA RAIZ CUADRADA DE 10 CON APROXIMACION '"<<a<<"' ES: "<<fixed<<setprecision(10)<<raizDiezi(a)<<endl;
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return raizDieziterativo();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
		double raizDiezi(int x){
			double u=0.0,v=3.0;
			for(int i=0;i<x;i++){
				u+=6.0;
				u=1.0/u;
			}
			v+=u;
			return v;
		}
		void raizDiezrecursivo(){
			cuadrado_asteriscos();
			int a;
			char q;
			double i=0.0;
			gotoxy(posicion.x=40,posicion.y=3);
			cout<<"INGRESE VALOR DE PRECISION: ";
			gotoxy(posicion.x=68,posicion.y=3);
			cin>> a;
			gotoxy(posicion.x=23,posicion.y=10);
			cout<<"EL VALOR DE LA RAIZ CUADRADA DE 10 CON APROXIMACION '"<<a<<"' ES: "<<fixed<<setprecision(10)<<raizDiezr(a,i)<<endl;
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return raizDiezrecursivo();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
		double raizDiezr(int x,double u){
			double v=3.0;
			if(x==0){
				v+=u;
				return v;
			}
			else{
				u+=6.0;
				u=1.0/u;
				x--;
				return raizDiezr(x,u);
			}
		}	
		void sumatriangularrecursivo(){
			cuadrado_asteriscos();
			int a ,b=3;
			char q;
			unsigned long long f=0,g=0;
			gotoxy(posicion.x=35,posicion.y=3);
			cout<<"Ingrese valor dentro del intervalo [1;7]: ";
			gotoxy(posicion.x=77,posicion.y=3);
			cin>>a;
			if(1<=a&&a<=7){
				gotoxy(posicion.x=50,posicion.y=10);
				cout<<sumaTriangularr(b,a,f,g)<<endl;
			}else{
				return sumatriangularrecursivo();
			}
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return sumatriangularrecursivo();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
				
	unsigned long long sumaTriangularr(int b,unsigned long long d,unsigned long long c,unsigned long long g){
		if(b==0){
			return d;
		}
		for(unsigned long long i=d; i>0; i--){
			for(c=i; c>0; c--){
				g+=c;
			}
		}
		c=g;
		g=0;
		b--;
		return sumaTriangularr(b,c,d,g);
		}
		
		void sumatriangulariterativo(){
			cuadrado_asteriscos();
			int a ;
			char q;
			gotoxy(posicion.x=35,posicion.y=3);
			cout<<"Ingrese valor dentro del intervalo [1;7]: ";
			gotoxy(posicion.x=77,posicion.y=3);
			cin>>a;
			if(1<=a&&a<=7){
				gotoxy(posicion.x=50,posicion.y=10);
				cout<<sumaTriangulari(a)<<endl;
			}else{
				return sumatriangulariterativo();
			}
			gotoxy(posicion.x=35,posicion.y=18);	
			cout<<"Quieres repetir?: 'S' PARA SI 'N' PARA NO: ";cin>>q;
			q=tolower(q);
			if(q=='s'){
				return sumatriangulariterativo();
			}
			if(q=='n'){
				return menu_numericos();
			}
		}
		unsigned long long sumaTriangulari(int b){
			unsigned long long d=0,c=0,a=0,f=0;
			for(unsigned long long i=b; i>0; i--){
				for(c=i; c>0; c--){
					d+=c;
				}
			}
			c=d;
			for(unsigned long long i=c; i>0; i--){
				for(d=i; d>0; d--){
					a+=d;
				}
			}
			c=a;
			for(unsigned long long i=c; i>0; i--){
				for(a=i; a>0; a--){
					f+=a;
				}
			}
			return f;
		}
		void tiempodedetalles(){
			for(int p=25; p>0;p--){
				gotoxy(posicion.x=52,posicion.y=25);
				cout.fill  ('0');    cout.width ( 2 );
				cout<<p<<" SEGUNDOS";
				Sleep(1000);
			}
		}
		void gotox(){
			gotoxy(posicion.x=45,posicion.y=4);
			cout<<"1.-Ver definición";
			gotoxy(posicion.x=45,posicion.y=5);
			cout<<"2.-Ejecutar";
			gotoxy(posicion.x=45,posicion.y=9);
			cout<<"9.-Volver al menú anterior";
			gotoxy(posicion.x=45,posicion.y=15);
			cout<<"Ingrese una opcion: ";
			gotoxy(posicion.x=65,posicion.y=15);
		}
		void fechaactual(){
			time_t rawtime;
			struct tm * timeinfo;
			time (&rawtime);
			timeinfo = localtime (&rawtime);
			printf ("Fecha actual: %s", asctime(timeinfo));
			return;
		}
		void cuadrado_asteriscos(){
			cls
			posicion.arriba     = true;
			posicion.izquierda  = true;
			posicion.derecha    = false;
			posicion.abajo      = false;
			posicion.x          = 0;
			posicion.y          = 0;
			for(int a=0;a<2;a++){//for de asteriscos de la introduccion
				if((posicion.arriba == true && posicion.izquierda == true)){
					for(; posicion.x != 115; ++posicion.x){
						gotoxy(posicion.x,posicion.y);
						printf("*");
					}
					posicion.izquierda  = false;
					posicion.derecha    = true;
					for (; posicion.y != 30; ++posicion.y){
						gotoxy(posicion.x,posicion.y);
						printf("*");
					}
					posicion.arriba     = false;
					posicion.abajo      = true;
				}
				else if((posicion.abajo == true) && (posicion.derecha == true)){
					for(; posicion.x != 0; --posicion.x){
						gotoxy(posicion.x,posicion.y);
						printf("*");
					}
					posicion.izquierda  = true;
					posicion.derecha    = false;
					for (; posicion.y != 0; --posicion.y){
						gotoxy(posicion.x,posicion.y);
						printf("*");
					}
					posicion.arriba     = true;
					posicion.abajo      = false;
				}
			}
			gotoxy(posicion.x=2,posicion.y=29);
			cout<<"UTN FRSF";
			gotoxy(posicion.x=55,posicion.y=29);
			cout<<"2021";	 
			gotoxy(posicion.x=104,posicion.y=29);
			cout<<"Versión 1.0";
			gotoxy(posicion.x=2,posicion.y=1);
			fechaactual();
			return;
		}
		void tiempo(int totalSeg){
			int horas=0, min=0, seg=0;
			horas = totalSeg/3600;
			min=totalSeg/60;
			seg=totalSeg%60;
			gotoxy(posicion.x=40,posicion.y=23);
			cout<<"TIEMPO DE EJECUCION DE PROGRAMA";
			gotoxy(posicion.x=50,posicion.y=24);
			cout.fill  ('0');    cout.width ( 2 );
			cout<<horas<<":";
			cout.fill  ('0');    cout.width ( 2 );
			cout<<min<<":";
			cout.fill  ('0');    cout.width ( 2 );
			cout<<seg<<endl;
			return;
		}
