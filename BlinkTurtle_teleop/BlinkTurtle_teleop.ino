/* 
 * improvitation
 */

#include <ros.h>
#include <turtlesim/Velocity.h>

ros::NodeHandle  nh;

void messageCb( const turtlesim::Velocity& vel){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<turtlesim::Velocity> sub("turtle1/command_velocity", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

