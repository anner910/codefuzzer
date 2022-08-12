#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <cstdio>

#include <assert.h>
#include <iostream>
#include <thread>


#ifdef __cplusplus
extern "C"{
#endif


void targer(int num, char* blob,int len, char* string)
{
	static int aaa = 0;
	static int aaa1 = 0;
	static int bbb = 0;
	static int bbb1 = 0;
	static int ccc = 0;
	static int ccc1 = 0;
	static int ddd = 0;
	
	if(num == 0x345679)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" num has ok\r\n");

			//int a = 0;
			//int b = a+5/a;
		}
	}

	if(num == 0x678886)
	{
		if (aaa1 == 0)
		{
			aaa1 = 1;
			printf(" num1 has ok\r\n");

			//for(;;)
				//;
		}
	}

	if(len >= 6)
		if(memcmp(blob,"123456",6) == 0)
		{
			if (bbb == 0)
			{
				bbb = 1;
				printf(" blob has ok\r\n");
			}

		}

	if(len >= 6)
		if(memcmp(blob,"jilin!",6) == 0)
		{
			if (bbb1 == 0)
			{
				bbb1 = 1;
				printf(" blob1 has ok\r\n");

				//char* temp = malloc(10);
				//temp = NULL;
			}

		}

	if(strcmp(string,"changchun") == 0)
	{
		if (ccc == 0)
		{
			ccc = 1;
			printf(" string has ok\r\n");
		}

	}

	if(strcmp(string,"shanghaiA") == 0)
	{
		if (ccc1 == 0)
		{
			ccc1 = 1;
			printf(" string1 has ok\r\n");
		}

	}


	if(len >= 6)
		if(blob[0] == 'l')
			if(blob[1] == 'v')
				if(blob[2] == ' ')
					if(blob[3] == 's')
						if(blob[4] == 'h')
							if(blob[5] == 'u')
								if (ddd == 0)
								{
									ddd = 1;
									printf(" lv shu has ok\r\n");

									//int a[10] = {0};
									//a[5] = a[10];
								}

	return;
}


int LLVMFuzzerTestOneInput1(const uint8_t *Data, size_t Size) {
  if (Size < 16) return 0;
  int64_t x;
  uint64_t y;
  memcpy(&x, Data, sizeof(x));
  memcpy(&y, Data + sizeof(x), sizeof(y));
  if (labs(x) < 0 && y == 0xbaddcafedeadbeefUL) {
    printf("BINGO; Found the target, exiting; x = 0x%lx y 0x%lx\n", x, y);
    exit(1);
  }
  return 0;
}

int LLVMFuzzerTestOneInput2(const uint8_t *Data, size_t Size) {
  if (Size < 8) return 0;
  int x;
  unsigned y;
  memcpy(&x, Data, sizeof(x));
  memcpy(&y, Data + sizeof(x), sizeof(y));
  if (abs(x) < 0 && y == 0xbaddcafe) {
    printf("BINGO; Found the target, exiting; x = 0x%x y 0x%x\n", x, y);
    exit(1);
  }
  return 0;
}

const int kAllocatedPointersSize = 10000;
int NumAllocatedPointers = 0;
int *AllocatedPointers[kAllocatedPointersSize];

int LLVMFuzzerTestOneInput3(const uint8_t *Data, size_t Size) {
  if (NumAllocatedPointers < kAllocatedPointersSize)
    AllocatedPointers[NumAllocatedPointers++] = new int;
  return 0;
}

static volatile bool SeedLargeBuffer;

int LLVMFuzzerTestOneInput4(const uint8_t *Data, size_t Size) {
  assert(Data);
  if (Size >= 4)
    SeedLargeBuffer = true;
  if (Size == 3 && SeedLargeBuffer && Data[3]) {
    std::cout << "Woops, reading Data[3] w/o crashing\n";
    exit(1);
  }
  return 0;
}



typedef void (*F)();
static F t[256];

void f34() {
  std::cerr << "BINGO\n";
  exit(1);
}
void f23() { t[(unsigned)'d'] = f34;}
void f12() { t[(unsigned)'c'] = f23;}
void f01() { t[(unsigned)'b'] = f12;}
void f00() {}

