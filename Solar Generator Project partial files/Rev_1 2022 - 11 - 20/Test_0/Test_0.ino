#define master PA_8

void setup() {
  // put your setup code here, to run once:

  // cycled at duty cycle
  pinMode(master, OUTPUT); // this is D8
  Serial.begin(115200);

  // since the MOSFET is normally open and close only when Gate voltage meets requirements
  // the output will be regulated in reverse
  // e.g. if duty cycle is 1 then output is 0
  // vice versa
}

void loop() {
  // put your main code here, to run repeatedly:
  float duty = 0.5;
  analogWrite(master, duty*255);
  Serial.print(analogRead(PA_0) * 5.0 / 1023.0 * (5.0+1.0) / 1.0);
  Serial.println();
}
