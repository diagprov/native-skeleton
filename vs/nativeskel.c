

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
NTSYSAPI
NTSTATUS
NTAPI
NtDelayExecution(
	IN BOOLEAN              Alertable,
	IN PLARGE_INTEGER       DelayInterval);

void NtProcessStartup(PSTARTUP_ARGUMENT Argument)
{
    UNICODE_STRING usMessage;

    UNREFERENCED_PARAMETER(Argument);
    LARGE_INTEGER li = { 0 };
    li.LowPart = 100000000;

    RtlInitUnicodeString(&usMessage, L"Hello, world.");
    NtDisplayString(&usMessage);
    NtDelayExecution(TRUE, &li);
    NtTerminateProcess(NtCurrentProcess(), 0);
}