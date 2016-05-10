## README

### expolit-2a, expolia-2b
expolit-2a, expolia-2b are easier, just pass url longer than the buffer, will pass the test.

###  expolit-3

* I exploit the reqpath in process_client.
* I install VMWARE in my mac, then install ssh server in linux, use my mac terminal to ssh connect the linux, then write code and debug. It is much easier to code in this way.
* When I try to get the return address, the instructions seems not correct, in gdb, the return address in 2048+20 bytes bigger than the  reqpath address, not 2048. below is my bash to debug.


```bash
//open one console to launch the webserve
./clean-env.sh ./zookld zook-exstack.conf

//another console to use gdb
gdb -p $(pgrep zookfs-exstack)
b process_client
continue

// third console to send http and debug now
./expolit-3y localhost 8080

//see the gdb agian, it break now
//here p is still some init value
p reqpath
//get reqpath address
p &reqpath  
//see current stack frame here
info frame
//the saved eip address is our return address,
//the ret address is 2068 bigger than reqpath address

n
n
n

//p becomes the url value here.
p reqpath
info frame
//we can see that the content of ret address now has been changed, comparing the last time.

//we can use x/s to check the value in some address 
x/s 0xbfffee08 

```

* this is very helpful.
https://crypto.stanford.edu/cs155old/cs155-spring07/pp1-demonstration.txt  


### expoit-4a.py
still use reqpath to do return libc 
* https://www.exploit-db.com/docs/28553.pdf is very helpful.

```bash
the dubug way is similar.
a few things need to pay attention:

//this command need to change to below one
gdb -p $(pgrep zookd)
b process_client
c
//get unlink address
p unlink
//get exit address
p exit
//use the way in expolit3 to get our string address, 
//can use return address+12 get it
//use x/s in gdb double check if the address is right


// launch server way is different
./clean-env.sh ./zookld zook-nxstack.conf

```

expolt.4b.py
```bash
use similar way to do,to launch gdb
gdb -p $(pgrep zookfs)
```

* I put the docs helps me a lot in more_info dir.
