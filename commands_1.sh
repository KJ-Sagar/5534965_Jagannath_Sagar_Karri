#!/bin/bash

vi sum.c
gcc sum.c && ./a.out
vi filecmd
cat filecmd
cat sum.c
gcc sum.c
./a.out
gcc sum.c && ./a.out
ls
more filecmd
nano filecmd
more filecmd
less filecmd
head filecmd
head -n 5 filecmd
tail filecmd
tail +5 filecmd
nano sample.txt
cat sample.txt
cut -c 1-3 sample.txt
cut -c 4-10 sample.txt
cat sample.txt
cut -d ':' -f2 sample.txt
cut -d ':' -f2,3 sample.txt
ls
cat demo
nano f1
nano f2
cat fi
cat f1
cat f2
paste f1 f2
paste -d ':' f1 f2
paste -s f1 f2
cat sample.txt
sort sample.txt
sort sample.txt -r
sort -t ':' -k2 sample.txt
sort -t ':' -k3 sample.txt
sort -t ':' -k4 sample.txt
sort -t ':' -k3 sample.txt -r
cat sample.txt
tr ':' '|' < sample.txt
cat sample.txt
tr ':' '|' < sample.txt > s1.txt
ls
cat s1.txt
tr ':0' '|$' < sample.txt
cat sample.txt
tr -s '0' < sample.txt
cat sample.txt
tr -d '0' < sample.txt
nano example.txt
cat example.txt
uniq example.txt
nano example.txt
cat example.txt
uniq example.txt
ls
cat sample.txt
cat s1.txt
cmp sample.txt s1.txt
diff sample.txt s1.txt
ls
nano test.c
cat test.c
grep main test.c
grep ^main test.c
grep ^int test.c
grep \; test.c
nano test.c
cat test.c
grep ^int test.c
nano sed_test
cat sed_test
sed 's/Hello/Hi/' sed_test
cat sed_test
sed -i 's/Hello/Hi/' sed_test
cat sed_test
sed 's/!/$/g' sed_test
cat sed_test
sed '/simple/d' sed_test
sed '/Hi/a Welcome to sed' sed_test
sed -n '/Hi/p' sed_test
nano employees.txt
cat employees.txt
awk '{print $0}' employees.txt
awk '{print $1, $3}' employees.txt
awk '$3>50000 {print $1, $3}' employees.txt
awk 'BEGIN {print "Name:, Salary: "} {print $1, $3}' employees.txt
awk 'BEGIN {print "Name Salary"} {print $1, $3}' employees.txt
awk 'BEGIN {print "Name Age Salary"} {print $1, $2, $3}' employees.txt
awk '{total+= $3} END {print "Total Salary=", total}' employees.txt
awk '{print $0}' employees.txt
awk '{print NR, $1}' employees.txt
awk '{print NR, $0}' employees.txt
awk '/Alice/' employees.txt
awk '$2 < 30 {print $1, $2}' employees.txt
awk '{printf "Name: %s, Age: %d, Salary: %d\n", $1, $2, $3}' employees.txt
awk 'END {print "Total employees= ", NR}' employees.txt
ls -l
ls -l s1.txt
chmod u+x s1.txt
ls -l s1.txt
chmod o-r s1.txt
ls -l s1.txt
chmod 462 s1.txt
ls -l s1.txt
history
