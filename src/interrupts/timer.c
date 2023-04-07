#include "interrupts/timer.h"

void timer_init(uint32_t frequency)
{
    uint32_t divisor = 1193180 / frequency;
    uint8_t low = (uint8_t)(divisor & 0xFF);
    uint8_t high = (uint8_t)((divisor >> 8) & 0xFF);

    asm_write_port(0x43, 0x36);
    asm_write_port(0x40, low);
    asm_write_port(0x40, high);
}

static uint32_t tick = 0;

static uint8_t hour = 0;
static uint8_t min = 0;
static uint8_t sec = 0;

void timer_handler()
{
    tick++;

    if(tick == BASE_FREQ)
    {
        tick = 0;
        sec++;
    }

    if(sec > 59)
    {
        sec = 0;
        min++;
    }

    if(min > 59)
    {
        min = 0;
        hour++;
    }

    // print_text("Time of work: ");

    // if(hour < 10)
    //     print_text("0");

    // print_dec_value((u32int)hour);
    // print_text(":");

    // if(min < 10)
    //     print_text("0");

    // print_dec_value((u32int)min);
    // print_text(":");

    // if(sec < 10)
    //     print_text("0");

    // print_dec_value((u32int)sec);
    // print_text("\r");
}
