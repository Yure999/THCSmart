  // base measures
  const int dryValue = 450;
  const int waterValue = 250;
  
  // ideal moisture value
  const int idealMoisture = 370;
  
  int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor0Value;
  int sensor1Value;
  sensor0Value = analogRead(A0);
  sensor1Value = analogRead(A1);

  int currentMoisture;
  currentMoisture = (sensor0Value + sensor1Value) / 2;
  

  if(currentMoisture == idealMoisture) {
    Serial.print("Humedad perfecta");
  } else if(currentMoisture < idealMoisture && currentMoisture > waterValue) {
    Serial.print("Demasiada humedad");
  } else if(currentMoisture < waterValue) {
    Serial.print("Las plantas se estan ahogando");
  } else if(currentMoisture > idealMoisture && currentMoisture < dryValue) {
    Serial.print("No les vendria mal un poco de agua");
  } else if (currentMoisture > dryValue) {
    Serial.print("la tierra esta seca");
  }
  Serial.println(currentMoisture);
  delay(800);
}