static F t0[256] = {
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
  f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00, f00,
};

extern "C" int LLVMFuzzerTestOneInput5(const uint8_t *Data, size_t Size) {
  if (Size < 4) return 0;
  // Spoof the counters.
  for (int i = 0; i < 200; i++) {
    f23();
    f12();
    f01();
  }
  memcpy(t, t0, sizeof(t));
  t[(unsigned)'a'] = f01;

  t[Data[0]]();
  t[Data[1]]();
  t[Data[2]]();
  t[Data[3]]();
  return 0;
}

int LLVMFuzzerTestOneInput6(const uint8_t *Data, size_t Size) {
  int Num = 0;
  for (size_t i = 0; i < Size; i++)
    if (Data[i] == 'A' + i)
      Num++;
  if (Num >= 4) {
    std::cerr <<  "BINGO!\n";
    exit(1);
  }
  return 0;
}

static volatile int Sink7;

int LLVMFuzzerTestOneInput7(const uint8_t *Data, size_t Size) {
  if (Size < 4) return 0;
  int a;
  memcpy(&a, Data, 4);

  Sink7 = 12345678 / (987654 - a);
  return 0;
}


int DSO1(int a) {
  if (a < 123456)
    return 0;
  return 1;
}

void Uncovered1() { }

int DSO2(int a) {
  if (a < 3598235)
    return 0;
  return 1;
}

void Uncovered2() {}


int DSOTestExtra(int a) {
  if (a < 452345)
    return 0;
  return 1;
}


extern int DSO1(int a);
extern int DSO2(int a);
extern int DSOTestExtra(int a);

static volatile int *nil = 0;

int LLVMFuzzerTestOneInput8(const uint8_t *Data, size_t Size) {
  int x, y, z;
  if (Size < sizeof(int) * 3) {
    x = y = z = 0;
  } else {
    memcpy(&x, Data + 0 * sizeof(int), sizeof(int));
    memcpy(&y, Data + 1 * sizeof(int), sizeof(int));
    memcpy(&z, Data + 2 * sizeof(int), sizeof(int));
  }
  int sum = DSO1(x) + DSO2(y) + (z ? DSOTestExtra(z) : 0);
  if (sum == 3) {
    fprintf(stderr, "BINGO %d %d %d\n", x, y, z);
    *nil = 0;
  }
  return 0;
}


int LLVMFuzzerTestOneInput9(const uint8_t *Data, size_t Size) {
  int bits = 0;
  if (Size > 0 && Data[0] == 'F') bits |= 1;
  if (Size > 1 && Data[1] == 'U') bits |= 2;
  if (Size > 2 && Data[2] == 'Z') bits |= 4;
  if (Size > 3 && Data[3] == 'Z') bits |= 8;
  if (bits == 15) {
    std::cerr <<  "BINGO!\n";
    exit(1);
  }
  return 0;
}


int LLVMFuzzerTestOneInput10(const uint8_t *Data, size_t Size) {
  int bits = 0;
  if (Size > 0 && Data[0] == 'F') bits |= 1;
  if (Size > 1 && Data[1] == 'U') bits |= 2;
  if (Size > 2 && Data[2] == 'Z') bits |= 4;
  if (Size > 3 && Data[3] == 'Z') bits |= 8;
  if (Size > 4 && Data[4] == 'E') bits |= 16;
  if (Size > 5 && Data[5] == 'R') bits |= 32;
  if (bits == 63) {
    std::cerr <<  "BINGO!\n";
    exit(1);
  }
  return 0;
}


static volatile void *Sink11;

int LLVMFuzzerTestOneInput11(const uint8_t *Data, size_t Size) {
  if (Size > 0 && *Data == 'H') {
    Sink11 = new int;
    Sink11 = nullptr;
  }
  return 0;
}


static volatile int *Sink12;

extern "C" int LLVMFuzzerTestOneInput12(const uint8_t *Data, size_t Size) {
  if (!Size) return 0;
  Sink12 = new int;
  Sink12 = new int;
  while (Sink12) *Sink12 = 0;  // Infinite loop.
  return 0;
}


