#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo *sig;
	Nodo *ant;

};

void recorreDesdeInicio(Nodo *p){
	Nodo *q=p;
	cout<<"\nRECORRIDO DE INICIO A FIN: \n";
	while(q!=NULL){
		cout<<q->info<< " ";
		q=q->sig;
	}

	cout<<endl;
}

void recorreDesdeFinal(Nodo *f){
		Nodo *q=f;
	cout<<"\nRECORRIDO DE FIN A INICIO: \n";
	while(q!=NULL){
		cout<<q->info<< " ";
		q=q->ant;
	}

	cout<<endl;
}

void inserta_principio(Nodo *&p, Nodo *&f){
    system("cls");
    cout<<"\n\tINSERTAR AL PRINCIPIO\n";
    int dato;
	cout<<"Dato a insertar al inicio: ";
    cin>>dato;
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

void inserta_antes_x(Nodo *&p, int dato, int x){
	Nodo *q,*r,*t;
	q=p;
	while((q->sig != NULL) && (q->info !=x)){
		q=q->sig;
	}

	if (q->info == x){
        t=new Nodo();
		t->info = dato;
		t->sig=q;

		r =q->ant;
		q->ant=t;

		if(p==q){
			p=t;
			t->ant = NULL;

		}else{

			r->sig= t;
			t->ant = r;
		}
	}else{
		cout<<"No se encontro el dato "<<x<<" en la lista. "<<endl;
		return;
	}
}


void inserta_despues_x(Nodo *&p, Nodo *&f, int dato, int x){
        cout<<"\n\tINSERTAR DESPUES DE UN DATO X\n";
	Nodo *q=p;
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}

	if (q->info == x){
		Nodo *t= new Nodo();
		t->info = dato;
		t->ant=q;

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
		cout<<"No se encontro el dato "<<x<<" en la lista. "<<endl;
		return;
	}
}

int contar_concurrencias(Nodo*p, int dato){
        cout<<"\n\tCONTAR CONCURRENCIAS\n";
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
cout<<"\n\tINVERTIR LISTA\n";
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
cout<<"LISTA INVERTIDA:\n\n";
recorreDesdeInicio(p);
}

// Elimina el primer nodo de una lista doblemente enlazada
void elimina_inicio(Nodo *&p, Nodo *&f){
	Nodo *q=p;
	
	if(q->sig!=NULL){
		p=q->sig;
		p->ant=NULL;
	}else{
		p=NULL;
		f=NULL;
	}
	delete(q);
}

//Elimina el ultimo nodo de una lista doblemente enlazada
void elimina_ultimo(Nodo *&p, Nodo *&f){
	Nodo *q=f;
	
	if(q->ant!=NULL){
		f=q->ant;
		f->sig=NULL;
	}else{
		p=NULL;
		f=NULL;
	}
	delete(q);
}

//Elimina un nodo con informacion x
void elimina_x(Nodo *&p, Nodo *&f, int x){
	Nodo *q=p;
	
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}
	
	if(q->info==x){
		
		if(q==p && q==f){ //la lsiata tiene un solo nodo
		p=NULL;
		f=NULL;
			}else{
				if(q==p){ //El nodo con informacion x es el primero de la lista
					p=q->sig;
					p->ant=NULL;
				}else{
					if(q==f){ //El nodo con informacion x el el ultimo de la lista
						f=q->ant;
						f->sig=NULL;
					}else{  //Es nodo con informacion x es un nodo intermedio
						Nodo *t=NULL;
						Nodo *r=NULL;
						t=q->ant;
						r=q->sig;
						t->sig=r;
						r->ant=t;
					}
					
				}
			}
			delete(q);
	}else{
		cout<<" El elemento con informacion "<< x << " no se encuentra en  la lista\n";
		return;
	}		
}

