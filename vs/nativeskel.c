

#include <ntddk.h>

typedef struct {
    ULONG Unknown[21];
    UNICODE_STRING CommandLine;
    UNICODE_STRING ImageFile;
} ENVIRONMENT_INFORMATION, *PENVIRONMENT_INFORMATION;

typedef struct {
    ULONG Unknown[3];
    PENVIRONMENT_INFORMATION Environment;
} STARTUP_ARGUMENT, *PSTARTUP_ARGUMENT;

NTSTATUS NTAPI NtTerminateProcess(HANDLE ProcessHandle, LONG ExitStatus);
NTSTATUS NTAPI NtDisplayString(PUNICODE_STRING String);

void NtProcessStartup(PSTARTUP_ARGUMENT Argument)
{
    UNICODE_STRING usMessage;

    UNREFERENCED_PARAMETER(Argument);
    RtlInitUnicodeString(&usMessage, L"Hello, world.");
    NtDisplayString(&usMessage);
    NtTerminateProcess(NtCurrentProcess(), 0);
}