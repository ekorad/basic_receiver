#include "processing.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
#include <mutex>
#include <fstream>
#include <iomanip>
#include <thread>
#include <condition_variable>

#define BUF_SIZE    8192
#define PORT        1337

using namespace std;

ofstream dbgout("dbg.txt");

static int client_sock_fd;
struct sockaddr_in sv_addr;

mutex queueMutex;
condition_variable queueCV;

bool recvDone = false;

// queue<string>& getEntriesQueue()
// {
//     static queue<string> entries;
//     return entries;
// }

queue<TransmOut>& getEntriesQueue()
{
    static queue<TransmOut> entries;
    return entries;
}

bool containsOnlyWhitespace(const std::string& str)
{
    for (char c : str)
    {
        if ((c != ' ') && (c != '\n') && (c != '\t'))
        {
            return false;
        }
    }
    return true;
}

int connectToServer(const string& ipAddr)
{
    if ((client_sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket");
        return -1;
    }

    sv_addr.sin_family = AF_INET;
    sv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, ipAddr.c_str(), &sv_addr.sin_addr) <= 0) 
    {
        perror("inet_pton");
        return -1;
    }

    if (connect(client_sock_fd, (struct sockaddr *)&sv_addr, sizeof(sv_addr)) < 0)
    {
        perror("connect");
        return -1;
    }

    dbgout << setprecision(17);

    return 0;
}
#include <fstream>
std::ofstream tmpOut{"num.txt"};
void receiveAndStore()
{
    // queue<string>& entries = getEntriesQueue();
    queue<TransmOut>& entries = getEntriesQueue();
    const string msgEndDelim = "<E>";
    string partialMsg;
    ssize_t bytesReceived = 0;
    char buffer[BUF_SIZE] = {0};

    cout << "> Receive started" << endl;

    double arrbuf[3];

    const int requiredTotalBytesReceived = 24;
    int totalBytesReceived = 0;

    while ((bytesReceived = recv(client_sock_fd, arrbuf,
        requiredTotalBytesReceived - totalBytesReceived, 0)) > 0)
    {
        // tmpOut << bytesReceived << "\n";
        totalBytesReceived += bytesReceived;
        if (totalBytesReceived == requiredTotalBytesReceived)
        {
            entries.push(TransmOut{ arrbuf[0], arrbuf[1], arrbuf[2] });
            totalBytesReceived = 0;
        }
        // queueCV.notify_one();
    }

    // while ((bytesReceived = recv(client_sock_fd, buffer, sizeof(buffer), 0)) > 0)
    // {
    //     buffer[bytesReceived] = '\0';
    //     string strBuf{buffer};
    //     decltype(strBuf.length()) foundIndex;

    //     partialMsg += strBuf;

    //     // queueMutex.lock();

    //     while ((foundIndex = partialMsg.find(msgEndDelim)) != string::npos)
    //     {
    //         entries.push(partialMsg.substr(0, foundIndex));
    //         partialMsg = partialMsg.substr(foundIndex + msgEndDelim.length());
    //     }

    //     queueCV.notify_one();

    //     // queueMutex.unlock();
    // }

    recvDone = true;

    // queueCV.notify_one();

    cout << "> Receive done" << endl;
}

TransmOut parseEntry(const string &entry)
{
    TransmOut transmOut;
    // stringstream ss(entry);
    // char comma;

    // ss >> transmOut.xc >> comma
    //     >> transmOut.zc >> comma
    //     >> transmOut.yr;

    sscanf(entry.c_str(), "%lf,%lf,%lf", &transmOut.xc, &transmOut.zc, &transmOut.yr);
    return transmOut;
}
