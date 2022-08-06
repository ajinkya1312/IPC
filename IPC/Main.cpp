// This is a simple project to revise the concepts of IPC.
// This is the server project which needs to be ran before client can connect.
#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
  HANDLE hPipeHandle;
  auto pipeName = TEXT("\\\\.\\pipe\\test_named_pipes");
  hPipeHandle =
      CreateNamedPipe(pipeName, PIPE_ACCESS_DUPLEX,
          PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, 1,
          1024 * 16, 1024 * 16, NMPWAIT_USE_DEFAULT_WAIT, NULL);

  char buffer[1024];
  DWORD dWord;
  while (hPipeHandle != INVALID_HANDLE_VALUE)
  {
      cout << "The pipe creation is successful!" << endl;
      if (ConnectNamedPipe(hPipeHandle, NULL) != FALSE)
      {
          cout << "Client has connected to this pipe!" << endl;
          while (ReadFile(hPipeHandle, buffer, sizeof(buffer) - 1, &dWord, NULL) != FALSE)
          {
              buffer[dWord] = '\0';
              cout << (buffer);
          }
      }
      DisconnectNamedPipe(hPipeHandle);
  }
  return 0;
}
