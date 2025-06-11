// End Game Simplified

int x = 0;
int y = 0;

int end_x = 10;
int end_y = 0;

int obs_x = 6;
int obs_y = 0;

String readSerial(String pretext = ""){
  //To Read from User
  Serial.println(pretext);
  while (Serial.available() == 0) {}
  return Serial.readString();
}

void move(String direction)
{
  if(direction == "right")
  {
    x = x + 1;
  }
  else if(direction == "left")
  {
   	x = x - 1; 
  }
  else if(direction == "up")
  {
   	y = y + 1; 
  }
  else if(direction == "down")
  {
    y = y - 1;
  }
    
  
  
  Serial.println("New Loc: x = " + String(x) + " y = "+ String(y));
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


void loop() //Runs Forever
{
  while(x < end_x)
  {
    if(x + 1 == obs_x && y == obs_y)
    {
      Serial.println("> Saw Obstacle");
      move("up");
      move("right");
      move("down");
    }
    else
    {
    	move("right");
    }
  }
  
  while(y < end_y)
  {
   	move("up"); 
  }
  
  while(x > end_x)
  {
    move("left");
  }
  
  while(y > end_y)
  {
    move("down");
  }
}
