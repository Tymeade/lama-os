void kmain(void) {
  const char *str = "Hello world!";
  char *vidptr = (char*)0xb8000;
  unsigned int i = 0;
  unsigned int j = 0;

  while (j < 80 * 25 * 2) {
    vidptr[j] = ' ';
    vidptr[j+1] = 0x07;
    j += 2;
  }

  j = 0;
  while (str[j] != '\0') {
    vidptr[i] = str[j];
    vidptr[i+1] = i % 7 + 1;
    j += 1;
    i += 2;
  }

  return;
}

