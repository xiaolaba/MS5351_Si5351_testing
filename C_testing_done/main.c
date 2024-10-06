/*
	direct manipulate MS5351 regsiter, testing, no uses any Si5351 library
	clk0/1/2, all on for 2MHz, output about 1.33MHz, no good, almost -50%, why
	98Hz no clock output cycle, 200us silent, no good, but why ?
	
	MS5351 register map and setting, 
	MS5351_频率输出工具.rar
	download https://www.relmon.com/index.php/support/
	try and save setting to csv, convert to C code, see excel file

	uses Arduino UNO, default SDA/SCL pin A4/A5, avr-gcc build hex, burn hex
	
	by xiaolaba, 2024-OCT-01
*/

#include "i2c.h"
#include "MS5351_reg_map_2MHZ_3ch_setting.h"	// MS5351 registers and set to create 2MHz for clk0/1/2

void ms5351clk_off()
{
	i2cSendRegister(3, 0xff);
}

void ms5351divn_off()
{
	i2cSendRegister(16, 0x80);	
	i2cSendRegister(17, 0x80);	
	i2cSendRegister(18, 0x80);
}

void ms5351pll_set()
{
	  i2cSendRegister(177, 0xAC);
}

void ms5351clk_on()
{
	  //i2cSendRegister(3, 0b10101000);	//clk0 only, but something wrong
	  i2cSendRegister(3, 0);	// clk0/1/2 all on
}

// loop, set each register, MS5351_reg_map_2MHZ_3ch.h
void ms5351setFrequency(uint8_t *reg_values, uint8_t length) {
    for (uint8_t i = 0; i < length; i += 2) {
			uint8_t reg = reg_values[i];
			uint8_t value = reg_values[i + 1];

			i2cSendRegister(reg, value);
    }
}




int main(void)
{
	i2cInit();
	ms5351clk_off();
	ms5351divn_off();
	
	// Send register-value pairs
    ms5351setFrequency(reg_values, sizeof(reg_values));
	
	ms5351pll_set();
	ms5351clk_on();

	return 0;
}