static volatile int Sink13;
const int kArraySize = 1234567;
int array[kArraySize];

int LLVMFuzzerTestOneInput13(const uint8_t *Data, size_t Size) {
  if (Size < 8) return 0;
  size_t a = 0;
  memcpy(&a, Data, 8);
  Sink13 = array[a % (kArraySize + 1)];
  return 0;
}

int LLVMFuzzerTestOneInput14(const uint8_t *Data, size_t Size) {
  // TODO: check other sizes.
  if (Size >= 8 && memcmp(Data, "01234567", 8) == 0) {
    if (Size >= 12 && memcmp(Data + 8, "ABCD", 4) == 0) {
      if (Size >= 14 && memcmp(Data + 12, "XY", 2) == 0) {
        if (Size >= 17 && memcmp(Data + 14, "KLM", 3) == 0) {
          if (Size >= 27 && memcmp(Data + 17, "ABCDE-GHIJ", 10) == 0){
            fprintf(stderr, "BINGO %zd\n", Size);
            for (size_t i = 0; i < Size; i++) {
              uint8_t C = Data[i];
              if (C >= 32 && C < 127)
                fprintf(stderr, "%c", C);
            }
            fprintf(stderr, "\n");
            exit(1);
          }
        }
      }
    }
  }
  return 0;
}

static int Counter15;

int LLVMFuzzerTestOneInput15(const uint8_t *Data, size_t Size) {
  if (Counter15++ == 1000) {
    std::cout << "BINGO; Found the target, exiting\n";
    exit(1);
  }
  return 0;
}


static volatile int *Null16 = 0;

int LLVMFuzzerTestOneInput16(const uint8_t *Data, size_t Size) {
  if (Size == 0) {
    std::cout << "Found the target, dereferencing NULL\n";
    *Null16 = 1;
  }
  return 0;
}

static volatile int Sink17;
static volatile int *Null17 = 0;

int LLVMFuzzerTestOneInput17(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    Sink17 = 1;
    if (Size > 1 && Data[1] == 'i') {
      Sink17 = 2;
      if (Size > 2 && Data[2] == '!') {
        std::cout << "Found the target, dereferencing NULL\n";
        *Null17 = 1;
      }
    }
  }
  return 0;
}

static volatile char *SinkPtr18;

int LLVMFuzzerTestOneInput18(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    if (Size > 1 && Data[1] == 'i') {
      if (Size > 2 && Data[2] == '!') {
        size_t kSize = (size_t)1 << 31;
        char *p = new char[kSize];
        memset(p, 0, kSize);
        SinkPtr18 = p;
        delete [] p;
      }
    }
  }
  return 0;
}

static volatile char *SinkPtr19;

int LLVMFuzzerTestOneInput19(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    if (Size > 1 && Data[1] == 'i') {
      if (Size > 2 && Data[2] == '!') {
          size_t kSize = 0xff000000U;
          char *p = new char[kSize];
          SinkPtr19 = p;
          delete [] p;
      }
    }
  }
  return 0;
}

static volatile char *SinkPtr20;

int LLVMFuzzerTestOneInput20(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    if (Size > 1 && Data[1] == 'i') {
      if (Size > 2 && Data[2] == '!') {
        while (true) {
          size_t kSize = 1 << 28;
          char *p = new char[kSize];
          memset(p, 0, kSize);
          SinkPtr20 = p;
          std::this_thread::sleep_for(std::chrono::seconds(1));
        }
      }
    }
  }
  return 0;
}

int LLVMFuzzerTestOneInput21(const uint8_t *Data, size_t Size) {
  assert(Data);
  // Looking for AAAAAAAAAAAAAAAAAAAAAA or some such.
  size_t CurA = 0, MaxA = 0;
  for (size_t i = 0; i < Size; i++) {
    // Make sure there are no conditionals in the loop so that
    // coverage can't help the fuzzer.
    int EQ = Data[i] == 'A';
    CurA = EQ * (CurA + 1);
    int GT = CurA > MaxA;
    MaxA = GT * CurA + (!GT) * MaxA;
  }
  if (MaxA >= 20) {
    std::cout << "BINGO; Found the target (Max: " << MaxA << "), exiting\n";
    exit(0);
  }
  return 0;
}

