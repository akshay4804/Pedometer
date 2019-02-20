 // Calibration and Pedometer function for Sensor Systems Project 1, which was written by Akshay Kumar, 671116
// The calibration process has been commented out as the analysis done during the project produced consistent results. 
// The calibration process was also removed for improved speed. It has been left in for full transparency for the purposes of the project and assignment
// Defining the various parameters, where A0 was set to read the X values, A1 for Y and A2 for Z. 
float analogPin_x = A0;
float analogPin_y = A1;
float analogPin_z = A2;
// This counts the steps
int stepcounter = 0;


int LEDPin = 13;
// The different acceleration values being read from the accelerometer
float valx = 0;
float valy = 0;
float valz = 0;
float total_acc = 0;

float sensorValuez;
float sensorValuey;
float sensorValuex;
// These are the maximum and minimum values determined after calibration
float maxz = 404.5;
float minz = 272;
float maxx = 395;
float maxy = 398;
float minx = 262;
float miny = 262;


void setup() {
  // The LED turns on as an indication of the calibration process
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  Serial.begin(9600);
  
// This section below is the calibration process which has been commented out.   
//  while (millis()<10000){
//    
//    valz = analogRead(analogPin_z);
//    if (valz > maxz){
//      maxz = valz;
//    }
//    if (valz < minz){
//      minz = valz;
//    }
//    valy = analogRead(analogPin_y);
//    if (valy > maxy){
//      maxy = valy;
//    }
//    if (valy < miny){
//      miny = valy;
//    }
//    valx = analogRead(analogPin_x);
//    if (valx > maxx){
//      maxx = valx;
//    }
//    if (valx < minx){
//      minx = valx;
//    }
//  }
  digitalWrite(13, LOW); // This signfies the end of the calibration process

  
}
// A custom made version of the map function to ensure that floats are returned instead of integers
float map2_float(float value_read, float cal_min, float cal_max, float cal_min_actual, float cal_max_actual)
{
  return (value_read - cal_min) * (cal_max_actual - cal_min) / (cal_max - cal_min) + cal_min_actual;
}
void loop() {
  float G = 1;
  float calib_conv = (maxz - minz)/2;
  // This assigns the accelerometer readings into the the following 3 variables
  valz = analogRead(analogPin_z);
  valy = analogRead(analogPin_y);
  valx = analogRead(analogPin_x);

  // These 3 variables below allows for the maximum and minimum values determine during the calibration process to be mapped directly to +G and -G 
  sensorValuez = map2_float(valz, minz, maxz,  -G, G);
  sensorValuey = map2_float(valy, miny, maxy,  -G, G);
  sensorValuex = map2_float(valx, minx, maxx,  -G, G);

// This section was prevously printing directly into the Serial Monitor to monitor and see the values change
//  //Serial.print("x:");
//  Serial.print(sensorValuex);
//  Serial.print("\t");
//  //Serial.print("y:");
//  Serial.print(sensorValuey);
//  Serial.print("\t");
//  //Serial.print("z:");
//  Serial.print(sensorValuez);
//  Serial.print("\n");

  // The absolute acceleration calculation to assist in the counting of steps for the pedometer. 
  total_acc = sqrt(sensorValuex*sensorValuex + sensorValuey*sensorValuey + sensorValuez*sensorValuez);
  // The threshold used for the counting of the steps, with the total_acc being used for the right leg, and the sensorValueX being used for the left leg
  if ((total_acc > 1.05)||(sensorValuex<-1.05)){
    stepcounter += 1;
    // Print out each time a single step is taken
    Serial.print(stepcounter);
    Serial.print("\n");
    delay(500); // The delay prevents double steps from being counted
  }
    

}


