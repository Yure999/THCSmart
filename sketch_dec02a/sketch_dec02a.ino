  // base measures
  const int dryValue = 440;
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

  String message;

  if(currentMoisture == idealMoisture) {
    message = "Humedad perfecta";
  } else if(currentMoisture < idealMoisture && currentMoisture > waterValue) {
    message = "Demasiada humedad";
  } else if(currentMoisture < waterValue) {
    message = "Las plantas se estan ahogando";
  } else if(currentMoisture > idealMoisture && currentMoisture < dryValue) {
    message = "No les vendria mal un poco de agua";
  } else if (currentMoisture > dryValue) {
    message = "la tierra esta seca";
  }
  Serial.print(message);
  Serial.println(currentMoisture);
  delay(800);
}
