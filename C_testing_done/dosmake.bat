::set ac=C:\WinAVR-20100110
:: 2020-09-07, download avr-gcc 3.6 from Microchip
set ac=C:\avr8-gnu-toolchain-win32_x86

path %ac%\bin;%ac%\utils\bin;%path%;"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\"

avr-gcc --version

make

cmd
