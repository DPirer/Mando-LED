#include <IRremote.h>

// Antes de nada, defino los códigos de cada uno de los botones para que sea
// más facil identificarlos en el caso de que haya que cambiar algo.

#define boton1 0xFFA25D
#define boton2 0xF7807F
#define boton3 0xFFE21D
#define boton4 0xF7C03F
#define boton5 0xF720DF
#define boton6 0xF7A05F
#define boton7 0xF7609F
#define boton8 0xF7E01F
#define boton9 0xF710EF
#define boton10 0xFF6897
#define boton11 0xFF9867
#define boton12 0xFFB04F
#define boton13 0xFF30CF
#define boton14 0xF7B04F
#define boton15 0xF7708F
#define boton16 0xFF10EF
#define boton17 0xF708F7
#define boton18 0xFF5AA5
#define boton19 0xF748B7
#define boton20 0xFF4AB5
#define boton21 0xFF52AD
#define boton22 0xF7A857
#define boton23 0xF76897
#define boton24 0xF7E817

const byte R = 3;
const byte G = 6;
const byte B = 5;
int color = 0;

int receptor = 11;        // El pin 11 es el del receptor infrarrojo
IRrecv irrecv(receptor);  // Iniciamos la recepción en el pin receptor
decode_results results;   // Decodificamos los datos obtenidos

void setup()
{  
  Serial.begin(9600);
  irrecv.enableIRIn();

  analogWrite(R, 255); // Iniciamos nuestra tira apagada. Como es una 
  analogWrite(G, 255); // diferencia de potencial, 255 serdá apagada
  analogWrite(B, 255); // y 0 será encendida.
}

void loop() {
  if (irrecv.decode(&results)) { 
    Serial.println(results.value, HEX);  

    // La siguiente parte el código en la que establecerá qué se hace 
    // en función de que botón se pulse. Ojo, solo he puesto los colores
    // principales, el resto no los uso

    // Encender leds. Se encenderán en el último color en el que se apagaron
    if (results.value == boton1 && color == 0){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 0);} 
    else if (results.value == boton1 && color == 5){analogWrite(R, 0);analogWrite(G, 255);analogWrite(B, 255);color = 5;}     
    else if (results.value == boton1 && color == 6){analogWrite(R, 255);analogWrite(G, 0);analogWrite(B, 255);color = 6;}     
    else if (results.value == boton1 && color == 7){analogWrite(R, 255);analogWrite(G, 255);analogWrite(B, 0);color = 7;}     
    else if (results.value == boton1 && color == 8){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 0);color = 8;}
    else if (results.value == boton1 && color == 14){analogWrite(R, 255);analogWrite(G, 0);analogWrite(B, 0);color = 14;}
    else if (results.value == boton1 && color == 15){analogWrite(R, 0);analogWrite(G, 255);analogWrite(B, 0);color = 15;}
    else if (results.value == boton1 && color == 21){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 255);color = 21;}
    else if (results.value == boton1 && color == 17){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 255);color = 17;}
    else if (results.value == boton1 && color == 13){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 255);color = 13;}

    // Apagar leds
    else if (results.value == boton3){analogWrite(R, 255);analogWrite(G, 255);analogWrite(B, 255);}
    
    // Colores principales
    else if (results.value == boton10){analogWrite(R, 0);analogWrite(G, 255);analogWrite(B, 255);color = 5;}        // Rojo
    else if (results.value == boton11){analogWrite(R, 255);analogWrite(G, 0);analogWrite(B, 255);color = 6;}        // Verde
    else if (results.value == boton12){analogWrite(R, 255);analogWrite(G, 255);analogWrite(B, 0);color = 7;}        // Azul
    else if (results.value == boton21){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 0);color = 8;}            // Blanco

    // Colores de mezcla simple
    else if (results.value == boton18){analogWrite(R, 255);analogWrite(G, 0);analogWrite(B, 0);color = 14;}        // Verdoso
    else if (results.value == boton16){analogWrite(R, 0);analogWrite(G, 255);analogWrite(B, 0);color = 15;}        // Violeta
    else if (results.value == boton20){analogWrite(R, 0);analogWrite(G, 0);analogWrite(B, 255);color = 21;}        // Amarillo

    // Colores de mezcla compleja
    else if (results.value == boton13){analogWrite(R, 128);analogWrite(G, 128);analogWrite(B, 255);color = 17;}    // Naranja
    
    irrecv.resume(); // Recibir el siguiente valor
  }
  delay(100);
}
