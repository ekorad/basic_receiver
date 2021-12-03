#ifndef PROCESSING_H
#define PROCESSING_H

#include <string>
#include <queue>
#include "data_struct.h"

bool containsOnlyWhitespace(const std::string& str);

int connectToServer(const std::string& ipAddr);

void receiveAndStore();

TransmOut parseEntry(const std::string &entry);

// std::queue<std::string>& getEntriesQueue();

std::queue<TransmOut>& getEntriesQueue();


#endif