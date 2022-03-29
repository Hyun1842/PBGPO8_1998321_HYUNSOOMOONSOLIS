
#include <iostream>
#include <locale.h>

using namespace std;

struct pacientes{
    int id;
    char nombrepaciente[50];
    int edad;
};

struct citas{
    char especialista[50];
    char hora[50];
    char tratamien[50];
    
};

int main()
{
    int opcion, op2, op3; 
    int i;
    int j=1;
    struct pacientes paciente[i];
    struct citas cita [i];
   


do{    
cout<<"Bienvenido, ¿qué desea hacer? \n";
 cout << "1.-Agendar cita \n"; 
            cout << "2.-Modificar cita \n";
            cout << "3.-Eliminar cita \n";
            cout << "4.-Lista de citas vigentes \n";
            cout << "5.-Limpiar pantalla \n";
            cout << "6.-Salir \n";
            cin >> opcion;
switch(opcion){
    
    case 1:
    
      
  for(i=0; i<j; i++){
      
    
      cout<<"El número de cita es: "<<i+1<<"\n";
      cout<<"Ingrese el nombre del paciente \n";
      cin>>paciente[i].nombrepaciente;
      cout<<"Ingrese la hora del tratamiento \n";
     cin>>cita[i].tratamien;
      cout<<"Ingrese la edad del paciente \n";
      cin>>paciente[i].edad;
         
      cout<<"¿Desea ingresar otra cita?, si es asi ingrese 1 \n";
      cin>>op3;
      
      if(op3==1){
          j=j+1;
      }
  }
  
  break;
  
      case 2:
      
      cout<<"Modificar cita \n";
      
      break;
      
      case 3:
      
      cout<<"Eliminar cita \n";
      
      break;
      
      case 4:
       cout<<"Las citas vigentes son: \n";
      for(i=0; i<3; i++){
      cout<<"El número de cita disponible es: "<<i+1<<"\n";
      }
      break;
      
      case 5:
      cout<<"Limpiar pantalla \n";
  
      break;
      
      case 6:
      
      cout<<"Salir \n";
      system("cls");
      op2=2;
      break;
      
      default:
      cout<<"Opción invalida \n";
      break;

      
      

}
cout<<"¿Desea volver al menu?, si es asi ingrese 1 \n";
cin>>op2;
}while (op2==1);



}