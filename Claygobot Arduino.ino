  #include <Servo.h>          //Servo motor library. This is standard library
  #include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
  // Tools > Libraries > Install "NewPing"
 // Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
  int trigPin = 11;    // TRIG pin  RED
  int echoPin = 10;    // ECHO pin  black
  //servo yellow
// For PWM maximum possible values are 0 to 255
// analogWrite(ENA, 255);
// analogWrite(ENB, 255);
    #define maximum_distance 200
  boolean goesForward = false;
  int distance = 100;

  NewPing sonar(trigPin, echoPin, maximum_distance); //sensor function
  Servo servo_motor; //As a magic emperor i define your name servo motor whahahaha

  
  void setup() { 
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	analogWrite(enA, 255);
	analogWrite(enB, 75);



	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);



    servo_motor.attach(6); //depende sa ano pa available slot

    servo_motor.write(115);
    delay(2000);
    distance = readPing();
    delay(100);
    distance = readPing();
    delay(100);
    distance = readPing();
    delay(100);
    distance = readPing();
    delay(100);
  }
  void loop(){

	
    int distanceRight = 0;
    int distanceLeft = 0;
    delay(50);

    // SAN KO LALAGAY YUNG WATER PUMP?
    // BOBO NI PRINCE BANO
    // A

    if (distance <= 20){
      moveStop();
      delay(300);
      moveBackward();
      delay(400);
      moveStop();
      delay(300);
      distanceRight = lookRight();
      delay(300);
      distanceLeft = lookLeft();
      delay(300);

      if (distance >= distanceLeft){
        turnRight();
        moveStop();
      }
      else{
        turnLeft();
        moveStop();
      }
    }
    else{
      moveForward(); 
    }
      distance = readPing();
  }

  int lookRight(){  
    servo_motor.write(50);
    delay(500);
    int distance = readPing();
    delay(100);
    servo_motor.write(115);
    return distance;
  }

  int lookLeft(){
    servo_motor.write(170);
    delay(500);
    int distance = readPing();
    delay(100);
    servo_motor.write(115);
    return distance;
    delay(100);
  }

  int readPing(){
    delay(70);
    int cm = sonar.ping_cm();
    if (cm==0){
      cm=250;
    }
    return cm;
  }

  void moveStop(){
    
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
    // edi stop 
  }

  void moveForward(){

    if(!goesForward){

      goesForward=true;
      
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
    // Moves forward
    }
  }

  void moveBackward(){

    goesForward=false;

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
    // moves backward ang pogi ko pag nabasa mo to haha crush ko si Lawrence Dominique B. Tan, Yes i love myself <3
  }

  void turnRight(){

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
    //Turns right
    delay(1000);
    
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
    // FORWARD
  }
    


  void turnLeft(){

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  // TURNS LEFT
    delay(1000);
    
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
    // FORWARD
  }

