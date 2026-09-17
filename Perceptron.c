#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define epoca 3000000
#define K 0.03f


//0.00000
//Funcion de Entrenamiento Perceptron
float EntNt(float, float, float  );
//Funcion para las salidas
float InitNt(float, float);
//Sigmoide
float sigmoide(float);
//pesos aleatorios
void pesos_initNt();


float Pesos[2];
float bias=0.5f;
float PesosOR[2];
float biasOR=0.5f;
float PesosXOR[2];
float biasXOR=0.5f;
float Error;

//PARA ENTRENAR LA OR
float EntOR(float x0, float x1, float target) {
    float net = PesosOR[0]*x0 + PesosOR[1]*x1 - biasOR;
    net = sigmoide(net);
    float error = target - net;
    biasOR -= K*error;
    PesosOR[0] += K*error*x0;
    PesosOR[1] += K*error*x1;
    return net;
}
 //                 1          1          1
 //                 0          1         0
 //                 1          0         0
 //                0          0          0
 // PARA ENTRENAR LA AND
float EntNt( float x0, float x1, float target )
{

//printf("x0=%f, x1=%f, t %f \n" ,x0, x1,  target );

  float net = 0;
  float out = 0;
  float delta[2];  //Es la variacion de los pesos sinapticos
  //float Error;

  net = Pesos[0]*x0 + Pesos[1]*x1 - bias;
  net = sigmoide( net );

  Error = target - net;
  //printf("Error funcion %f \n", Error);
  bias -= K*Error;  //Como el bias es siempre 1, pongo que
                    //el bias incluye ya su peso sinaptico

  delta[0] = K*Error * x0;  //la variacion de los pesos sinapticos corresponde
  delta[1] = K*Error * x1;  //al error cometido, por la entrada correspondiente


  Pesos[0] += delta[0];  //Se ajustan los nuevos valores
  Pesos[1] += delta[1];  //de los pesos sinapticos



  out=net;
  return out;
}


//PARA ENTENAR LA XOR CON SALIDAS DE LAS OTRAS
// Entrenamiento para compuerta XOR usando salidas de AND y OR
float EntXOR(float andOut, float orOut, float target) {
    float net = PesosXOR[0]*andOut + PesosXOR[1]*orOut - biasXOR;
    net = sigmoide(net);
    float error = target - net;
    biasXOR -= K*error;
    PesosXOR[0] += K*error*andOut;
    PesosXOR[1] += K*error*orOut;
    return net;
}

float InitNt( float x0, float x1 )
{
  float net = 0;
  float out = 0;
//Pesos de cada epoca
//Peso 1 = 30.753101
//Peso 2 = 30.780966
//BiasBias = 61.583714
//Resultados
//  net = 1.23*x0 + 2.4*x1+23;
//Peso 1 = 989.755493
//Peso 2 = -1407.284180
//Bias = 989.755981


net = 70.934807*x0 + 93.935219*x1 - 187.886169 ;


  //net = 316.518982*x0 + 316.522095*x1-633.045837;
  net=sigmoide( net );

  out=net;
  return out;
}




void pesos_initNt(void)
{
int i;
  for(  i = 0; i < 2; i++ )
  {
    Pesos[i] = (float)rand()/RAND_MAX;
  }
}

float sigmoide( float s ){
  return (1/(1+ (-1*s)));
}


int main(){
  int i=0;
  float apr;
  pesos_initNt();

 while(i<epoca){

    printf("------------------------\n");
    printf("Salida Entrenamiento Epoco %d \n", i);
    apr=EntNt(1,1,0);
    printf("1,1=%f\n",apr);
    apr=EntNt(1,0,1);
    printf("1,0=%f\n",apr);
    apr=EntNt(0,1,1);
    printf("0,1=%f\n",apr);
    apr=EntNt(0,0,0);
    printf("0,0=%f\n",apr);
    printf("\n");
    printf("Pesos de cada epoca\n");
    printf("Peso 0 = %f\n", Pesos[0]);
    printf("Peso 1 = %f\n", Pesos[1]);

    printf("Bias = %f \n",bias);
	printf("Error %f\n ",Error  );
	printf("------------------------\n");
	i++;
/*


    printf("Resultados\n");
    apr=InitNt(1,1);
    printf("1,1=%f\n",apr);
    apr=InitNt(1,0);
    printf("1,0=%f\n",apr);
    apr=InitNt(0,1);
    printf("0,1=%f\n",apr);
    apr=InitNt(0,0);
    printf("0,0=%f\n",apr);
*/


}


  return 0;
}
