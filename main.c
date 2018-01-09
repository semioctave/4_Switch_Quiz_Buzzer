// ***** 0. Documentation Section *****
// Automatic Quiz Buzzer System 
// Switch with has been pressed first ,its LED Flashes & rest all LEDs 
// remains OFF , also a buzzer will buzzes for 2.4 sec whenever a switch 
// is pressed

// Author : Harshit Srivastava
// Date : 13th December 2017

// ***** 1. Pre-processor Directives Section *****



// ***** 2. Global Declarations Section *****
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

// PortE Control Registers
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

// PortD Control Registers
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
	
// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Port_Init(void);// Initializes the port
void Delay1ms(unsigned long msec); // Delay function
// ***** 3. Subroutines Section *****

// To avoid damaging your hardware, ensure that your circuits match the schematic

int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************

  
	Port_Init();

  while(1){
			int Data1 , Data2 , Data3 , Data4 ;
			Data1 = GPIO_PORTD_DATA_R&0x01 ;      
			Data2 = GPIO_PORTD_DATA_R&0x02 ;
			Data3 = GPIO_PORTD_DATA_R&0x04 ;
			Data4 = GPIO_PORTD_DATA_R&0x08 ;

			if (Data1 == 0x01)// If Switch1 is pressed
			{
				int i;
				for(i=0;i<6;i++)
				{
					 GPIO_PORTE_DATA_R = 0x11 ; // LED1 Flashes & buzzer buzzes
					 Delay1ms(200);
					 GPIO_PORTE_DATA_R = 0x00 ;
					 Delay1ms(200);
				}
				GPIO_PORTE_DATA_R = 0x01 ; // LED1 stablises.
			}
			
			else if (Data2 == 0x02 ) // If Switch2 is pressed
			{
				int i;
				for(i=0;i<6;i++)
				{
					 GPIO_PORTE_DATA_R = 0x12 ; // LED2 Flashes & buzzer buzzes
					 Delay1ms(200);
					 GPIO_PORTE_DATA_R = 0x00 ;
					 Delay1ms(200);	
				}
				GPIO_PORTE_DATA_R = 0x02 ; // LED2 stablises.
			}
			
			else if (Data3 == 0x04 ) // If Switch3 is pressed
			{
				int i;
				for(i=0;i<6;i++)
				{
					 GPIO_PORTE_DATA_R = 0x14 ; // LED3 Flashes & buzzer buzzes
					 Delay1ms(200);
					 GPIO_PORTE_DATA_R = 0x00 ;
					 Delay1ms(200);
				}
				GPIO_PORTE_DATA_R = 0x04 ; // LED3 stablises.
			}
			 
			else if (Data4 == 0x08 ) // If Switch4 is pressed
			{
				int i;
				for(i=0;i<6;i++)
				{
					 GPIO_PORTE_DATA_R = 0x18 ; // LED4 Flashes & buzzer buzzes
					 Delay1ms(200);
					 GPIO_PORTE_DATA_R = 0x00 ; 
					 Delay1ms(200);
				}
				GPIO_PORTE_DATA_R = 0x08 ; // LED4 stablises.
			}
			
  }
  
}

void Port_Init(void)
{
		unsigned long int Delay;
		SYSCTL_RCGC2_R = SYSCTL_RCGC2_R | 0x18 ; // Enables Clock for PortE & PortD
		Delay = SYSCTL_RCGC2_R ; // Time for Clock to get stabilised
		
	// Initializes PortE
		GPIO_PORTE_AMSEL_R = 0x00; // Disables Analog Funtion
		GPIO_PORTE_AFSEL_R = 0x00; // No Alternate function selected
		GPIO_PORTE_PCTL_R  = 0x00000000; // Clears pin PCTL
		GPIO_PORTE_PUR_R   = 0x00 ; // No Pull up resistor to be activated
		GPIO_PORTE_DEN_R   = 0x1F; // Enables Digital Functionality  for PE1 & PE0
		GPIO_PORTE_DIR_R   = 0x1F; // Enables PE0 , PE1 , PE2 , PE3 , PE4 as Output

	// Initializes PortD
		GPIO_PORTD_AMSEL_R = 0x00; // Disables Analog Function
		GPIO_PORTD_AFSEL_R = 0x00; // No Alternate function selected
		GPIO_PORTD_PCTL_R  = 0x00000000; // Clears pin PCTL
		GPIO_PORTD_PUR_R   = 0x00; // No Pull up resistor to be activated
		GPIO_PORTD_DEN_R   = 0x0F; // Enables Digital Functionality for PD0 , PD1 , PD2 , PD3.
		GPIO_PORTD_DIR_R   = 0x00; // Enables PD0 , PD1 , PD2 , PD3 as Input.

}

void Delay1ms(unsigned long msec){
	unsigned long i;
  while(msec > 0)
		{
				i = 13333;  // this number means 1ms
				while(i > 0)
				{
					i = i - 1;
				}
				msec = msec - 1; // decrements every 1ms// write this function

		}
}