int LLVMFuzzerTestOneInput22(const uint8_t *Data, size_t Size) {
  int Matches = 0;
  for (size_t i = 0; i + 2 < Size; i += 3) {
    const char *Pat = i % 2 ? "foo" : "bar";
    if (!memcmp(Data + i, Pat, 3))
      Matches++;
  }
  if (Matches > 20) {
    fprintf(stderr, "BINGO!\n");
    exit(1);
  }
  return 0;
}

static volatile int Sink23;

int LLVMFuzzerTestOneInput23(const uint8_t *Data, size_t Size) {
  int8_t Ids[256];
  memset(Ids, -1, sizeof(Ids));
  for (size_t i = 0; i < Size; i++)
    if (Ids[Data[i]] == -1)
      Ids[Data[i]] = i;
  int F = Ids[(unsigned char)'F'];
  int U = Ids[(unsigned char)'U'];
  int Z = Ids[(unsigned char)'Z'];
  if (F >= 0 && U > F && Z > U) {
    Sink23++;
    //fprintf(stderr, "IDS: %d %d %d\n", F, U, Z);
  }
  return 0;
}

static volatile uint32_t Sink24;

int LLVMFuzzerTestOneInput24(const uint8_t *Data, size_t Size) {
  if (Size < sizeof(uint32_t)) return 0;
  uint32_t X, Y;
  size_t Offset = Size < 8 ? 0 : Size / 2;
  memcpy(&X, Data + Offset, sizeof(uint32_t));
  memcpy(&Y, "FUZZ", sizeof(uint32_t));
  Sink24 = X == Y;
  return 0;
}

static volatile int Sink25;
static int Large25 = 2147483647;

extern "C" int LLVMFuzzerTestOneInput25(const uint8_t *Data, size_t Size) {
  assert(Data);
  if (Size > 0 && Data[0] == 'H') {
    Sink25 = 1;
    if (Size > 1 && Data[1] == 'i') {
      Sink25 = 2;
      if (Size > 2 && Data[2] == '!') {
        Large25++;  // int overflow.
      }
    }
  }
  return 0;
}

extern int AllLines26[];

bool PrintOnce(int Line) {
  if (!AllLines26[Line])
    fprintf(stderr, "Seen line %d\n", Line);
  AllLines26[Line] = 1;
  return true;
}

int LLVMFuzzerTestOneInput26(const uint8_t *Data, size_t Size) {
  if (Size != 22) return 0;
  uint64_t x = 0;
  int64_t  y = 0;
  int32_t z = 0;
  uint16_t a = 0;
  memcpy(&x, Data, 8);  // 8
  memcpy(&y, Data + 8, 8);  // 16
  memcpy(&z, Data + 16, sizeof(z));  // 20
  memcpy(&a, Data + 20, sizeof(a));  // 22

  if (x > 1234567890 && PrintOnce(__LINE__) &&
      x < 1234567895 && PrintOnce(__LINE__) &&
      a == 0x4242 && PrintOnce(__LINE__) &&
      y >= 987654321 && PrintOnce(__LINE__) &&
      y <= 987654325 && PrintOnce(__LINE__) &&
      z < -10000 && PrintOnce(__LINE__) &&
      z >= -10005 && PrintOnce(__LINE__) &&
      z != -10003 && PrintOnce(__LINE__) &&
      true) {
    fprintf(stderr, "BINGO; Found the target: size %zd (%zd, %zd, %d, %d), exiting.\n",
            Size, x, y, z, a);
    exit(1);
  }
  return 0;
}

int AllLines26[__LINE__ + 1];  // Must be the last line.

static volatile int Zero27 = 0;

