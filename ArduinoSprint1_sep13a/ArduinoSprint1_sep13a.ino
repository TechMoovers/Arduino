#include "DHT.h"
#define dht_type DHT11            //puxar biblioteca com as funções que serão usadas
int dht_pin = A1;                 //coletar os dados das entradas
DHT dht_1 = DHT(dht_pin, dht_type);
int switch_pin = 7;

int lm35_pin = A0, leitura_lm35 = 0;
float temperatura;

void setup() {                                //configurações iniciais
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht_1.begin();
  pinMode(switch_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:       !!!!código de saída
 float umidade = dht_1.readHumidity();                  //tudo que aparecerá na tela
float temperatura = dht_1.readTemperature();            //em repetição, setado pelo delay que o programa está configurado
if (isnan(temperatura) or isnan(umidade))
{                                                       //readHumidity = função que calcula a porcentagem da umidade do ar
Serial.println("Erro ao ler o DHT");                    //condição de validação do sensor de UMIDADE
}
else
{
Serial.print("Umidade: ");
Serial.println(umidade);
}
  leitura_lm35 = analogRead(lm35_pin);                  
  temperatura = leitura_lm35 * (5.0/1023) * 100;        //leitura da captura de dado, converte para bits e então milivolts
  Serial.print ("TemperaturaLM35: ");                   //milivolts para celsius
  Serial.println(temperatura);
  delay (3000);
  
}