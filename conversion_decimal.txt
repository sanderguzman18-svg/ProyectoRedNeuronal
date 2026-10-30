float data = 0;
int dataReal = 0;
int dataDecimal = 0;
int dataPow = 1;
bool isDecimalStage = false;
bool isNegative = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Conexion Establecida");
}

void loop() {
 while(Serial.available())
  {
   char incomingChar = Serial.read();
   Serial.println(incomingChar);     
   if (incomingChar == '-')
         isNegative = -1;
   
   else if (incomingChar == '.' || incomingChar == ',')
         isDecimalStage = true;
   else if (incomingChar >= '0' && incomingChar <= '9')
      {
         if (isDecimalStage == false)
            dataReal = (dataReal * 10) + (incomingChar - '0');
         else
         {
            dataDecimal = (dataDecimal * 10) + (incomingChar - '0');
            dataPow *= 10;
         }
      }
      else if (incomingChar == '\n')
      {
         data = (float)dataReal + (float)dataDecimal / dataPow;
         data = isNegative ? -data : data;
         delay(1);        
         dataReal = 0;
         dataDecimal = 0;
         dataPow = 1;
         isDecimalStage = false;
         Serial.println(data);
         if(data>0.00){
             digitalWrite(LED_BUILTIN, HIGH);
         }else{
             digitalWrite(LED_BUILTIN, LOW);
         }         
      }
  }
}