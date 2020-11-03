gcc ex2.c -o my_tee
cmod +x ex2
cat /proc/cpuinfo | ./my_tee ex2.txt