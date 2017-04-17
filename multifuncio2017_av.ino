avançat




//////////////////////////////////////////////////////////////////////////////////////
/*Canvi d'estat d'un Led per pulsació d'un polsador
  A cada pulsació es canvia de estat (encés-apagat)
  No importa el temps que dura cada polsacio.
  Un interruptor general encen i apaga totos els leds a l'hora amb indepedencia
  del deu estat previ.
  si estant apagats, amb els polsadors es poden encendre i apagar.
*/

const int polsadorBlau = 2;//conexió polsador blau.................
const int polsadorGroc = 3;//conexió polsador groc........
const int sw = 8;//conexió polsador marxa. Cable gris 

int canviPolsBlau = 0; //variable per canviar d'estat
int canviPolsGroc = 0;

int estatPolsadorBlau = 0;
int estatPolsadorGroc = 0;
int estatSw = 0;
int previEstatSw = 0;


int previEstatPolsadorBlau = 0;
int previEstatPolsadorGroc = 0;

const int ledPinBlau = 6;
const int ledPinGroc = 7;



void setup() {
  Serial.begin(9600);
  pinMode(ledPinBlau,OUTPUT);
  pinMode(ledPinGroc,OUTPUT);
  pinMode(polsadorBlau,INPUT);
  pinMode(polsadorGroc,INPUT);
  pinMode(sw,INPUT);
  
}

void loop() {
  estatSw = digitalRead(sw);
  
  if (estatSw == HIGH){
    digitalWrite (ledPinBlau,HIGH);
    digitalWrite (ledPinGroc,HIGH); 
    previEstatSw = estatSw;
    Serial.println(estatSw);
    Serial.println(previEstatSw);
  }  
  
  //Serial.println(estatSw);
    //Serial.println(previEstatSw);
    if(estatSw == LOW && previEstatSw == HIGH){
      digitalWrite (ledPinBlau,LOW);
      digitalWrite (ledPinGroc,LOW);
      previEstatSw = estatSw;
      Serial.print("estatSw_LH");
      Serial.println(estatSw);
      Serial.println("previEstatSw_LH");
      Serial.println(previEstatSw);
      delay(100);
    } 
    if(estatSw == LOW && previEstatSw == LOW){
      estatPolsadorBlau = digitalRead(polsadorBlau);
      if (estatPolsadorBlau != previEstatPolsadorBlau){ //es compara l'estat actual del polsador i l'actual
        if (estatPolsadorBlau == HIGH ){
          canviPolsBlau =! canviPolsBlau; //Es canvia d'estat, de 0 a 1 ó de 1 a 0
        }
        if (canviPolsBlau == HIGH){
          digitalWrite (ledPinBlau,HIGH);
        }
        if (canviPolsBlau == LOW){
          digitalWrite (ledPinBlau,LOW);
        }
      } 
      previEstatPolsadorBlau = estatPolsadorBlau;
     
  
      
 
/////////////////////////////////////////////////////////////////////
      estatPolsadorGroc = digitalRead(polsadorGroc);
      if (estatPolsadorGroc != previEstatPolsadorGroc){ 
        if (estatPolsadorGroc == HIGH){
        canviPolsGroc =! canviPolsGroc; 
        }
        if (canviPolsGroc == HIGH){
          digitalWrite (ledPinGroc,HIGH);
        }  
        if (canviPolsGroc == LOW){
          digitalWrite (ledPinGroc,LOW);
        }
      }  
      previEstatPolsadorGroc = estatPolsadorGroc;
    }
  
} 

///////////////////////////////////////////////////////////////////////  
  

