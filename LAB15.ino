#include <LiquidCrystal.h>

  #include <Servo.h>
  
LiquidCrystal lcd {13,12, 11, 10, 9 , 8 };

//ultrasonic pin
const int echoPin = 2; 
const int trigPin = 3;

//identify servo
Servo myservo;

                                              

  void setup(){

    // set in & out pins

    //ultrasonic pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    //servo pin out

     myservo.attach(1); 

    //driver motor pin out
    pinMode(4,OUTPUT);
     pinMode(5,OUTPUT);

    //set lcd pins
    lcd.begin(16,2);
    lcd.clear();
 
   
    }

    void loop(){

     

  //read distance
      long duration, inches, cm , distance;
      digitalWrite(trigPin,LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin ,HIGH);
      delayMicroseconds(10);

      digitalWrite(trigPin ,LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = ((duration* 0.034)/2 );

    
    //check distnce and run motors
    if(distance <= 300){

                                     
      //SERVO
      myservo.write(90);
      //MOTOR DRIVER
      digitalWrite(4,1);
      digitalWrite(5,0);
      }
     else{

                                              
      //SERVO
 
      myservo.write(0);

       //MOTRO DRIVER
       digitalWrite(4,0);
       digitalWrite(5,0);
                                                 
      }
  // print on lcd
         lcd.clear();
         lcd.print("Distance: " );
         lcd.print( distance);
         lcd.print(" cm " );
         lcd.setCursor(0,1);
      }

     







      
