#include "stepperA4988.h"

stepperA4988::stepperA4988(gpio_num_t step_pin, gpio_num_t direction_pin)
{
    this->step_pin = step_pin;
    this->direction_pin = direction_pin;

    gpio_pad_select_gpio(step_pin);
    gpio_set_direction(step_pin, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(direction_pin);
    gpio_set_direction(direction_pin, GPIO_MODE_OUTPUT);

    this->direction = 0;
    gpio_set_level(this->direction_pin,this->direction);
    return;
}

void stepperA4988::newStep(bool direction)
{
      if(direction != this->direction){
        this->direction = direction;
        gpio_set_level(this->direction_pin,this->direction);
      }
      vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,0);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,1);
}

void stepAcel (int steps)
{
  int delays[STEPS];
  float angle = 1;
  float accel = 0.01;
  float c0 = 2000 * sqrt(2 * angle/accel) * 0.67703;
  float lastDeley = 0;
  int highSpeed = 100;

  for(int i = 0; i < STEPS; ++i)
  {
    float d = c0;

    if(i > 0)
      d = lastDeley - (2 * lastDeley)/(4 * i + 1);
    if(d < highSpeed)
      d = highSpeed;
    delays[i] = d;
    lastDelay = d;
  }
}

int PID (int step, int setepRef)
{
  int kp = 2, ki = 0, kd = 0.5, dt = 1;
  int E = stepRef - step;
  int Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  return kp*E + ki*Ei + kd*Ed;
}
