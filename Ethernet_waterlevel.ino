#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAC };
byte ip[] = {192, 168, 1, 11 }; //Enter the IP of ethernet shield
byte serv[] = {192, 168, 1, 100} ; //Enter the IPv4 address

EthernetClient cliente;

void setup() {
Serial.begin(9600); //setting the baud rate at 9600
Ethernet.begin(mac, ip);

pinMode(A0,INPUT);

}

void loop() {

 /////////////////////////////////////////////
  int level=0;
  float teglevel = analogRead(A0)*0.00322265625*1.0;
  if (teglevel<3.3){ level=9; }
  if (teglevel<2.8){ level=8; }
  if (teglevel<2.0){ level=7; }
  if (teglevel<1.4){ level=6; }
  if (teglevel<1.07){ level=5; }
  if (teglevel<0.86){ level=4; }
  if (teglevel<0.72){ level=3; }
  if (teglevel<0.62){ level=2; }
  if (teglevel<0.54){ level=1; }
  if (teglevel<0.4){ level=0; }
  //level=analogRead(A0);
  //level = 11;
  //Serial.print(teglevel);
    
  /////////////////////////////////////////////

    if (cliente.connect(serv, 80)) { //Connecting at the IP address and port we saved before
      Serial.println("connected");
        cliente.print("GET /angkasapura/insert.php?"); //Connecting and Sending values to database
        cliente.print("level=");
        cliente.print(level);
        cliente.print("&ip=");
        cliente.println("192.168.1.11");

//Printing the values on the serial monitor
Serial.print("level= ");
Serial.println(level);
Serial.print("ip=");
Serial.println("192.168.1.11");

cliente.stop(); //Closing the connection
}
else {
// if you didn't get a connection to the server:
Serial.println("connection failed");
}
delay(4000);
}