int LLVMFuzzerTestOneInput27(const uint8_t *Data, size_t Size) {
  const char *Expected = "ElvisPresley";
  if (Size < strlen(Expected)) return 0;
  size_t Match = 0;
  for (size_t i = 0; Expected[i]; i++)
    if (Expected[i] + Zero27 == Data[i])
      Match++;
  if (Match == strlen(Expected)) {
    std::cout << "BINGO; Found the target, exiting\n";
    exit(1);
  }
  return 0;
}


// A modified jenkins_one_at_a_time_hash initialized by non-zero,
// so that simple_hash(0) != 0. See also
// https://en.wikipedia.org/wiki/Jenkins_hash_function
static uint32_t simple_hash28(const uint8_t *Data, size_t Size) {
  uint32_t Hash = 0x12039854;
  for (uint32_t i = 0; i < Size; i++) {
    Hash += Data[i];
    Hash += (Hash << 10);
    Hash ^= (Hash >> 6);
  }
  Hash += (Hash << 3);
  Hash ^= (Hash >> 11);
  Hash += (Hash << 15);
  return Hash;
}

int LLVMFuzzerTestOneInput28(const uint8_t *Data, size_t Size) {
  if (Size < 14)
    return 0;

  uint32_t Hash = simple_hash28(&Data[0], Size - 4);
  uint32_t Want = reinterpret_cast<const uint32_t *>(&Data[Size - 4])[0];
  if (Hash != Want)
    return 0;
  fprintf(stderr, "BINGO; simple_hash defeated: %x == %x\n", (unsigned int)Hash,
          (unsigned int)Want);
  exit(1);
  return 0;
}


static volatile int Sink29;

int LLVMFuzzerTestOneInput29(const uint8_t *Data, size_t Size) {
  assert(Data);
  if (Size > 0 && Data[0] == 'H') {
    Sink29 = 1;
    if (Size > 1 && Data[1] == 'i') {
      Sink29= 2;
      if (Size > 2 && Data[2] == '!') {
        std::cout << "BINGO; Found the target, exiting\n";
        exit(0);
      }
    }
  }
  return 0;
}


int LLVMFuzzerTestOneInput30(const uint8_t *Data, size_t Size) {
  auto C = [&] {
    if (Size >= 2 && Data[0] == 'H') {
        std::cout << "BINGO; Found the target, exiting\n";
        abort();
    }
  };
  std::thread T[] = {std::thread(C), std::thread(C), std::thread(C),
                     std::thread(C), std::thread(C), std::thread(C)};
  for (auto &X : T)
    X.join();
  return 0;
}

int LLVMFuzzerTestOneInput31(const uint8_t *Data, size_t Size) {
  char *S = (char*)Data;
  if (Size >= 6 && !memcmp(S, "qwerty", 6)) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}


int LLVMFuzzerTestOneInput32(const uint8_t *Data, size_t Size) {
  char *S = (char*)Data;
  if (Size >= 7 && !strcmp(S, "qwerty")) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}

int LLVMFuzzerTestOneInput33(const uint8_t *Data, size_t Size) {
  char *S = (char*)Data;
  if (Size >= 6 && !strncmp(S, "qwerty", 6)) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}

int LLVMFuzzerTestOneInput34(const uint8_t *Data, size_t Size) {
  assert(Data);
  printf("PRINTF_STDOUT\n");
  fflush(stdout);
  fprintf(stderr, "PRINTF_STDERR\n");
  std::cout << "STREAM_COUT\n";
  std::cout.flush();
  std::cerr << "STREAM_CERR\n";
  return 0;
}



bool Eq35(const uint8_t *Data, size_t Size, const char *Str) {
  char Buff[1024];
  size_t Len = strlen(Str);
  if (Size < Len) return false;
  if (Len >= sizeof(Buff)) return false;
  memcpy(Buff, (char*)Data, Len);
  Buff[Len] = 0;
  int res = strcmp(Buff, Str);
  return res == 0;
}

int LLVMFuzzerTestOneInput35(const uint8_t *Data, size_t Size) {
  if (Eq35(Data, Size, "ABC") &&
      Size >= 3 && Eq35(Data + 3, Size - 3, "QWER") &&
      Size >= 7 && Eq35(Data + 7, Size - 7, "ZXCVN") &&
      Size >= 14 && Data[13] == 42
    ) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}