//Elimina el nodo anterior al nodo con informacion x
void elimina_antes_x(Nodo *&p, Nodo *&f, int x){
	if (p==NULL) {
    cout << "La lista ya está vacía.\n";
    return;
	}
	Nodo *q=p;
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}
	
	if(q->info == x){
		if(q==p){ //El nodo con informacion x es el primero de la lista
			cout<<"No existe nodo anterior al primero.\n";
			return;
		}else{
				Nodo *t=NULL;
				t=q->ant;
				if(p==t){ //El nodo a eliminar es el primer nodo de la lista
					p=q;
					p->ant=NULL;
				}else{
					Nodo *r=NULL;
					r=t->ant;
					q->ant=r;
					r->sig=q;
				}
				delete(t);
			}
	}else{
		cout<<"El elemento con informacion "<<x<<" no se encuentra en la lista.\n";
	}	
}

//Elimina el nodo posterior al nodo con informacion x
void elimina_despues_x(Nodo *&p, Nodo *&f, int x){
	if (p==NULL) {
    cout << "La lista ya está vacía.\n";
    return;
	}
	Nodo *q=p;
	while(q->sig != NULL && q->info !=x){
		q=q->sig;
	}
	
	if(q->info == x){
		if(q==f){ //El nodo con informacion x es la ultima posicion de la lista
			cout<<"No existe nodo posterior al ultimo.\n";
			return;
		}else{
				Nodo *t=NULL;
				t=q->sig;
				if(f==t){ //El nodo a eliminar es el ultimo nodo de la lista
					f=q;
					f->sig=NULL;
				}else{
					Nodo *r=NULL;
					r=t->sig;
					q->sig=r;
					r->ant=q;
				}
				delete(t);
			}
	}else{
		cout<<"El elemento con informacion "<<x<<" no se encuentra en la lista.\n";
	}	
	
}
// Mover el menor elemento a la primera posicion de la lista
void MoverMenor(Nodo *&p, Nodo *&f){
	
	cout<<"MOVER ELEMENTO MENOR AL INICIO DE LA LISTA\n";
Nodo *q=p;
Nodo *M;
    if(p->sig==NULL){
        cout<<"La lista tiene un solo elemento\n";
        return;
    }
    else{
        q=p;
        M=p;
            while(q!=NULL){
               if(q->info<M->info){
                M=q;
               }
               q=q->sig;
            }

            if(M==p){
            cout<<"El elemento menor ya esta en la posicion inicial";
            return;
        }else{
            if(M==f){
                f=M->ant;
                f->sig=NULL;
            }else{
                Nodo *r,*t;
                r=M->ant;
                t=M->sig;
                r->sig=t;
                t->ant=r;
            }
        }
        //insertar al inicio
        M->sig=p;
        M->ant=NULL;
        p->ant=M;
        p=M;
    }

}

//Mover el mayor elemento a la iltima posicion de la lista
void MoverMayor(Nodo *&p,Nodo *&f){

Nodo *q=p;
Nodo *M;
    if(p->sig==NULL){
        cout<<"La lista tiene un solo elemento\n";
    }else{
        q=p;
        M=p;
            while(q!=NULL){
               if(q->info>M->info){
                M=q;
               }
               q=q->sig;
            }

            if(M==f){
            cout<<"El elemento mayor ya esta en la posision final";
            return ;
        }else{
            if(M==p){
                p=M->sig;
                p->ant=NULL;
            }else{
                Nodo *r,*t;
                r=M->sig;
                t=M->ant;
                r->ant=t;
                t->sig=r;
            }
        }
        //insertar al final
        M->sig=NULL;
        M->ant=f;
        f->sig=M;
        f=M;
    }


}

void eliminarRepetidos(Nodo *&p, Nodo *&f) {
    cout << "\n\tELIMINAR ELEMENTOS DUPLICADOS EN LISTA ORDENADA\n";
Nodo *q=p;
 if (p == NULL) {
        cout << "La lista está vacía.\n";
    }
	if(p->sig==NULL){
	        cout<<"La lista tiene un solo elemento\n";
	    }else{
	        while(q->sig!=NULL){
	                Nodo *r=q->sig;
	            if(q->info==r->info){
	                Nodo *s=r;
	                r=r->sig;
	                q->sig=r;
	
	                if(r==NULL){
	                    f=q;
	                }else{
	                    r->ant=q;
	                
	                }
	                delete(s);
	            }else{
	                q=q->sig;
	            }
	
	        }
	        cout << "Duplicados eliminados correctamente.\n";
	
	    }

}

