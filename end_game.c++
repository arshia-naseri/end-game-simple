// End Game Simplified

int x = 0;
int y = 0;

String readSerial(String pretext = ""){
  //To Read from User
  Serial.println(pretext);
  while (Serial.available() == 0) {}
  return Serial.readString();
}

void setup() //Runs once
{
  Serial.begin(9600);
  // Clears Monitor
  for(int i=0; i<50; i++) Serial.println("\n");
  
  Serial.println("> Welcome to Maze simple");
  Serial.println("> Your Starting location is: x= "+ String(x) + " y= "+ String(y)); 
  
  readSerial("type anything to start ...");
}

// YOUR CODE

void move(String direction)
{
  if(direction == "right")
  {
    x = x + 1;
  }
  
  
  Serial.println("New Loc: x = " + String(x) + " y = "+ String(y));
}

void loop() //Runs Forever
{
  move("right");
  delay(1000); // Waits 1000 ms or 1 second
}