static volatile int Sink36;

int LLVMFuzzerTestOneInput36(const uint8_t *Data, size_t Size) {
  if (Size < 5) return 0;
  const char *Ch = reinterpret_cast<const char *>(Data);
  if (Ch[Size - 3] == 'a')
    Sink36 = strncmp(Ch + Size - 3, "abcdefg", 6);
  return 0;
}

static volatile int sink37;

extern "C" int LLVMFuzzerTestOneInput37(const uint8_t *Data, size_t Size) {
  // TODO: check other sizes.
  char *S = (char*)Data;
  if (Size >= 8 && strncmp(S, "123", 8))
    sink37 = 1;
  if (Size >= 8 && strncmp(S, "01234567", 8) == 0) {
    if (Size >= 12 && strncmp(S + 8, "ABCD", 4) == 0) {
      if (Size >= 14 && strncmp(S + 12, "XY", 2) == 0) {
        if (Size >= 17 && strncmp(S + 14, "KLM", 3) == 0) {
          fprintf(stderr, "BINGO\n");
          exit(1);
        }
      }
    }
  }
  return 0;
}


// Windows does not have strcasestr and memmem, so we are not testing them.
#ifdef _WIN32
#define strcasestr strstr
#define memmem(a, b, c, d) true
#endif

int LLVMFuzzerTestOneInput38(const uint8_t *Data, size_t Size) {
  if (Size < 4) return 0;
  std::string s(reinterpret_cast<const char*>(Data), Size);
  if (strstr(s.c_str(), "FUZZ") &&
      strcasestr(s.c_str(), "aBcD") &&
      memmem(s.data(), s.size(), "kuku", 4)
      ) {
    fprintf(stderr, "BINGO\n");
    exit(1);
  }
  return 0;
}

int LLVMFuzzerTestOneInput39(const uint8_t *Data, size_t Size) {
  if (Size < 14) return 0;
  uint64_t x = 0;
  uint32_t y = 0;
  uint16_t z = 0;
  memcpy(&x, Data, sizeof(x));
  memcpy(&y, Data + Size / 2, sizeof(y));
  memcpy(&z, Data + Size - sizeof(z), sizeof(z));

  x = __builtin_bswap64(x);
  y = __builtin_bswap32(y);
  z = __builtin_bswap16(z);

  if (x == 0x46555A5A5A5A5546ULL &&
      z == 0x4F4B &&
      y == 0x66757A7A &&
      true
      ) {
    if (Data[Size - 3] == 'z') {
      fprintf(stderr, "BINGO; Found the target\n");
      exit(1);
    }
  }
  return 0;
}


int Switch40(int a) {
  switch(a) {
    case 100001: return 1;
    case 100002: return 2;
    case 100003: return 4;
  }
  return 0;
}

int LLVMFuzzerTestOneInput40(const uint8_t *Data, size_t Size) {
  const int N = 3;
  if (Size < N * sizeof(int)) return 0;
  int Res = 0;
  for (int i = 0; i < N; i++) {
    int X;
    memcpy(&X, Data + i * sizeof(int), sizeof(int));
    Res += Switch40(X);
  }
  if (Res == 5 || Res == 3 || Res == 6 || Res == 7) {
    fprintf(stderr, "BINGO; Found the target, exiting; Res=%d\n", Res);
    exit(1);
  }
  return 0;
}


static volatile int Sink41;
bool Switch41(const uint8_t *Data, size_t Size) {
  int X;
  if (Size < sizeof(X)) return false;
  memcpy(&X, Data, sizeof(X));
  switch (X) {
    case 1: Sink41 = __LINE__; break;
    case 101: Sink41 = __LINE__; break;
    case 1001: Sink41 = __LINE__; break;
    case 10001: Sink41 = __LINE__; break;
    case 100001: Sink41 = __LINE__; break;
    case 1000001: Sink41 = __LINE__; break;
    case 10000001: Sink41 = __LINE__; break;
    case 100000001: 
		return true;
  }
  return false;
}

