#include <stdio.h>
#include <ctype.h>

int confirmacion(){
  char confirmacion;

  do 
  {
    printf("¿Quieres añadir mas empleados? S/N\n");
    scanf("%c",&confirmacion);
    getchar();
    if(tolower(confirmacion) != 's' && tolower(confirmacion) != 'n')
    {
      printf("Escriba S / N\n");
    }
  }while(tolower(confirmacion) != 's' && tolower(confirmacion) != 'n');
  
  return confirmacion;
}

void maestro_de_empleados(){
  char caracter, opcion;
  int contador = 0, numeroSem = 0, horas = 0, horasExt = 0, Ge=0, Th=0, Tc=0;
  float salarioGe = 0, salarioTh = 0, salarioTc = 0, valor = 0, Total = 0;

  do{
    printf("Maestro de empleados:\n");
    printf("A. Gerente\n");
    printf("B. Trabajadores con horario\n");
    printf("C. Trabajadores a comision\n");
    opcion = getchar();
    getchar();

    switch (tolower(opcion)){

      case 'a':

        do{
          printf("Ingrese el numero de semanas que trabajo el gerente 1 a 4 semnas\n");
          scanf("%d",&numeroSem);
          getchar();
        }while(numeroSem < 1 || numeroSem > 4);
        valor = numeroSem * 1380.57;
        salarioGe += valor;
        Ge++;
        break;

      case 'b':

        do{
          printf("Ingrese el numero de horas que trabajo\n");
          scanf("%d",&horas);
          if(horas < 0){
            printf("Solo numeros positivos");
          }
          getchar();
        }while(horas < 0);

          if(horas > 40){
            horasExt = horas - 40;
            salarioTh = 560.84+(horasExt * 21.0315);
          }
          else
          {
            salarioTh = horas * 14.021;
          }
        Th++;
        break;

      case 'c':
        do{
          printf("Ingrese el valor de ventas realizadas\n");
          scanf("%f",&valor);
          if(valor < 0){
            printf("Solo numeros positivos");
          }
          getchar();
        }while(valor < 0);
        salarioTc = (valor * 0.046)+425.99 ;
        Tc++;
        break;
      default:
        printf("El empleado no esta dentro del menú\n");
      break;
    }
    if(tolower(opcion) == 'a'|| tolower(opcion) == 'b' || tolower(opcion) == 'c')
    {
      contador++;
      caracter = confirmacion();    
    }
  }while(caracter == 's');

  printf("Existen %d gerentes\n",Ge);
  printf("Existen %d Tabajadores por horario\n",Th);
  printf("Existen %d Tabajadores por comision\n",Tc);
  printf("\n");
  printf("Lo que se debe pagar a los gerentes es %.2f\n",salarioGe);
  printf("Lo que se debe pagar a los Tabajadores por horario es %.2f\n",salarioTh);
  printf("Lo que se debe pagar a los Tabajadores por comision es %.2f\n",salarioTc);
  printf("\n");
  Total = salarioGe + salarioTc + salarioTh;
  printf("El procentaje que ocupa los gerentes es %.2f\n",(salarioGe/Total)*100);
  printf("El procentaje que ocupa los Tabajadores por horario es %.2f\n",(salarioTh/Total)*100);
  printf("El procentaje que ocupa los Tabajadores por comision es %.2f\n",(salarioTc/Total)*100);
  printf("\n");
  printf("El total que la empresa debe pagar es de %.2f dolares",Total);
  
}

int main(void) {
  maestro_de_empleados();
  return 0;
}