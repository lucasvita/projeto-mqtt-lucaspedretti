#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>

//Define o endereço MAC que será utilizado
byte mac[] = {0xC8, 0x45, 0x17, 0xDF, 0x5D, 0x67};

boolean mensagem;

int pino2 = 2; //Cria uma variável para o Pino 2
bool estado_sensor; //Cria uma variável para Armazenar o estado do sensor

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);
    
    pinMode(pino2,INPUT_PULLUP); //Coloca o Pino 2 como Entrada    

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer("54.144.190.205",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");
}

void loop() {

  estado_sensor = digitalRead(pino2);

  if(estado_sensor == 1){
  Serial.println("O Rack esta ABERTO");
  mensagem = mqttClient.publish("lucaspedretti-p","ABERTO ");
}
  if(estado_sensor == 0){
  Serial.println("O Rack esta FECHADO");
  mensagem = mqttClient.publish("lucaspedretti-p","FECHADO  ");  
    
 }  
  mqttClient.connect("lucaspedretti");

  mensagem = mqttClient.publish("lucaspedretti-t","FUNCIONANDO!");

  Serial.println(mensagem);
  
  mqttClient.loop();  
}