bool Switch411(const uint8_t *Data, size_t Size) {
  uint64_t X;
  if (Size < sizeof(X)) return false;
  memcpy(&X, Data, sizeof(X));
  switch (X) {
    case 1: Sink41 = __LINE__; break;
    case 101: Sink41 = __LINE__; break;
    case 1001: Sink41 = __LINE__; break;
    case 10001: Sink41 = __LINE__; break;
    case 100001: Sink41 = __LINE__; break;
    case 1000001: Sink41 = __LINE__; break;
    case 10000001: Sink41 = __LINE__; break;
    case 100000001: return true;
  }
  return false;
}


bool ShortSwitch41(const uint8_t *Data, size_t Size) {
  short X;
  if (Size < sizeof(short)) return false;
  memcpy(&X, Data, sizeof(short));
  switch(X) {
    case 42: Sink41 = __LINE__; break;
    case 402: Sink41 = __LINE__; break;
    case 4002: Sink41 = __LINE__; break;
    case 5002: Sink41 = __LINE__; break;
    case 7002: Sink41 = __LINE__; break;
    case 9002: Sink41 = __LINE__; break;
    case 14002: Sink41 = __LINE__; break;
    case 21402: return true;
  }
  return false;
}

int LLVMFuzzerTestOneInput41(const uint8_t *Data, size_t Size) {
  if (Size >= 4  && Switch41(Data, Size) &&
      Size >= 12 && Switch411(Data + 4, Size - 4) &&
      Size >= 14 && ShortSwitch41(Data + 12, 2)
    ) {
    fprintf(stderr, "BINGO; Found the target, exiting\n");
    exit(1);
  }
  return 0;
}

static volatile int *Sink42;

int LLVMFuzzerTestOneInput42(const uint8_t *Data, size_t Size) {
  if (Size == 0) return 0;
  if (Data[0] != 'F') return 0;
  std::thread T([&] { Sink42 = new int; });
  T.join();
  return 0;
}

int LLVMFuzzerTestOneInput43(const uint8_t *Data, size_t Size) {
  if (Size < 8) return 0;
  assert(Data);
  auto C = [&] {
    size_t Res = 0;
    for (size_t i = 0; i < Size / 2; i++)
      Res += memcmp(Data, Data + Size / 2, 4);
    return Res;
  };
  std::thread T[] = {std::thread(C), std::thread(C), std::thread(C),
                     std::thread(C), std::thread(C), std::thread(C)};
  for (auto &X : T)
    X.join();
  return 0;
}


int LLVMFuzzerTestOneInput44(const uint8_t *Data, size_t Size) {
  static volatile int Zero = 0;
  if (!Size)
    while(!Zero)
      ;
  return 0;
}


static volatile int Sink45;

extern "C" int LLVMFuzzerTestOneInput45(const uint8_t *Data, size_t Size) {
  if (Size > 0 && Data[0] == 'H') {
    Sink45 = 1;
    if (Size > 1 && Data[1] == 'i') {
      Sink45 = 2;
      if (Size > 2 && Data[2] == '!') {
        Sink45 = 2;
        while (Sink45)
          ;
      }
    }
  }
  return 0;
}


int *Ptr46;

extern "C" int LLVMFuzzerTestOneInput46(const uint8_t *Data, size_t Size) {
  if (!Size) return 0;
  if (*Data == 1) {
    delete Ptr46;
    Ptr46 = nullptr;
  } else if (*Data == 2) {
    delete Ptr46;
    Ptr46 = new int;
  } else if (*Data == 3) {
    if (!Ptr46)
      Ptr46 = new int;
  }
  return 0;
}

extern "C" int LLVMFuzzerTestOneInput47(const uint8_t *Data, size_t Size) {
  if (Size < 12) return 0;

  int aaa = *(int*)Data;
  int bbb = 0x34e5688;
  int ccc = 0x8ff9900;
  if ((aaa - ccc) == bbb)
  {
    fprintf(stderr, "BINGO; Found the target, exiting\n");
    exit(1);
  }
  
  return 0;
}


#ifdef __cplusplus
}
#endif

