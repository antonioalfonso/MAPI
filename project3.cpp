// Mapping degli indirizzi di memoria
#define RCC_AHBENR  0x40021014
#define GPIOE_MODER 0x48001000
#define GPIOA_MODER 0x48000000
#define GPIOE_ODR   0x48001014
#define GPIOA_IDR   0x48000010

unsigned int* p;  // Puntatore di servizio

void main() {
  // Abilitazione clock su porte A ed E
   p = (unsigned int*) RCC_AHBENR;
  *p = (1 << 17) | (1 << 21);


  // Settaggio in modalità output linee dei LED
   p  = (unsigned int*) GPIOE_MODER;
  *p  = (1 << 16) | (1 << 18) | (1 << 20) | (1 << 22);
  *P |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);


  // Settaggio in modalità input linea tasto USER
  p   = (unsigned int*) GPIOA_MODER;
  *p &= 0XFFFFFFFC;

  while(1) {
    
    p = (unsigned int*) GPIOA_IDR;

    // Se il tasto è premuto..
    if ((*p & 1) == 1) {
      // Accendi tutti i LED
       p = (unsigned int*) GPIOE_ODR;
      *p = 0X0000FF00;
    } else {
      // Spegni tutti i LED
       p = (unsigned int*) GPIOE_ODR;
      *p = 0X00000000;
    }

  }

} // main()
