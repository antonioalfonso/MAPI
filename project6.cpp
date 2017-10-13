#include <stm32f30x.h>

void main() {
  short int flag = 0; // Variabile si segnalazione on/off

  RCC -> AHBENR |= RCC_AHBENR_GPIOEEN;  // Abilitazione clock su PE
  RCC -> AHBENR |= RCC_APB1ENR_TIM2EN;  // Abilitazione clock su TIM2
  GPIOE -> MODER = 0x55550000;          // OUTPUT per tutti i LED

  TIM2 -> CR1 |= TIM_CR1_CEN;           // Abilitazione conteggio
  TIM2 -> ARR  = 4000000;               // 8 MHz / 2 --> 4 MHz ogni 0.5 secondi
  TIM2 -> CNT  = 0;                     // Ripristinio counter

  while(1) {

    /**
    * Se TIM2_CNT raggiunge quota 4.000.000 grazie all TIM2_ARR viene emmesso un
    * evento che abilita TIM2_SR ad 1...
    */

    // ... e se la variabile flag è uguale a 0 (LED spenti)
    if ((TIM2 -> SR & TIM_SR_UIF) == TIM_SR_UIF && !flag) {
      GPIOE -> ODR = 0x0000FF00;    // Vengono accessi tutti i LED
      TIM2  -> SR  &= ~TIM_SR_UIF;  // Viene ripristinato TIM2_SR a 0

      flag = 1;                     // Viene memorizzato lo stato
    }

    // ... e se la variabile flag è uguale ad 1 (LED accesi)
    if ((TIM2 -> SR & TIM_SR_UIF) == TIM_SR_UIF && flag) {
      GPIOE -> ODR = 0;             // Vengono spenti tutti i LEd
      TIM2  -> SR &= ~TIM_SR_UIF;   // Viene riassegnato TIM2_SR a 0
      flag = 0;                     // Viene memorizzato lo stato

    }

  }
} // main()
