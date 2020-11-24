int dipA, dipB, dipC, dipD;
double pot;

void setup()
{
  pinMode(A0,INPUT); //potentiometer

  pinMode(4,INPUT); //For Dip Switch
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  
  pinMode(8,INPUT); //2nd input for chip
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  pot = map(analogRead(A0),0,1023,0,255);
  Serial.println(pot);
  dipA = digitalRead(7);
  dipB = digitalRead(6);
  dipC = digitalRead(5);
  dipD = digitalRead(4);
  delay(25);
  
  if (dipA == 0 && dipB == 0 && dipC == 0 && dipD == 0) {
    //stop
  	digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, pot);
    digitalWrite(11, pot);
    delay(25);
  }
  else if (dipA == 0 && dipB == 0 && dipC == 0 && dipD == 1) {
    //left
  	digitalWrite(8, pot);	//stop
    digitalWrite(9, LOW);	//stop
    digitalWrite(10, pot);	//stop
    digitalWrite(11, LOW);	//stop
    delay(25);
  }
  else if (dipA == 0 && dipB == 0 && dipC == 1 && dipD == 0) {
    //right
  	digitalWrite(8, LOW);
    digitalWrite(9, pot);
    digitalWrite(10, LOW);
    digitalWrite(11, pot);
    delay(25);
  }
  
  else if (dipA == 1 && dipB == 0 && dipC == 0 && dipD == 0) {
    //front
  	digitalWrite(8, pot);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, pot);
    delay(25);
  }
  
  else if (dipA == 0 && dipB == 1 && dipC == 0 && dipD == 0) {
    //reverse
  	digitalWrite(8, LOW);
    digitalWrite(9, pot);
    digitalWrite(10, pot);
    digitalWrite(11, LOW);
    delay(25);
  }
}
