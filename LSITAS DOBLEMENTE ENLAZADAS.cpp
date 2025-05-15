#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo *sig;
	Nodo *ant;

};

void recorreDesdeInicio(Nodo *p){
	Nodo *q=p;
	cout<<"\nRECORIDO DE INICIO A FIN: \n";
	while(q!=NULL){
		cout<<q->info<< " ";
		q=q->sig;
	}

	cout<<endl;

}

void recorreDesdeFinal(Nodo *f){
		Nodo *q=f;
	cout<<"\nRECORIDO DE FIN A INICIO";
	while(q!=NULL){
		cout<<q->info<< " ";
		q=q->ant;
	}

	cout<<endl;
}

void inserta_principio(Nodo *&p, Nodo *&f,int dato){

	Nodo *q = new Nodo();
	q->info =dato;

	if(p==NULL){
		p=f=q;

	}else{
		q->sig=p;
		p->ant=q;
		q->ant=NULL;
		p=q;
	}
}

void inserta_final(Nodo *&p, Nodo *&f,int dato){

	Nodo *q = new Nodo();
	q->info =dato;

	if(f==NULL){
		p=f=q;

	}else{
		f->sig=q;
		q->ant=f;
		q->sig=NULL;
		f=q;
	}
}

void inserta_antes_x(Nodo *&p,Nodo *&f, int dato, int x){
	Nodo *q=p;
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}

	if (q->info == x){
		Nodo *t= new Nodo();
		t->info = dato;
		t->sig=q;

		Nodo *r =q->ant;
		q->ant=q;

		if(p==q){
			p=t;
			t->ant = NULL;

		}else{

			r->sig= t;
			t->ant = r;
		}
	}else{
		cout<<"No se encontró el dato "<<x<<" en la lista. "<<endl;
		return;
	}
}


void inserta_despues_x(Nodo *&p, Nodo *&f, int dato, int x){
	Nodo *q=p;
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}

	if (q->info == x){
		Nodo *t= new Nodo();
		t->info = dato;
		t->sig=q;

		Nodo *r =q->sig;
		q->sig=t;

		if(f==q){
			t->sig=NULL;
			f=t;

		}else{

			t->sig= r;
			r->ant = t;
		}
	}else{
		cout<<"No se encontró el dato "<<x<<" en la lista. "<<endl;
		return;
	}
}

int contar_concurrencias(Nodo*p, int dato){
	Nodo *q=p;
	int cont=0;
	if(q!=NULL){
		while(q!=NULL){
			if(dato==q->info){
				cont++;
			}
            q=q->sig;
		}
	}
	return cont;

}


void invertir(Nodo *&p,Nodo *&f){
Nodo *q=p;
Nodo *TEMP= new Nodo;
while(q!=NULL){
    TEMP=q->ant;
    q->ant=q->sig;
    q->sig=TEMP;
    q=q->ant;
}
TEMP=p;
p=f;
f=TEMP;
recorreDesdeInicio(p);
}

void menu(){

	Nodo *p=NULL;
	Nodo *f=NULL;
	int op,dato, x, cont;

	do{
		cout<<"\n-----MENU DE LISTAS DOBLEMENTE ENLAZADAS--------"<<endl;
		cout<<"1.- Insertar al inicio\n";
		cout<<"2.- Insertar al final\n";
		cout<<"3.- Insertar antes de un nodo con dato x\n";
		cout<<"4.- Insertar despues de un nodo con dato x\n";
		cout<<"5.- Mostrar lista de inicio a fin\n";
		cout<<"6.- Mostrar lista de fina a inicio\n";
		cout<<"7.- Contar CONCURRENCIAS\n";
		cout<<"8.- INVERTIR LISTA\n";
		cout<<"0. salir\n";
		cout<<"OPCION: "; cin>>op;

		switch(op)
		{
			case 1:
				cout<<"Dato a insertar al inicio: ";
				cin>>dato;
				inserta_principio(p,f,dato);
				break;
			case 2:
				cout<<"Dato a insertar al final: ";
				cin>>dato;
				inserta_principio(p,f,dato);
				break;
			case 3:
				cout<<"dato a insertar: ";
				cin>>dato;
				cout<<"Antes del nodo con dato: ";
				cin>>x;
				inserta_antes_x(p,f,dato,x);
				break;
			case 4:
				cout<<"dato a insertar: ";
				cin>>dato;
				cout<<"Despues del nodo con dato: ";
				cin>>x;
				inserta_despues_x(p,f,dato,x);
				break;
			case 5:
				recorreDesdeInicio(p);
				break;
			case 6:
				recorreDesdeFinal(p);
				break;
			case 7:
				cout<<"Ingrese el dato a buscar: "; cin>>dato;
				 cont=contar_concurrencias(p,dato);
				if(cont==0){
					cout<<"El dato no fue encontrada\n";
				}else{
                cout<<"Nodos repetidos:\n";
				cout<<cont;
				cout<<"\n";
				}

				break;
			case 8:
                invertir(p,f);
                break;
			case 0:
				cout<<"PROGRAMA FINALIZADO\n";
				break;
			default :
			cout<<"OPCION INVALIDA"	;
		}
	}while(op!=0);
}

int main(){

	menu();

	return 0;
}

