// delay 1s
union reg {
struct bitsy {
unsigned int b0: 1;
unsigned int b1: 1;
unsigned int b2: 1;
unsigned int b3: 1;
unsigned int b4: 1;
unsigned int b5: 1;
unsigned int b6: 1;
unsigned int b7: 1;
} bits;
int bytes: 8;
} x;

void init(int ocr) {
DDRB |= (1 << PB5);
cli();

OCR0A = ocr;
TCCR0A |= (1 << WGM01) | (1 << COM0A0);
TCCR0B |= (1 << CS02) | (1 << CS00);
TIMSK0 |= (1 << OCIE0A);
sei();
}

void start(int millies) {
int temp = 0;

if (millies < 256) {
init(millies);
} else {
temp = ceil(millies / 255.0);
x.bytes = temp;

while (x.bytes > 0) {
init(255);
}
}
}

int main() {
while (1) {
start(17000);
PORTB ^= (1 << PB5);
}
}

ISR(TIMER0_COMPA_vect) {
x.bytes -= 1;
}
