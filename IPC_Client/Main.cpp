// This is a simple project to revise the concepts of IPC.
// This is the client project which needs to be ran after server starts.
#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
  HANDLE hPipeHandle;
  DWORD dWord;
  auto pipeName = TEXT("\\\\.\\pipe\\test_named_pipes");
  hPipeHandle = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                           OPEN_EXISTING, 0, NULL);
  if (hPipeHandle != INVALID_HANDLE_VALUE) {
    WriteFile(hPipeHandle, "Hello from Client \n", 20, &dWord, NULL);
    CloseHandle(hPipeHandle);
  }
  return 0;
}
