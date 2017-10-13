// Mapping degli indirizzi di memoria
#define RCC_AHBENR  0x40021014
#define GPIOE_MODER 0x48001000
#define GPIOE_ODR   0x48001014

unsigned int* p;  // Puntatore di servizio

void main() {
  // Abilitazione clock su porte A ed E
   p = (unsigned int*) RCC_AHBENR;
  *p = (1 << 21);


  // Settaggio in modalità output LED
   p  = (unsigned int*) GPIOE_MODER;
  *p  = (1 << 16) | (1 << 22);


  // Settaggio in modalità input linea tasto USER
   p = (unsigned int*) GPIOA_MODER;
  *p = (1 << 8) | (1 << 11);

  while(1);

} // main()
