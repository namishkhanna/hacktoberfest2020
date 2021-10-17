//delay 1s
int count;

int main() {
DDRB |= (1<<PB1); 
cli();

OCR0A = 255;
TCCR0A |= (1 << WGM01) | (1 << COM0A0);
TCCR0B |= (1 << CS01) | (1 << CS00);
TIMSK0 |= (1 << OCIE0A);
count = 0;
sei();

while (1);
}

ISR(TIMER0_COMPA_vect) {
if (count > 1000) {
PORTB ^= (1 << PB1);
count = 0;
}
count++;
}



