#define master PA_8

void setup() {
  // put your setup code here, to run once:

  // cycled at duty cycle
  pinMode(master, OUTPUT); // this is D8

  pinMode(PA_0, INPUT_PULLDOWN);
  long double timer = 0;

  Serial.begin(115200);

  pinMode(USER_BTN, INPUT_PULLDOWN);
  pinMode(LED_BUILTIN, OUTPUT);
}
float duty = 0.35;  
bool isButtonDown = 0;
void loop() {

// this function enables the user to switch between 2 different duty cycles to
// test potential functions.
  if (digitalRead(USER_BTN) == HIGH){
    digitalWrite(LED_BUILTIN,LOW);
    if (isButtonDown){
      if (duty == 1){
        duty = 0.1;
      }else{
        duty = 1;
      }
    }
    
    isButtonDown = 0;
    
  }else{
    isButtonDown = 1;
    digitalWrite(LED_BUILTIN, HIGH);
  }



  // put your main code here, to run repeatedly:
  
  analogWrite(master, duty*255);
  float vOut = analogRead(PA_0) * (2200.0/(2200.0+1000.0)) * 3.0/2.0/100;
  Serial.print(analogRead(PA_0) * (2200.0/(2200.0+1000.0)) * 3.0/2.0/100);
 //number found via testing.
  Serial.println();
}

void PID(){

}