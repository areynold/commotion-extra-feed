simple buffer overflow to test the SSP option enabled in
https://github.com/opentechinstitute/commotion-router/issues/22

Usage:
1. Add `src-git areynold git://github.com/areynold/commotion-feed.git` to feeds.conf
2. `./setup.sh`
3. `cd openwrt`
4. `make menuconfig`
4a. Select Commotion > Utilities > ssp_test, which includes SSP compile flags in its Makefile. (Note: I have occasionally had to deselect and reselect Advanced Configuration Options > Toolchain Options > Enable Stack-Smashing-Protection to make the test utility available.)
4b. Save and exit
5. make V=s
6. Flash router. 
7. Telnet to router. No need to run through setup wizard.
8. `cd /root`
9. Run `./smash` to find the address of the vulnerable function. Note that the address format is 0x followed by 8 digits. You only need the digits after "0x". If smash provides fewer than 8, pad the address with 0s as needed. Also note that you will need to reverse the address on little-endian machines. See examples below.
10. Type `printf "meat\x01\x12\x23\x34\x01\x12\x23\x34\x01\x12\x23\x34\x01\x12\x23\x34 | ./smash`. 

If the package was compiled with SSP, smash will abort with the message `*** stack smashing detected ***: smash terminated
Trace/breakpoint trap`. If not, it will execute the target function and print a message to the screen.

Alternately, you can run `strings ./smash` and grep for "__stack_chk_fail", but that's not nearly as cool.

Examples:
If smash returns 0x804849d, you will first need to pad the address (making it 0804849d).

On a big-endian device (such as ubiquiti routers) you would enter \x08\x04\x84\x9d.
On a little-endian device (such as x86) you would enter \x9d\x84\x04\x08.
