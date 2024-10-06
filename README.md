# MS5351_Si5351_testing
MS5351 and Si5351, many sayings they are equivalent and no need to code change and comprehensive pin-to-pin replacement, let me try...


clone and try this library,  
https://github.com/etherkit/Si5351Arduino

example code, something is missing and I did not undestand yet.

this is code nipeet
```
  // Set CLK0 to output 14 MHz 14,000,000 Hz
  //si5351.set_freq(1400000000ULL, SI5351_CLK0); why 1,400,000,000  ??? 14MHz x 100 ??
  si5351.set_freq(   200000000ULL, SI5351_CLK0); // destired 2MHz, but 1.3MHz frequency, why ?
```
