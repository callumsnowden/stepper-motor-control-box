/*
 * Stepper motor control box
 * Callum Snowden 2024
 */

#include <AccelStepper.h>
#include <CommandParser.h>

#define STEP_PIN 10
#define DIRECTION_PIN 9
#define ENABLE_PIN 8

AccelStepper motor(AccelStepper::DRIVER, STEP_PIN, DIRECTION_PIN);

typedef CommandParser<> serialCommandParser;
serialCommandParser parser;

void startCmdHandler(serialCommandParser::Argument *args, char *response) {
  motor.setSpeed(args[0].asDouble);
  strlcpy(response, "success", serialCommandParser::MAX_RESPONSE_SIZE);
}

void stopCmdHandler(serialCommandParser::Argument *args, char *response) {
  motor.setSpeed(0);
  strlcpy(response, "success", serialCommandParser::MAX_RESPONSE_SIZE);
}

void setup() {
  Serial.begin(115200);
  
  motor.setMaxSpeed(1000);
  motor.setSpeed(0);

  // Command parser setup
  parser.registerCommand("start", "d", &startCmdHandler);
  parser.registerCommand("stop", "", &stopCmdHandler);
  parser.registerCommand("speed", "d", &startCmdHandler);
}

void loop() {
  if (Serial.available()) {
    char line[128];
    size_t lineLength = Serial.readBytesUntil('\n', line, 127);
    line[lineLength] = '\0';

    char response[serialCommandParser::MAX_RESPONSE_SIZE];
    parser.processCommand(line, response);
    Serial.println(response);
  }

  motor.runSpeed();
}
