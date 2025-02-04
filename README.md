# Repositório da Sprint-8
### Objetivo
O objetivo desse projeto é utilizar um Arduino Uno mais um Sensor Magnético para monitorar se a porta de um Rack de Rede está **ABERTO** ou **FECHADO**; Enviar essa informação via internet utilizando o protocolo MQTT(**M**essage **Q**ueuing **T**elemetry **T**ransport) para um servidor MQTT hospedado na **A**mazon **W**eb **S**ervice (AWS) e exibir essa informação em um cliente MQTT([MQTT DASH](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR&gl=US)) instalado em um Smartphone, conforme imagem abaixo.

![Circuito](https://i.imgur.com/flrLGf3.png)

Foram utilizadas as seguintes bibliotecas:
* [UIPEthernet](https://www.arduino.cc/reference/en/libraries/uipethernet/)
* [PubSubClient](https://pubsubclient.knolleary.net/)

### Materiais
* Arduino Uno
* Módulo Ethernet(ENC28J60)
* Sensor Magnético(MC-38
* Jumpers

### Circuito

![Circuito](https://i.imgur.com/AaG8NmP.png)

#### Autor:  Lucas Pedretti
