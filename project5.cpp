#include <stm32f30x.h>

void main() {
  RCC   -> AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOEEN; // Abilitazione clock sulla porta A ed E
  GPIOE -> MODER = 0x55550000;                                // Settaggio delle linee dei led come OUTPUT
  GPIOA -> MODER = ~GPIO_MODER_MODER0;                        // Settaggio linea pulsante come INPUT

  int cont = 0;  // Variabile contatore

  while (1) {
    // Se il tasto è premuto..
    if ((GPIOA -> IDR & GPIO_IDR_0) == GPIO_IDR_0) {
      // Una volta entrati all'interno del if, il cliclo mette in pausa il codice
      // finché non viene lasciato il pulsante
      while ((GPIOA -> IDR & GPIO_IDR_0) == GPIO_IDR_0);
      cont++; // Incremento
      GPIOE -> ODR = (cont << 8); // Traslazione del valore binario di cout sulle celle interessate
    }
  }
} // main()
