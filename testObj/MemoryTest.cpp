#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "windows.h"
#include <Psapi.h>
#pragma comment(lib,"psapi.lib")
using namespace std;
//solution https://stackoverflow.com/questions/1172734/how-to-create-a-process-in-c-to-execute-exe
//https://stackoverflow.com/questions/1984186/what-is-private-bytes-virtual-bytes-working-set
//https://docs.microsoft.com/zh-tw/windows/win32/psapi/collecting-memory-usage-information-for-a-process
void PrintMemoryInfo( HANDLE hProcess )
{
    PROCESS_MEMORY_COUNTERS pmc;

    // Print the process identifier.

    // Print information about the memory usage of the process.

    if (NULL == hProcess)
        return;

    if ( GetProcessMemoryInfo( hProcess, &pmc, sizeof(pmc)) )
    {
        printf( "\tPageFaultCount: %lld\n", pmc.PageFaultCount );
        printf( "\tPeakWorkingSetSize: %lld\n", 
                  pmc.PeakWorkingSetSize );
        printf( "\tWorkingSetSize: %lld\n", pmc.WorkingSetSize );
        printf( "\tQuotaPeakPagedPoolUsage: %lld\n", 
                  pmc.QuotaPeakPagedPoolUsage );
        printf( "\tQuotaPagedPoolUsage: %lld\n", 
                  pmc.QuotaPagedPoolUsage );
        printf( "\tQuotaPeakNonPagedPoolUsage: %lld\n", 
                  pmc.QuotaPeakNonPagedPoolUsage );
        printf( "\tQuotaNonPagedPoolUsage: %lld\n", 
                  pmc.QuotaNonPagedPoolUsage );
        printf( "\tPagefileUsage: %lld\n", pmc.PagefileUsage ); 
        printf( "\tPeakPagefileUsage: %lld\n", 
                  pmc.PeakPagefileUsage );
    }
}

void ExecuteAndWait(wstring toto){
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION  pi;
    vector<TCHAR> V( toto.length() + 1);
    for (int i=0;i< (int) toto.length();i++)
    V[i] = toto[i];
    CreateProcess(NULL, &V[0],0, 0, FALSE, 0, 0, 0, &si, &pi);
    
	
	//pi.hProcess is the process
	//PrintMemoryInfo(pi.hProcess);
    WaitForSingleObject(pi.hProcess, INFINITE);
    PrintMemoryInfo(pi.hProcess);
	
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}


int main(){
    //<SortType>Test.exe <data set Type>
    //c.g.  HeapSortTest.exe 1  -> HeapSort 100 dataset
    ExecuteAndWait(L"InsertionSortTest.exe 1 FULLDATA");
    ExecuteAndWait(L"MergeSortTest.exe 1 FULLDATA");
    ExecuteAndWait(L"QuickSortTest.exe 1 FULLDATA");
    ExecuteAndWait(L"HeapSortTest.exe 1 FULLDATA");
}