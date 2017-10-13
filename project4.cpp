#include <stm32f30x.h>

void main() {
  RCC   -> AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOEEN; // Abilitazione clock sulla porta A ed E
  GPIOE -> MODER = 0x55550000;                                // Settaggio delle linee dei led come OUTPUT
  GPIOA -> MODER = ~GPIO_MODER_MODER0;                        // Settaggio linea pulsante come INPUT

  while (1) {
    // Se il tasto è premuto, se il GPIOA_IDR ha la cella corrispondente al
    // tasto uguale a 1 ...
    if ((GPIOA -> IDR & GPIO_IDR_0) == GPIO_IDR_0) {
      GPIOE -> ODR = 0x0000FF00;  // Accendi i LED
    } else {
      GPIOE -> ODR = 0;           // Spegni i LED
    }
  }
} // main()
