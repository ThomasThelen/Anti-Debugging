## Checking for a Debugger by Reading the Thread Information Block


### Background

Windows processes have an internal structure that defines various properties of its state. Its name is the Process Information Block (PEB); The structure below is from MSDN.

```
typedef struct _PEB {
  BYTE                          Reserved1[2];
  BYTE                          BeingDebugged;
  BYTE                          Reserved2[1];
  PVOID                         Reserved3[2];
  PPEB_LDR_DATA                 Ldr;
  PRTL_USER_PROCESS_PARAMETERS  ProcessParameters;
  PVOID                         Reserved4[3];
  PVOID                         AtlThunkSListPtr;
  PVOID                         Reserved5;
  ULONG                         Reserved6;
  PVOID                         Reserved7;
  ULONG                         Reserved8;
  ULONG                         AtlThunkSListPtr32;
  PVOID                         Reserved9[45];
  BYTE                          Reserved10[96];
  PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
  BYTE                          Reserved11[128];
  PVOID                         Reserved12[1];
  ULONG                         SessionId;
} PE
```

The second BYTE is a flag that is set to `1` when the process is being debugged. The Windows API call `IsDebuggerPresent` checks this flag however, it can be done manually (which is done here).

In order to check the flag, we need a way to get the PEB. One reliable way is to first realize that the FS register points to the Thread Information Block, which holds a pointer to
the PEB. The Thread Information Block is another structure that Windows uses to store information about a thread. 

From MSDN, the TEB looks like

```
typedef struct _TEB {
  PVOID Reserved1[12];
  PPEB  ProcessEnvironmentBlock;
  PVOID Reserved2[399];
  BYTE  Reserved3[1952];
  PVOID TlsSlots[64];
  BYTE  Reserved4[8];
  PVOID Reserved5[26];
  PVOID ReservedForOle;
  PVOID Reserved6[4];
  PVOID TlsExpansionSlots;
} TEB, *PTEB;
```

We can see that the PEB lies after the reserved section at the beginning.

Our program flow will look like

TEB->PEB->IsBeingDebugged

### Source Code

The source is fairly straight forward. We create a placeholder variable that will hold the value of `isBeingDebugged`. We then define
an assembly block.

Using assembly, we can access regions of the fs register with `fs:[offset]`. We know that we want offset 30h, so we move whatever's in fs:[30h] (a pointer to the PEB) to eax. Then, we
access the content at address `eax+2` of the PEB (eax register). We place it in our placeholder variable, and return.




#### Relevant Links
[MSDN TEB Page](https://docs.microsoft.com/en-us/windows/win32/api/winternl/ns-winternl-teb?redirectedfrom=MSDN)

[MSDN PEB Page](https://docs.microsoft.com/en-us/windows/win32/api/winternl/ns-winternl-peb)