void eliminarCoincidentes(Nodo*& p, Nodo*& f, int x) {
    Nodo* q = p; 
    Nodo* s;      
    Nodo* t;  
	if(p->sig==NULL){
        cout<<"La lista tiene un solo elemento\n";
    }else{
    		while (q != NULL) {
        	if (q->info == x) {
            	t = q;
            
            	if (q == p) {
                p = q->sig;
                if (p != NULL) {
                    p->ant = NULL;
                } else {
                    f = NULL; // Lista queda vacía
                }
            }
            //nodo al final
            else if (q == f) {
                f = q->ant;
                f->sig = NULL;
            }
            //nodo en el medio
            else {
                s = q->ant;
                s->sig = q->sig;
                q->sig->ant = s;
            }

            q = q->sig;
            delete t;
        } else {
            q = q->sig;
        }
   	 	}
	}   
    
}

void menu(){

	Nodo *p=NULL;
	Nodo *f=NULL;
	int op,dato, x, cont;

	do{
        //system("cls");
		cout<<"\n\t-----MENU DE LISTA DOBLEMENT ENLAZADA--------"<<endl;
		cout<<"1.- Insertar al inicio\n";
		cout<<"2.- Insertar al final\n";
		cout<<"3.- Insertar antes de un nodo con dato x\n";
		cout<<"4.- Insertar despues de un nodo con dato x\n";
		cout<<"5.- Mostrar lista de inicio a fin\n";
		cout<<"6.- Mostrar lista de fina a inicio\n";
		cout<<"7.- Contar CONCURRENCIAS\n";
		cout<<"8.- INVERTIR LISTA\n";
		cout<<"9.- Eliminar el PRIMER NODO\n";
		cout<<"10.- Eliminar el ULTIMO NODO\n";
		cout<<"11.- Eliminar el nodo con INFORMACION X\n";
		cout<<"12.- Eliminar el NODO ANTERIOR AL NODO CON INFORMACION X\n";
		cout<<"13.- Eliminar el NODO POSTERIOR AL NODO CON INFORMACION X\n";
		cout<<"14.- MOVER MENOR AL INICIO DE LA LISTA\n";
		cout<<"15.- MOVER MAYOR AL FINAL DE LA LISTA\n";
		cout<<"16.- ELIMINAR DUPLICADOS EN LISTA ORDENADA\n";
		cout<<"17.- ElIMINAR COINCIDENTES\n";
		cout<<"0. salir\n";
		cout<<"OPCION: "; cin>>op;

		switch(op)
		{
			case 1:
				inserta_principio(p,f);
				break;
			case 2:
			    system("cls");
				cout<<"Dato a insertar al final: ";
				cin>>dato;
				inserta_final(p,f,dato);
				system("pause");
				break;
			case 3:
				cout<<"dato a insertar: ";
				cin>>dato;
				cout<<"Antes del nodo con dato: ";
				cin>>x;
				inserta_antes_x(p,dato,x);
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
			    
				recorreDesdeFinal(f);
				
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
            case 9:
				elimina_inicio(p,f);
				break;
			case 10:
				elimina_ultimo(p,f);
				break;
			case 11:
				cout<<"Ingrese el dato a eliminar: ";cin>>dato;
				elimina_x(p,f,dato);	
				break;
			case 12:
				cout<<"Ingrese el dato REFERENCIAL antes de x: ";cin>>dato;
				elimina_antes_x(p,f,dato);
				break;
			case 13:
				cout<<"Ingrese el dato REFERENCIAL despues de x: ";cin>>dato;
				elimina_despues_x(p,f,dato);
				break;
			case 14:
				MoverMenor(p,f);
				break;					    
            case 15:
                MoverMayor(p,f);
                break;   
            case 16:
                
                eliminarRepetidos(p, f);
                
                break;
			case 17:
				cout<<"Ingrese el dato a eliminar: ";cin>>x;
				eliminarCoincidentes(p,f,x);
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

