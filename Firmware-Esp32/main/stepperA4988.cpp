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
      //vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,0);
      stepAcel(2400);
      //vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,1);
      stepAcel(2400);
}

void stepAcel (int steps)
{
  int speedMax = 2000;
  int speedMin = 100;
  int MudSenti = 2;

  int stopStepAcel = (speedMax - speedMin) / MudSenti;

  if ( stopStepAcel > steps / 2 )
    stopStepAcel = steps / 2;
  int initStepAcel = steps - stopStepAcel;

  int d = speedMax;

  for( int i = 0; i < steps; ++i)
  {
    gpio_set_level(this->step_pin,1);
    gpio_set_level(this->step_pin,0);
    vTaskDelay(d);

    if(i < stopStepAcel)
      d -= MudSenti;
    else if(i < stopStepAcel)
      d += MudSenti;
  }
}
