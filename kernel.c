/* Nov 30 Project08
** Debra Nash
** Load and Execute a file
**
*/
void readSector();
void readFile();

char abuffer[13312];

int main(){

makeInterrupt21();
interrupt(0x21, 3, "messag\0", abuffer, 0);
interrupt(0x21, 0, abuffer, 0, 0);

while(1);
}
int div(int a, int b){
  int q = 0;
  while ((q * b) < a){
    q = q + 1;
  }
  return q-1;
}
int mod(int dividend, int divisor){
  while (dividend >= divisor){
    dividend = dividend - divisor;
  }
}
void readSector(char* abuffer, int sector){
  int rs, h, t;
  int idx = 0;
  char mychar;
  
  rs = mod(sector,18)+ 1;
  h = div(sector,18);h = mod(h,2); 
  t = div(sector, 36); 
  interrupt(0x13, 2*256+1, abuffer, t*256+rs, h*256+0);
}
void readFile(char* abuffer){
char  *inFile;
int fileFound = 0;

      abuffer = inFile;   /* copy buffer to a local file */
      readSector(inFile); /* read the file from the floppy disk */
      while (inFile != 0x0){
      	interrupt(0x21, 3,  abuffer, inFile, 0);       /*read first 6 chars */
      	   /* if first 6 chars = inFile */
      		fileFound = 1;
      	
      		/* increment past the next 26 chars. */
       }
      	
}