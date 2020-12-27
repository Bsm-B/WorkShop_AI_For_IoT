#include <Arduino.h>
#include "NeuralNetwork.h"
#include "esp32-hal-cpu.h"

NeuralNetwork *nn;

void setup()
{
  Serial.begin(115200);
  nn = new NeuralNetwork();
  Serial.println((String) getCpuFrequencyMhz()); 
}

void loop()
{
 // 7,196,90,0,0,39.8,0.451,41 -> TRUE
 // 1,85,66,29,0,26.6,0.351,31	=> FALSE
  float number1 = 7;
  float number2 = 196;
  float number3 = 90;
  float number4 = 0;
  float number5 = 0;
  float number6 = 39.8;
  float number7 = 0.451;
  float number8 = 41;


  nn->getInputBuffer()[0] = number1;
  nn->getInputBuffer()[1] = number2;
  nn->getInputBuffer()[2] = number3;
  nn->getInputBuffer()[3] = number4;
  nn->getInputBuffer()[4] = number5;
  nn->getInputBuffer()[5] = number6;
  nn->getInputBuffer()[6] = number7;
  nn->getInputBuffer()[7] = number8;



  float result = nn->predict();

   const char *predicted = result > 0.5 ? "True" : "False";

  Serial.printf("result %.2f  => Predicted %s\n",result , predicted); 

  delay(1000);
  
}